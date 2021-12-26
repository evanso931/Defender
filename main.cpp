/* 
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
Name: Benjamin Evans
Username:el18bpe
Student ID Number:201216635
Date:23/02/2020
*/

// pre-processor directives ----------------------------------------------------
#include "GameEngine.h"

#ifdef GAME_TEST
    #include "test.h"
#endif

// Objects ---------------------------------------------------------------------

/** Define Game Engine object*/ 
GameEngine engine;

// Functions -------------------------------------------------------------------

/** Runs the different test for the game */ 
void test_game();

int main()
{ 
    // Initialise the game engine
    engine.init();
    
    // Tests game
    test_game();
    
    while (1) {   
        // Selects the different parts of the game 
        engine.game_select_part();
        
        // Sets frame rate to 20 FPS for menu system
        wait(0.05);
    } 
}  

void test_game(){
    // Compile with tests
    #ifdef GAME_TEST
    
    // Spaceship tests
        run_spaceship_movement_tests();
        run_spaceship_draw_tests();
        
    // Map tests
        run_map_draw_tests();
        
    // Alien tests
        run_alien_draw_tests();
        run_check_collision_test();
        
    // Weapons tests
        run_weapons_draw_tests();
        
    // Explosion tests
        run_explosion_draw_tests();
        
    // People tests
        run_people_draw_tests();
        
    // Menu tests
        run_menu_select_part_test();
        run_menu_scroll_test();
        run_menu_draw_part_test();
        
    // HUD tests 
        run_HUD_draw_test();
        
    // Saved Games tests
        run_saved_games_scroll_test();
        run_display_saved_games_test();
        run_save_game_screen_test();
        
    // Settings tests
        run_settings_select_part_test();
        run_settings_scroll_test();
        run_display_settings_screen_test();
        
    // Play Engine tests
        run_no_high_scores_test();
        
    // Play Engine tests
        run_read_accelerometer_direction_test();
        run_spawn_aliens_test();
        run_create_alien_test();
        run_create_explosion_test();
        run_spawn_people_test();
        run_reset_map_timer_test();
        run_reset_map_test();
        
    #endif  
}
