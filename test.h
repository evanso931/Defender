#ifndef TESTS_H
#define TESTS_H

// Included Headers ------------------------------------------------------------
#include "Spaceship_test.h"
#include "Map_test.h"
#include "Alien_test.h"
#include "Weapons_test.h"
#include "Explosion_test.h"
#include "People_test.h"
#include "Menu_test.h"
#include "HUD_test.h"
#include "SavedGames_test.h"
#include "Settings_test.h"
#include "HighScore_test.h"
#include "PlayEngine_test.h"
 
/** Test
 * @brief Runs all tests for game 
 * @author Benjamin Evans, University of Leeds
 * @date April 2020 
 */
// Spaceship tests -------------------------------------------------------------

void run_spaceship_movement_tests() {
    printf ("\nTesting spaceship_movement_test() \n");
    int passed_counter = 0;

    // Runs test with all possible movement directions 
    if (spaceship_movement_test(CENTRE, 36, 22)) passed_counter++;
    if (spaceship_movement_test(N, 36, 21)) passed_counter++;
    if (spaceship_movement_test(NE, 35, 21)) passed_counter++;
    if (spaceship_movement_test(E, 35, 22)) passed_counter++;
    if (spaceship_movement_test(SE, 35, 23)) passed_counter++;
    if (spaceship_movement_test(S, 36, 23)) passed_counter++;
    if (spaceship_movement_test(SW, 37, 23)) passed_counter++;
    if (spaceship_movement_test(W, 37, 22)) passed_counter++;
    if (spaceship_movement_test(NW, 37, 21)) passed_counter++;
    
    // Prints results
    printf ("\nspaceship_movement_test passed %d tests out of 9\n\n\n",
    passed_counter);
}

void run_spaceship_draw_tests() {
    printf ("\nTesting spaceship_draw_tests() \n\n");
    int passed_counter = 0;
    
    // Runs test with max movement directions 
    if (spaceship_draw_test(NE, 1, 15, 9)) passed_counter++;
    if (spaceship_draw_test(SE, 1, 15, 44)) passed_counter++;
    if (spaceship_draw_test(SW, 1, 64, 44)) passed_counter++;
    if (spaceship_draw_test(NW, 1, 64, 9)) passed_counter++;
    
    // Prints results
    printf ("\nspaceship_draw_test passed %d tests out of 4\n\n\n",passed_counter);
}



// Map tests -------------------------------------------------------------------

void run_map_draw_tests() {
    printf ("\nTesting map_draw_tests() \n\n");
    int passed_counter = 0;
    
    // Runs multiple map tests
    if (map_move_test(CENTRE, -84)) passed_counter++;
    if (map_move_test(N, -84)) passed_counter++;
    if (map_move_test(NE,-86)) passed_counter++;
    if (map_move_test(E, -86)) passed_counter++;
    if (map_move_test(SE, -86)) passed_counter++;
    if (map_move_test(S, -84)) passed_counter++;
    if (map_move_test(SW, -82)) passed_counter++;
    if (map_move_test(W, -82)) passed_counter++;
    if (map_move_test(NW, -82)) passed_counter++;
    
    // Prints results
    printf ("\nmap_draw_test passed %d tests out of 9\n\n\n",passed_counter);
}



// Alien tests -----------------------------------------------------------------

void run_alien_draw_tests() {
    printf ("\nTesting alien_draw_test() \n\n");
    int passed_counter = 0;

    // Runs test with all possible movement directions 
    if (alien_draw_test(1,CENTRE, 1, 1)) passed_counter++;
    if (alien_draw_test(1,N, 43, 20)) passed_counter++;
    if (alien_draw_test(0,NE, -23, 6)) passed_counter++;
    if (alien_draw_test(0,E, 23, -34)) passed_counter++;
    if (alien_draw_test(0,SE, -23, -43)) passed_counter++;
    if (alien_draw_test(0,S, 100, 26)) passed_counter++;
    if (alien_draw_test(0,SE, 40, 100)) passed_counter++;
    if (alien_draw_test(1,E, 70, 5)) passed_counter++;
    if (alien_draw_test(1,NE, 6, 44)) passed_counter++;
    
    // Prints results
    printf ("\nalien_draw_test passed %d tests out of 9\n\n\n",passed_counter);
}

void run_check_collision_test() {
    printf ("\nTesting alien_collision_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (check_collision_test(1, 1, 10,22)) passed_counter++;
    if (check_collision_test(0, 1, 28,40)) passed_counter++;
    if (check_collision_test(1, 0, 11,22)) passed_counter++;
    if (check_collision_test(0, 0, 20,22)) passed_counter++;
    
    // Prints results
    printf ("\nalien_draw_test passed %d tests out of 4\n\n\n",passed_counter);
}


// Weapons tests ---------------------------------------------------------------

void run_weapons_draw_tests() {
    printf ("\nTesting spaceship_draw_tests() \n\n");
    int passed_counter = 0;
    
    // Runs test with max movement directions 
    if (weapons_draw_test(1, 1, 1, 49, 24)) passed_counter++;
    if (weapons_draw_test(1, 1, 2, 52, 24)) passed_counter++;
    if (weapons_draw_test(0, 1, 2, 49, 24)) passed_counter++;
    if (weapons_draw_test(1, 0, 1, 36, 24)) passed_counter++;
    if (weapons_draw_test(1, 0, 2, 33, 24)) passed_counter++;
    if (weapons_draw_test(0, 0, 2, 33, 24)) passed_counter++;
    
    // Prints results
    printf ("\nspaceship_draw_test passed %d tests out of 6\n\n\n",passed_counter);
}



// Explosion tests -------------------------------------------------------------

void run_explosion_draw_tests() {
    printf ("\nTesting explosion_draw_tests() \n\n");
    int passed_counter = 0;
    
    // Runs test with max movement directions 
    if (explosion_draw_test(1, 15, 3)) passed_counter++;
    if (explosion_draw_test(1, 15, 44)) passed_counter++;
    if (explosion_draw_test(1, 64, 44)) passed_counter++;
    if (explosion_draw_test(1, 64, 2)) passed_counter++;
    
    // Prints results
    printf ("\nspaceship_draw_test passed %d tests out of 4\n\n\n",passed_counter);
}



// People tests ----------------------------------------------------------------

void run_people_draw_tests() {
    printf ("\nTesting people_draw_tests() \n\n");
    int passed_counter = 0;
    
    // Runs test with max movement directions 
    if (people_draw_test(CENTRE, 1,44)) passed_counter++;
    if (people_draw_test(N, 0,100)) passed_counter++;
    if (people_draw_test(NE, 0, -100)) passed_counter++;
    if (people_draw_test(E, 1,0)) passed_counter++;
    if (people_draw_test(SE, 1,82)) passed_counter++;
    if (people_draw_test(S, 1,43)) passed_counter++;
    if (people_draw_test(SW, 0,-64)) passed_counter++;
    if (people_draw_test(W, 0,-6)) passed_counter++;
    if (people_draw_test(NW, 0,84)) passed_counter++;
    
    // Prints results
    printf ("\npeople_draw_test passed %d tests out of 9\n\n\n",passed_counter);
}

void run_check_alien_collision_test() {
    printf ("\nTesting check_alien_collision_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (check_alien_collision_test(1,1)) passed_counter++;
    if (check_alien_collision_test(1,80)) passed_counter++;
    if (check_alien_collision_test(1,-42)) passed_counter++;
    if (check_alien_collision_test(1,100)) passed_counter++;
    
    // Prints results
    printf ("\ncheck_alien_collision_test passed %d tests out of 4\n\n\n",
    passed_counter);
}



// Menu tests ------------------------------------------------------------------

void run_menu_select_part_test() {
    printf ("\nTesting menu_select_part_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (menu_select_part_test(play,1)) passed_counter++;
    if (menu_select_part_test(main_menu,0)) passed_counter++;
    
    // Prints results
    printf ("\nmenu_select_part_test passed %d tests out of 2\n\n\n",
    passed_counter);
}

void run_menu_scroll_test() {
    printf ("\nTesting menu_scroll_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (menu_scroll_test(CENTRE, play)) passed_counter++;
    if (menu_scroll_test(N, settings)) passed_counter++;
    if (menu_scroll_test(NE, settings)) passed_counter++;
    if (menu_scroll_test(E,  play)) passed_counter++;
    if (menu_scroll_test(SE, high_score)) passed_counter++;
    if (menu_scroll_test(S, high_score)) passed_counter++;
    if (menu_scroll_test(SW, high_score)) passed_counter++;
    if (menu_scroll_test(W,  play)) passed_counter++;
    if (menu_scroll_test(NW, settings)) passed_counter++;
    
    // Prints results
    printf ("\nmenu_scroll_test passed %d tests out of 9\n\n\n",
    passed_counter);
}

void run_menu_draw_part_test() {
    printf ("\nmenu_draw_part_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (menu_draw_part_test(1, 42, 27)) passed_counter++;
    if (menu_draw_part_test(1, 41, 43)) passed_counter++;
    if (menu_draw_part_test(0, 9, 1)) passed_counter++;
    if (menu_draw_part_test(0, 0, 0)) passed_counter++;
       
    // Prints results
    printf ("\nmenu_draw_part_test %d tests out of 4\n\n\n",
    passed_counter);
}




// HUD tests -------------------------------------------------------------------

void run_HUD_draw_test() {
    printf ("\nTesting HUD_draw_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (HUD_draw_test(3, 0, 4, 1, 3, 3)) passed_counter++;
    if (HUD_draw_test(3, 0, 4, 1, 12, 3)) passed_counter++;
    if (HUD_draw_test(1, 0, 4, 0, 12, 3)) passed_counter++;
    if (HUD_draw_test(3, 0, 4, 1, 62, 3)) passed_counter++;
    if (HUD_draw_test(3, 0, 3, 0, 62, 3)) passed_counter++;
    if (HUD_draw_test(3, 0, 3, 1, 30, 3)) passed_counter++;
    if (HUD_draw_test(3, 1111, 3, 00, 30, 3)) passed_counter++;
       
    // Prints results
    printf ("\nHUD_draw_test passed %d tests out of 7\n\n\n",
    passed_counter);
}




// Saved Games tests -----------------------------------------------------------

void run_saved_games_scroll_test() {
    printf ("\nsaved_games_scroll_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (saved_games_scroll_test(CENTRE, 1)) passed_counter++;
    if (saved_games_scroll_test(N, 2)) passed_counter++;
    if (saved_games_scroll_test(NE, 2)) passed_counter++;
    if (saved_games_scroll_test(E,  1)) passed_counter++;
    if (saved_games_scroll_test(SE, 3)) passed_counter++;
    if (saved_games_scroll_test(S, 3)) passed_counter++;
    if (saved_games_scroll_test(SW, 3)) passed_counter++;
    if (saved_games_scroll_test(W,  1)) passed_counter++;
    if (saved_games_scroll_test(NW, 2)) passed_counter++;
    
    // Prints results
    printf ("\nsaved_games_scroll_test passed %d tests out of 9\n\n\n",
    passed_counter);
}

void run_display_saved_games_test() {
    printf ("\nTesting display_saved_games_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (display_saved_games_test(1, 41, 18 )) passed_counter++;
    if (display_saved_games_test(1, 41, 34)) passed_counter++;
    if (display_saved_games_test(1, 9, 1)) passed_counter++;
    if (display_saved_games_test(0, 0, 0)) passed_counter++;
       
    // Prints results
    printf ("\ndisplay_saved_games_test %d tests out of 4\n\n\n",
    passed_counter);
}

void run_save_game_screen_test() {
    printf ("\nTesting save_game_screen_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (save_game_screen_test(1, 41, 18 )) passed_counter++;
    if (save_game_screen_test(1, 41, 34)) passed_counter++;
    if (save_game_screen_test(1, 3, 1)) passed_counter++;
    if (save_game_screen_test(0, 0, 0)) passed_counter++;
       
    // Prints results
    printf ("\nsave_game_screen_test %d tests out of 4\n\n\n",
    passed_counter);
}



// Settings tests --------------------------------------------------------------

void run_settings_select_part_test() {
    printf ("\nTesting settings_select_part_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (settings_select_part_test(acc,1)) passed_counter++;
    if (settings_select_part_test(joy,0)) passed_counter++;
    
    // Prints results
    printf ("\nsettings_select_part_test passed %d tests out of 2\n\n\n",
    passed_counter);
}

void run_settings_scroll_test() {
    printf ("\nsettings_scroll_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (settings_scroll_test(CENTRE, controls)) passed_counter++;
    if (settings_scroll_test(N, sound_fx)) passed_counter++;
    if (settings_scroll_test(NE, sound_fx)) passed_counter++;
    if (settings_scroll_test(E, controls)) passed_counter++;
    if (settings_scroll_test(SE, contrast)) passed_counter++;
    if (settings_scroll_test(S, contrast)) passed_counter++;
    if (settings_scroll_test(SW, contrast)) passed_counter++;
    if (settings_scroll_test(W,  controls)) passed_counter++;
    if (settings_scroll_test(NW, sound_fx)) passed_counter++;
    
    // Prints results
    printf ("\nsettings_scroll_test passed %d tests out of 9\n\n\n",
    passed_counter);
}

void run_display_settings_screen_test() {
    printf ("\ndisplay_settings_screen_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (display_settings_screen_test(1, 41, 18 )) passed_counter++;
    if (display_settings_screen_test(1, 41, 34)) passed_counter++;
    if (display_settings_screen_test(0, 9, 1)) passed_counter++;
    if (display_settings_screen_test(0, 0, 0)) passed_counter++;
       
    // Prints results
    printf ("\ndisplay_settings_screen_test %d tests out of 4\n\n\n",
    passed_counter);
}




// High Score tests ------------------------------------------------------------

void run_no_high_scores_test() {
    printf ("\nno_high_scores_test_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (no_high_scores_test(1, 0, 27)) passed_counter++;
    if (no_high_scores_test(1, 3, 35)) passed_counter++;
    if (no_high_scores_test(0, 9, 1)) passed_counter++;
    if (no_high_scores_test(0, 0, 0)) passed_counter++;
       
    // Prints results
    printf ("\nno_high_scores_test %d tests out of 4\n\n\n",
    passed_counter);
}




// Play Engine tests -----------------------------------------------------------

void run_read_accelerometer_direction_test() {
    printf ("\nread_accelerometer_direction_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (read_accelerometer_direction_test(CENTRE,5,-40 )) passed_counter++;
    if (read_accelerometer_direction_test(N, 5,-10)) passed_counter++;
    if (read_accelerometer_direction_test(NE, 20, -10)) passed_counter++;
    if (read_accelerometer_direction_test(E, 20,-40)) passed_counter++;
    if (read_accelerometer_direction_test(SE, 20,-60)) passed_counter++;
    if (read_accelerometer_direction_test(S, 5,-60)) passed_counter++;
    if (read_accelerometer_direction_test(SW, -20,-60)) passed_counter++;
    if (read_accelerometer_direction_test(W,  -40, -40)) passed_counter++;
    if (read_accelerometer_direction_test(NW, -15, -10)) passed_counter++;
    
    // Prints results
    printf ("\nread_accelerometer_direction_test passed %d tests out of 9\n\n\n"
    ,passed_counter);
}

void run_spawn_aliens_test() {
    printf ("\nspawn_aliens_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (spawn_aliens_test(1)) passed_counter++;
    if (spawn_aliens_test(3)) passed_counter++;
    if (spawn_aliens_test(5)) passed_counter++;
    if (spawn_aliens_test(10)) passed_counter++;
    if (spawn_aliens_test(20)) passed_counter++;
        
    // Prints results
    printf ("\nspawn_aliens_test passed %d tests out of 5\n\n\n"
    ,passed_counter);
}

void run_create_alien_test() {
    printf ("\ncreate_aliens_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (create_alien_test(2)) passed_counter++;
    if (create_alien_test(4)) passed_counter++;
    if (create_alien_test(6)) passed_counter++;
    if (create_alien_test(15)) passed_counter++;
    if (create_alien_test(30)) passed_counter++;
        
    // Prints results
    printf ("\ncreate_aliens_test() %d tests out of 5\n\n\n"
    ,passed_counter);
}

void run_create_explosion_test() {
    printf ("\ncreate_explosion_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (create_explosion_test(3)) passed_counter++;
    if (create_explosion_test(6)) passed_counter++;
    if (create_explosion_test(9)) passed_counter++;
    if (create_explosion_test(1)) passed_counter++;
    if (create_explosion_test(22)) passed_counter++;
        
    // Prints results
    printf ("\ncreate_explosion_test() %d tests out of 5\n\n\n"
    ,passed_counter);
}

void run_spawn_people_test() {
    printf ("\nspawn_people_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (spawn_people_test(1)) passed_counter++;
    if (spawn_people_test(2)) passed_counter++;
    if (spawn_people_test(3)) passed_counter++;
    if (spawn_people_test(4)) passed_counter++;
    if (spawn_people_test(5)) passed_counter++;
        
    // Prints results
    printf ("\nspawn_people_test passed %d tests out of 5\n\n\n"
    ,passed_counter);
}
 
void run_people_alien_test() {
    printf ("\ncreate_people_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (create_people_test(1)) passed_counter++;
    if (create_people_test(2)) passed_counter++;
    if (create_people_test(3)) passed_counter++;
    if (create_people_test(4)) passed_counter++;
    if (create_people_test(5)) passed_counter++;
        
    // Prints results
    printf ("\ncreate_people_test() %d tests out of 5\n\n\n"
    ,passed_counter);
}

void run_reset_map_timer_test() {
    printf ("\nreset_map_timer_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (reset_map_timer_test(CENTRE, true)) passed_counter++;
    if (reset_map_timer_test(N, false)) passed_counter++;
        
    // Prints results
    printf ("\nreset_map_timer_test() %d tests out of 2\n\n\n"
    ,passed_counter);
}

void run_reset_map_test() {
    printf ("\nreset_map_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (reset_map_test()) passed_counter++;
        
    // Prints results
    printf ("\nreset_map_test() %d tests out of 1\n\n\n"
    ,passed_counter);
}
#endif
