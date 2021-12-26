#ifndef HIGHSCORE_TEST_H
#define HIGHSCORE_TEST_H

/** High Score Test
 * @brief Checks no score screen displays
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
 bool no_high_scores_test(int expected_pixel_status, int expected_postion_x, 
int expected_postion_y) {
    
    // Objects required for test
    HighScore high_score;
    N5110 lcd;
    
    // Initialise save and lcd
    high_score.init();
    lcd.init();
    
    printf("no_high_scores x,y = %d,%d : ",expected_postion_x,
    expected_postion_y );
    
    high_score.no_high_scores(lcd);
    
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
