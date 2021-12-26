#ifndef WEAPONS_TEST_H
#define WEAPONS_TEST_H

/** Weapons Test
 * @brief Checks that the weapons draws
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool weapons_draw_test(int expected_pixel_status,bool direction, 
int bullet_movement, int expected_postion_x, int expected_postion_y) {
    // Objects required for test 
    Weapons bullet;
    Spaceship spaceship;
    N5110 lcd;
    
    // Initialise objects for test
    spaceship.init();
    lcd.init();
    bullet.init(spaceship.get_pos(), direction, true); 
    
    printf("draw_bullet = %d,%d : ", expected_postion_x, expected_postion_y);
    
    // Draws bullet in different positions
    for(int i = 0;i <= bullet_movement; i++) {
        bullet.draw_bullet(lcd);
    }
    
    // Reads pixel where bullet is expected to be drawn 
    int actual_pixel_status = lcd.getPixel(expected_postion_x, 
    expected_postion_y);
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (actual_pixel_status) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", actual_pixel_status, 
        expected_pixel_status);
        return false;
    }
}

#endif
