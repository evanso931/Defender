#ifndef SAVEDGAMES_TEST_H
#define SAVEDGAMES_TEST_H

/** Saved Games Test
 * @brief Checks saved screen scrolls and draws properly
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool saved_games_scroll_test(Direction d_, int expected_display_data_number) {
    // Objects reqired for test
    SavedGames saved;
    
    // Initialise the menu
    saved.init();
    
    printf("Expected display number %d :  ",expected_display_data_number);
    
    saved.saved_games_scroll(d_);
    
    int actual_display_data_number = saved.get_display_data_number();
    
    // Gets the current menu part and checks if it is the expected menu part
    if (actual_display_data_number == expected_display_data_number) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! %d (expecting  %d,)\n", actual_display_data_number,
        expected_display_data_number);
        return false;
    }
}

bool display_saved_games_test(int expected_pixel_status, int expected_postion_x, 
int expected_postion_y) {
    
    // Objects required for test
    SavedGames saved;
    N5110 lcd;
    
    // Initialise save and lcd
    saved.init();
    lcd.init();
    
    printf("save_game_screen x,y = %d,%d : ",expected_postion_x,
    expected_postion_y );
    
    saved.display_saved_games(lcd);
    
    // Reads pixel where hud is expected to be drawn 
    int actual_pixel_status = lcd.getPixel(expected_postion_x, 
    expected_postion_y);
    
    // Checks if pixel is drawn and therefor testing it hasnt gone of screen
    if (actual_pixel_status == expected_pixel_status) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", actual_pixel_status, 
        expected_pixel_status);
        return false;
    }
}

bool save_game_screen_test(int expected_pixel_status, int expected_postion_x, 
int expected_postion_y) {
    
    // Objects required for test
    SavedGames saved;
    N5110 lcd;
    
    // Initialise save and lcd
    saved.init();
    lcd.init();
    
    printf("save_game_screen x,y = %d,%d : ",expected_postion_x,
    expected_postion_y );
    
    saved.save_game_screen(lcd);
    
    // Reads pixel where hud is expected to be drawn 
    int actual_pixel_status = lcd.getPixel(expected_postion_x, 
    expected_postion_y);
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (actual_pixel_status == expected_pixel_status) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", actual_pixel_status, 
        expected_pixel_status);
        return false;
    }
}
 

#endif
