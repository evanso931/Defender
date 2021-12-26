#ifndef ALIEN_TEST_H
#define ALIEN_TEST_H

/** Alien Test
 * @brief Checks that the alien draws, moves and detects collisions
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool check_collision_test(bool expected_collision, bool bullet_direction,
int position_x_bullet,int position_y_bullet) {
    // Objects required for test 
    Alien alien;
    Weapons bullet;
    Gamepad pad;
    
    // Initialise alien in start position of 10, 22 
    alien.init(pad,10,22); 
    
    printf("collision =  %s : " ,expected_collision ? "true" : "false");
    
    // Set bullet direction and position 
    Vector2D pos = {position_x_bullet,position_y_bullet};
    bullet.set_pos_one(pos);
    bullet.set_direction(bullet_direction);
    
    // Checks collision function
    bool actual_collision = alien.check_collision(bullet);
    
    // Checks if collision is expected 
    if (actual_collision == expected_collision) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ("Failed! value = %s (expecting  %d)\n", 
        actual_collision ? "true" : "false", 
        expected_collision ? "true" : "false");
        return false;
    } 
}

bool alien_draw_test(int expected_pixel_status,Direction direction, 
int expected_x, int expected_y) {
    // Objects required for test 
    Gamepad pad;
    Spaceship spaceship;
    Alien alien;
    N5110 lcd;
    Map map;
    Direction d_;
    d_ = direction;
   
    
    // Initialise alien to set start position 10,23
    pad.init();
    alien.init(pad,expected_x, expected_y); 
    spaceship.init();

    printf("draw_alien = %d,%d  ", expected_x, expected_y);
    
    // Draws alien
    alien.draw_alien(lcd,spaceship.get_pos(),d_, map.get_length_map(), 
    map.get_position_x_map(), false);
    
    // Gets the alien_pos as it is random
    Vector2D alien_pos = alien.get_pos();
    int actual_x = alien_pos.x;
    int actual_y = alien_pos.y;
  
   // Reads middle pixel of alien where it is expected to be drawn 
    int actual_pixel_status = lcd.getPixel(actual_x + 3, 
    actual_y);
    
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
