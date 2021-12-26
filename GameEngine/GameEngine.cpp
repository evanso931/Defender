#include "GameEngine.h"

/** Define accelerometer object */
FXOS8700CQ accelerometer(I2C_SDA,I2C_SCL);

/** Define SD card object */
SDFileSystem sd(PTE3, PTE1, PTE2, PTE4, "sd");
    
GameEngine::GameEngine() {
    //attach ticker to isr 
    ticker.attach(callback(this, &GameEngine::lcd_frame_time_isr), 0.04 );
}
 
GameEngine::~GameEngine() {
    
}

void GameEngine::init() {
    // Initialise objects
    pad.init();
    lcd.init();
    spaceship.init();
    map.init(pad);
    menu.init();
    accelerometer.init();
    saved.init();
    setting.init();
    h_score.init();

    // Set first screen to main menu
    current_menu_part_= menu.get_current_menu_part();
    
    // Launch screen
    lcd.printString("Evans Studios",3,2); 
    lcd.printString("Presents:",15,3);
    lcd.refresh();
    wait(3); 
    
    play_music();
    
    // Set seed value 
    srand(pad.read_adc()*64000);
    
    // Had to include save test here as getting the error sd couldn’t be created
    #ifdef SD_TEST
        saved.run_save_test(sd,lcd); 
        h_score.run_save_test(sd,lcd);      
    #endif 
}

void GameEngine::lcd_frame_time_isr() {
    // Set ISR flag
    lcd_frame_time_flag_ = 1; 
} 

// Menu Control-----------------------------------------------------------------

void GameEngine::game_select_part() {
    switch (current_menu_part_) {
    case main_menu: run_menu(); break;
    case play: run_play(); break;
    case settings: run_settings(); break;
    case saved_games: run_saved_games(); break;
    case high_score: run_highscore(); break;
    }
}

void GameEngine::run_menu() {
    lcd.setContrast(pad.read_pot1());          
    lcd.clear();
    pad.reset_buttons();
            
    // Scrolls, draws and selects menu parts
    read_joystick_direction();
    menu.menu_scroll(d_);
    menu.draw_part(lcd);  
    menu.select_part(pad.A_pressed());
             
    current_menu_part_ = menu.get_current_menu_part();
    
    // Sets sound and music setting 
    sound_fx_ = setting.get_sound_method();
    music_fx_ = setting.get_music_method();
    if (music_fx_ == music_off){
        stop_music();
    }   
    music_flag_ = true;
    
    // printf("sound%d\n",sound_fx_ );
         
    // Initialise the game if play 
    if (current_menu_part_ == play) {
        play_init();
    }
    
    pad.reset_buttons();    
    lcd.refresh();      
}

void GameEngine::loading_screen(){
    lcd.clear();
    
    // Draws adding dots 3 times
    for (int x = 0; x <= 2; x++) {
        lcd.printString("Loading",15,3);
        lcd.refresh();
        
        // Adds loading dots 
        for (int i = 0; i <= 3; i++) { 
            wait(0.25);
            lcd.printString(".",57+(i*6),3);
            lcd.refresh();  
        }
        lcd.clear();
    }
}



// Menu Play -------------------------------------------------------------------

void GameEngine::run_play() {
    loading_screen(); 
    
    // Stops melody playing
    stop_music();
    
    // Main gameplay loop to run playable part of game, pause and save screens
    while (1) {             
        // Timer interrupt to set frame rate of game
        if (lcd_frame_time_flag_) {
            // Resets ISR flag 
            lcd_frame_time_flag_ = 0; 
            
            // Selects the different parts of the game
            play_select();
            
            // Break out of run play loop when lives = 0 or exited flag set
            if (!spaceship_lives_||exit_flag_) {
                // Only draw game over screen if run out of lives
                if (!spaceship_lives_) {
                    draw_game_over_screen();
                }
                reset_map();
                pad.leds_off();
                break;   
            } 
        }
        
    // MCU put to sleep between each frame to save power 
    sleep();       
    } 
    play_music();
    wait(0.3);
}

void GameEngine::play_select(){
    // Pause button pressed
    if (pad.start_pressed() && paused_counter_ > 10 ) {
        paused_button_pressed_ =  !paused_button_pressed_; 
        paused_counter_ = 0 ;
        run_save_a_game_flag_ = false;
    }
    
    // Stopped double press of pause button
    paused_counter_++;
    
    // Draws pause screen if paused button pressed
    if (paused_button_pressed_) {
        run_paused_game();
               
    // Otherwise draw gameplay screen
    }else{
        gameplay_loop(); 
    }
    
       
}

void GameEngine::play_music() {
    if (music_fx_ == music_on) {
        pad.play_melody(88, star_wars, star_wars_note_time, 108, true);
    }
    
}

void GameEngine::stop_music() {
    pad.play_melody(1, melody_off, melody_off_note_time, 1, false);
}

void GameEngine::play_init() {
    // Define variables
    spawn_time_multipler_ = 1;
    alien_number_ = 5;
    spawn_alien_counter_ = 0;
    spaceship_lives_ = 3;
    reset_map_counter_ = 0;
    smart_bomb_counter_ = 4;
    create_people();
    points_ = 0;
    smart_bomb_timer_ =  0;
    bullet_timer_ = 0;
    lcd_frame_time_flag_ = 0;
    paused_counter_ = 25;
    
    // Flags for screen control
    exit_flag_ = false;
    run_save_a_game_flag_ = false;
    spaceship_destroyed_ = false;
    saved.set_error(false);
    paused_button_pressed_ = false;
}

void GameEngine::gameplay_loop() {
    // Clear screen and set contrast
    lcd.setContrast(pad.read_pot1());          
    lcd.clear();
    
    // Creates aliens and people
    spawn_aliens();
    spawn_people();

    // If spaceship is destroyed stop joystick input, don’t draw spaceship sprite
    spaceship_not_detroyed();
    
    // Draws objects
    map.draw_map(lcd, d_);
    draw_aliens();
    draw_bullets();
    draw_explosions();
    draw_people(); 
    hud.draw_HUD(lcd, spaceship_lives_, points_, smart_bomb_counter_);
    spaceship_lives_leds();
    
    reset_map_timer();
    
    // Refresh's screen
    lcd.refresh(); 
}

void GameEngine::spaceship_not_detroyed() {
    if (!spaceship_destroyed_) {
        
        // Changes the control method depending what’s selected in the setting
        if (setting.get_control_method() == joy ) {
        read_joystick_direction();
        }else {
        read_accelerometer_direction(accelerometer.get_roll_angle(),
        accelerometer.get_pitch_angle());
        }
        
        // Stops movement of spaceship and map after destroyed
        spaceship.movement(d_);
        spaceship.draw(lcd);
        create_weapons_bullets();
        create_weapons_smart_bomb();
    }
}

void GameEngine::draw_game_over_screen() {
    // Draws game over screen then back to menu
    lcd.clear();
    lcd.printString("Game Over",15,0);
    
    // Draws score/highscore part of screen
    char buffer[11]; 
    sprintf(buffer,"Score = %d",points_);
    lcd.printString(buffer,12,2);
    h_score.set_error(false);
    
    // Prints new high score if a high score and no error
    if (calculate_new_score()&& !h_score.get_error()) {
        lcd.printString("NEW HIGH SCORE",0,4); 
        
        if (music_fx_ == music_on) {
        pad.play_melody(61, take_on_me, take_on_me_note_time, 140, false);
        }
        
    }else if (music_fx_ == music_on) {
        pad.play_melody(23, god_farther, god_farther_note_time, 80, false);
    }
    
    lcd.refresh();
    wait(6);
    current_menu_part_ = main_menu;
}

void GameEngine::run_paused_game() {
    // Lunch save a game screen 
    if (pad.B_pressed()||run_save_a_game_flag_) {
        run_save_a_game_flag_ = true;
        run_save_a_game();
        
    // Draw pause screen
    }else{
        draw_pause_screen();
    }
    
    // Exit to main menu
    if (pad.A_pressed()||saved.get_error()) {
        current_menu_part_ = main_menu;
        play_music();
        exit_flag_ = true;
        saved.set_error(false);
        wait(0.037);
    }
}

void GameEngine::draw_pause_screen() {
    // Clear screen and set contrast
    lcd.setContrast(pad.read_pot1());          
    lcd.clear();
    
    // Draw strings
    lcd.printString("Paused!",24,0);
    lcd.printString("Exit(A)",24,3);
    lcd.printString("Save&Exit(B)",6,4);
    
    // Refresh's screen
    lcd.refresh(); 
}

void GameEngine::run_save_a_game() {
    // Draw and interact with save a game screen
    read_joystick_direction();
    saved.saved_games_scroll(d_);
    saved.save_game_screen(lcd);
    
    // Save game to save file that is displayed
    if (pad.A_pressed()) {  
        // Define struct data
        SavedGamesData data;
        
        // Set values in struct data and saves them selected file
        data.score = points_;
        data.lives = spaceship_lives_;
        data.smart_bombs = smart_bomb_counter_;
        data.alien_number = alien_number_;
        saved.add_saved_data(sd, data, lcd);
        
        // If error go back to pause screen
        if (saved.get_error()) {
            run_save_a_game_flag_ = false;
            saved.set_error(false);
        }else{
        // Exit to main menu
        current_menu_part_ = main_menu;
        exit_flag_ = true; 
        }
    } 
}




// Menu Setting ----------------------------------------------------------------

void GameEngine::run_settings() {      
    lcd.clear();
    lcd.setContrast(pad.read_pot1());
            
    // Scrolls, draws and changes different parts
    read_joystick_direction();
    setting.settings_scroll(d_);
    setting.display_settings_screen(lcd, pad.read_pot1());  
    setting.change_setting(pad.A_pressed());
    
    // Stops music immediately changed
    music_fx_ = setting.get_music_method();
    if (music_fx_ == music_off){
        stop_music();
        music_flag_ = false;
    }   
    if (music_fx_ == music_on && !music_flag_ ){
        play_music();
        music_flag_ = true;
    }        
    // Go back to main menu if b
    if (pad.B_pressed()) { 
        current_menu_part_ = main_menu;
    }
            
    lcd.refresh();     
}



// Menu Saved Games ------------------------------------------------------------

void GameEngine::run_saved_games() {
    // Draws and interact with save screen
    read_joystick_direction(); 
    saved.saved_games_scroll(d_);
    saved.display_saved_games(lcd);
    
    // Go back to main menu
    if (pad.B_pressed()) { 
        current_menu_part_ = main_menu;
    }
    
    // Press  A to load save, if no file press go back to main menu
    if (pad.A_pressed()) {
        wait(0.035);  
        saved_games_overide_init();
        if (saved.get_error()) {
            saved.set_error(false);
            current_menu_part_ = main_menu;
        }else{   
            current_menu_part_ = play; 
        }
    }   
}

void GameEngine::saved_games_overide_init() {
    play_init();
    
    // Creates data object add sett it values to data saved in the file
    SavedGamesData displayed_game;
    displayed_game = saved.read_saved_data(sd, lcd);
    
    // Set the variables to value in the displayed saved struct
    points_ = displayed_game.score;
    spaceship_lives_ = displayed_game.lives;
    smart_bomb_counter_= displayed_game.smart_bombs;
    alien_number_ = displayed_game.alien_number;
}



// Menu High score -------------------------------------------------------------

void GameEngine::run_highscore() {
    lcd.clear();
    lcd.printString("High Scores",9,0);
    lcd.printString("Back(B)",21,5);
    
    // Sets error to false as may of become true from previous error
    h_score.set_error(false);
    
    // Draws score/highscore part of screen
    char buffer[11]; 
    sprintf(buffer,"Score = %d",h_score.read_high_score(sd));
    lcd.printString(buffer,9,3);
    
    // If error reading high score just say no high score or sd card
    if (h_score.get_error()) {
       h_score.no_high_scores(lcd);
       wait(3);
       current_menu_part_ = main_menu;  
    }
    
    // Go back to main menu when b pressed
    if (pad.B_pressed()) { 
        current_menu_part_ = main_menu;
    }
    
    lcd.refresh();
}

bool GameEngine::calculate_new_score() {
    bool new_high_score = false;
    
    // Gets old high score and return true if current score is greater
    int saved_high_score = h_score.read_high_score(sd);
    if (points_ > saved_high_score) {
        new_high_score = true; 
        h_score.save_new_high_score(sd, lcd, points_);
    }
    return new_high_score;
}
