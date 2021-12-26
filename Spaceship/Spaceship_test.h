#ifndef SPACESHIP_TEST_H
#define SPACESHIP_TEST_H

/** Spaceship Test
 * @brief Checks Spaceship move to the correct position when moved and doesn’t go 
 * of map when being drawn
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 * @return true if test are passed 
 */
bool spaceship_movement_test(Direction d_, int expected_x,int expected_y) {
    // Objects required for test 
    FXOS8700CQ accelerometer(I2C_SDA,I2C_SCL);
    Gamepad pad;
    Spaceship spaceship;
    
    // Initialise spaceship in start position of 36, 22 
    pad.init();
    spaceship.init(); 
    
    printf("spaceship_movement = %d,%d : ", expected_x, expected_y );
    
    // Moves spaceship
    spaceship.movement(d_);
    
    // Reads finish spaceship position 
    Vector2D finish_postion = spaceship.get_pos();
    
    // Checks final position with expected
    if (finish_postion.x == expected_x && finish_postion.y == expected_y) {
        printf ( "Passed!\n");
        return true;
    } else {
        int finish_x_postion = finish_postion.x;
        int finish_y_postion = finish_postion.y;
        printf ( "Failed! value = %d,%d (expecting  %d,%d)\n", finish_x_postion, 
        finish_y_postion, expected_x, expected_y);
        return false;
    }  
}

bool spaceship_draw_test(Direction d_, int expected_pixel_status, 
int expected_postion_x, int expected_postion_y) {
    // Objects required for test 
    Gamepad pad;
    Spaceship spaceship;
    N5110 lcd;
    
    // Initialise spaceship in start position of 36, 22 
    pad.init();
    lcd.init();
    spaceship.init(); 
    
    // Reads start spaceship position 
    printf("spaceship_draw x,y= %d,%d : ",expected_postion_x, 
    expected_postion_y );
    
    // Moves spaceship to max/min x and y positions to test 
    // off_screen_x_y_checker
    for (int i = 0; i < 30; i++) {
        spaceship.movement(d_);
    }
    
    // Draws spaceship
    spaceship.draw(lcd);
    
    // Reads pixel where spaceship is expected to be drawn 
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
