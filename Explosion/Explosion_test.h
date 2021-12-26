#ifndef EXPLOSION_TEST_H
#define EXPLOSION_TEST_H

/** EXPLOSION Test
 * @brief Checks explosion animation is drawn 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool explosion_draw_test(int expected_pixel_status, int expected_postion_x, 
int expected_postion_y) {
    // Objects required for test 
    Gamepad pad;
    Explosion explosion;
    N5110 lcd;
    
    // Sets position of explosion
    Vector2D detroyed_pos = {expected_postion_x,expected_postion_y};
    
    // Initialise objects
    pad.init();
    lcd.init();
    explosion.init(detroyed_pos);
    
    // Reads start spaceship position 
    printf("explosion_draw x,y= %d,%d : ",expected_postion_x, 
    expected_postion_y);
   
    // Draws explosion
    explosion.draw_explosion(lcd);
    
    // Reads pixel where explosion is expected to be drawn 
    int actual_pixel_status = lcd.getPixel(expected_postion_x + 3, 
    expected_postion_y + 3);
    
    // Checks if pixel is drawn and therefor testing if it has gone of screen
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
