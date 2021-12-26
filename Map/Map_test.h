#ifndef MAP_TEST_H
#define MAP_TEST_H

/** Map Test
 * @brief Checks that the map moves to the correct x position depending on 
 * joystick input
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 * @return true if test are passed 
 */
bool map_move_test(Direction d_, int expected_x_position) {
    // Objects required for test
    Map map;
    N5110 lcd;
    Gamepad pad;
    
    // Initialise map in start position of -84,42
    pad.init();
    map.init(pad); 
    
    printf("Espected map x position = %d, : ",expected_x_position);
    
    // Draws map but with move variable set so it starts above 0
    // As can't rea pixel of the LCD
    map.draw_map(lcd, d_);
    
    // Reads start position of map drawn
    int map_start_draw_postion = map.get_position_x_map();
    
    // Checks final position with expected
    if (map_start_draw_postion  == expected_x_position) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d,  (expecting  %d)\n",
        map_start_draw_postion, expected_x_position);
        return false;
    }
}

#endif
