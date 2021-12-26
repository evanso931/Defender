#include "SavedGames.h"

SavedGames::SavedGames() {
    
}

SavedGames::~SavedGames() {
    
}

bool SavedGames::save_test(Direction d_,SDFileSystem &sd, N5110 &lcd) {
    
    // Objects required for test 
    
    printf("Data save = %d  : ",d_);
    
    // Define input data object and set values
    SavedGamesData input_data;
    input_data.score = 0;
    input_data.lives = 3;
    input_data.smart_bombs = 4;
    input_data.alien_number = 5;

    // Change the save file
    saved_games_scroll(d_);
    
    add_saved_data(sd, input_data, lcd); 
    
    // Define output data object
    SavedGamesData output_data;
    
    output_data = read_saved_data(sd, lcd);   
    
    // Checks if the input and output are equal
    if (output_data.score == input_data.score && 
    output_data.lives == input_data.lives &&
    output_data.smart_bombs == input_data.smart_bombs &&
    output_data.alien_number == input_data.alien_number ) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed!\n");
        return false;
    }
}

void SavedGames::run_save_test(SDFileSystem &sd, N5110 &lcd) {
    printf ("\nTesting  save_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (save_test(CENTRE, sd, lcd)) passed_counter++;
    if (save_test(N, sd, lcd)) passed_counter++;
    if (save_test(NE, sd, lcd)) passed_counter++;
    if (save_test(E, sd, lcd)) passed_counter++;
    if (save_test(SE, sd, lcd)) passed_counter++;
    if (save_test(S, sd, lcd)) passed_counter++;
    if (save_test(SW, sd, lcd)) passed_counter++;
    if (save_test(W, sd, lcd)) passed_counter++;
    if (save_test(NW, sd, lcd)) passed_counter++;
       
    // Prints results
    printf ("\n save_test passed %d tests out of 9\n\n\n",
    passed_counter);
}

void SavedGames::init() {
    error_ = false;
    display_data_number_ = 1; 
}

void SavedGames::check_sd_present(SDFileSystem &sd, N5110 &lcd) {
    if(!sd.card_present()) {
        // Print error screen
        lcd.clear();
        lcd.printString("SD card not ",9,3);
        lcd.printString("  present   ",9,4);
        lcd.refresh();
        wait(3);
    }
}

void SavedGames::error_open_file(N5110 &lcd) {
    error_ = true;

    // Print error screen
    lcd.clear();
    lcd.printString(" Unable to  ",9,3);
    lcd.printString(" open file  ",9,4);
    lcd.refresh();
    wait(3); 
}

void SavedGames::no_saved_files(N5110 &lcd) {
    error_ = true;
    
    // Print error screen
    lcd.clear();
    lcd.printString("No saved Files",0,3);
    lcd.refresh();
    wait(3); 
}

void SavedGames::add_saved_data(SDFileSystem &sd,SavedGamesData data,
 N5110 &lcd) {
    check_sd_present(sd,lcd);
    FILE *fp;
    
    // Overwrites selected save file
    if (display_data_number_ == 1) {    
        fp = fopen("/sd/SavedGamesOne.csv", "w");
       // printf ("save1 \n");
    }else if (display_data_number_ == 2) {
        fp = fopen("/sd/SavedGamesTwo.csv", "w");
       // printf ("save2\n" );
    }else{
        fp = fopen("/sd/SavedGamesThree.csv", "w");
       // printf ("save2 \n");
    }
     
    if (fp == NULL) {
        error_open_file(lcd);
            
    }else{
        // printf ("add data.score = %d \n", data.score);
        // printf ("add data.lives = %d \n", data.lives);
        // printf ("adddata.smart_bombs = %d \n", data.smart_bombs);
        // printf ("add data.alien_number = %d \n", data.lives);      
        
        // Adds data to file if no error
        fprintf(fp, "%d,%d,%d,%d\n", data.score, data.lives, data.smart_bombs,
        data.alien_number); 
        fclose(fp);
    }  
}

SavedGamesData SavedGames::read_saved_data(SDFileSystem &sd, N5110 &lcd) {
    check_sd_present(sd,lcd);
    
    FILE *fp;
    SavedGamesData data;
    
    // Opens displayed file  
    if (display_data_number_ == 1) {    
        fp = fopen("/sd/SavedGamesOne.csv", "r");
        //printf ("open save1\n");
    }else if (display_data_number_ == 2) {
        fp = fopen("/sd/SavedGamesTwo.csv", "r");
        //printf ("open save2\n");
    }else{
        fp = fopen("/sd/SavedGamesThree.csv", "r");
       // printf ("open save2\n");
    }
    
    // Check if any saved game files
    if (fp == NULL) {
        no_saved_files(lcd); 
        
    // Reads saved data into object
    }else{
        
        // Read save file and add values to data object
        fscanf(fp, "%d,%d,%d,%d",&data.score, &data.lives,&data.smart_bombs,
        &data.alien_number);
          
        // printf ("saved_data_vector_ 1%d \n", saved_data_vector.size());
        fclose(fp);           
    } 
     
    return data;
}

void SavedGames::display_saved_games(N5110 &lcd) {
    lcd.clear();
    
    // Prints saved game screen
    lcd.printString("Saved Games",9,0);
    lcd.drawSprite(39, 18, 3, 5, (int *)arrow_up);
    lcd.drawSprite(39, 34, 3, 5, (int *)arrow_down);
    
    // Prints saved game that is displayed
    char buffer[9]; 
    sprintf(buffer,"Save %2d",display_data_number_);
    lcd.printString(buffer,21,3);
    lcd.printString("Back(B)Play(A)",0,5);
    
    lcd.refresh();
}

void SavedGames::save_game_screen(N5110 &lcd) {
    lcd.clear();
    
    // Prints saved game screen
    lcd.printString("Select a save",3,0);
    lcd.drawSprite(39, 18, 3, 5, (int *)arrow_up);
    lcd.drawSprite(39, 34, 3, 5, (int *)arrow_down);
    
    // Prints saved game that is displayed
    char buffer[9]; 
    sprintf(buffer,"Save %2d",display_data_number_);
    lcd.printString(buffer,21,3);
    lcd.printString("Save(A)",21,5);

    lcd.refresh();
}

void SavedGames::saved_games_scroll(Direction d_) {
    
    // Changes displayed menu part depending on joystick input
    if (d_ == N || d_ == NE || d_ == NW ) {   
        display_data_number_++;
        
        // Loops back round when at end of saved game vector
        if(display_data_number_ > 3) {
          display_data_number_ = 1; 
        }        
    } else if (d_ == S || d_ == SW || d_ == SE) {
        display_data_number_--;
         if(display_data_number_ < 1 ) {
          display_data_number_ = 3; 
        }
    }
    wait(0.15);
}  


int SavedGames::get_display_data_number() {
    return display_data_number_;
}
