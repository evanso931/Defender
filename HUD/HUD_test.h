#ifndef HUD_TEST_H
#define HUD_TEST_H

/** HUD Test
 * @brief Checks that the different parts of the hud draw
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool HUD_draw_test(int spaceship_lives, int points,  int smart_bomb_counter, 
int expected_pixel_status, int expected_postion_x, int expected_postion_y) {
    
    // Objects required for test 
    HUD hud;
    N5110 lcd;
    
    // Initialise lcd
    lcd.init();
    
    printf("HUD_draw x,y = %d,%d : ",expected_postion_x,expected_postion_y );
    
    hud.draw_HUD(lcd,spaceship_lives, points, smart_bomb_counter);
    
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
