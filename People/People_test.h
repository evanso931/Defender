#ifndef PEOPLE_TEST_H
#define PEOPLE_TEST_H

/** People Test
 * @brief Checks People draw corectly and moves joystick direction
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 * @return true if test are passed 
 */
bool people_draw_test(Direction d_, int expected_pixel_status, int expected_x){
    // Objects required for test 
    Gamepad pad;
    Map map;
    People people;
    N5110 lcd;
    
    // Initialises
    pad.init();
    lcd.init();
    map.init(pad); 
    people.init(pad,expected_x),

    printf(" expected pixel status = %d  ",expected_pixel_status);
    
    // Draws people
    people.draw_people(lcd, d_, map.get_length_map(), map.get_position_x_map());
    
    // Gets the position of person as it's random
    Vector2D people_pos = people.get_pos();
    
    // Reads pixel where person is expected to be drawn 
    int actual_pixel_status = lcd.getPixel(people_pos.x + 1, 
    people_pos.y + 1);
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (actual_pixel_status ==  expected_pixel_status) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", actual_pixel_status, 
        expected_pixel_status);
        return false;
    }
}

bool check_alien_collision_test(bool expected_collision, int expected_x){
    
    // Objects required for test 
    Alien alien;
    People people;
    Gamepad pad;
    
    // Initialise people x start position
    people.init(pad,expected_x); 
    
    printf("collision =  %s : " ,expected_collision ? "true" : "false");
    
    // Initialise alien to people position
    alien.init(pad,expected_x,43);
    
    // Checks collision function
    bool actual_collision = people.check_alien_collision(alien);
    
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
#endif
