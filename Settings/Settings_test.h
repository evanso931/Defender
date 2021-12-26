#ifndef SETTINGS_TEST_H
#define SETTINGS_TEST_H

/** Settings Test
 * @brief Test the different settings function 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool settings_select_part_test(ControlsParts expected_control_part, bool pressed) {
    // Objects required for test
    Settings settings;
    
    // Initialise the settings
    settings.init();
    
    if (pressed) {
        printf("Expected controls part Accelerometer :  ");
    }else{
        printf("Expected controls part Joystick :  ");
    }
    
    // Calls settings change function with pressed and not pressed
    settings.change_setting(pressed);
     
    // Gets the current menu part and checks if it is the expected menu part
    if (settings.get_control_method() == expected_control_part) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed!\n");
        return false;
    }
}

bool settings_scroll_test(Direction d_, SettingsParts expected_setting_part) {
    // Objects required for test
    Settings settings;
    
    // Initialise the settings
    settings.init();
    
    printf("Expected settings part %d :  ",expected_setting_part);
    
    settings.settings_scroll(d_);
    
    SettingsParts actual_setting_part = settings.get_displayed_settings_part();
    
    // Gets the current menu part and checks if it is the expected menu part
    if (actual_setting_part == expected_setting_part) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! %d (expecting  %d,)\n", actual_setting_part,
        expected_setting_part);
        return false;
    }
}

bool display_settings_screen_test(int expected_pixel_status, 
int expected_postion_x, int expected_postion_y) {
    // Objects required for test
    Settings settings;
    N5110 lcd;
    
    // Initialise the settings
    settings.init();
    lcd.init();

    printf("display_settings_screen x,y = %d,%d : ",expected_postion_x,
    expected_postion_y );
    
    settings.display_settings_screen(lcd, 0.01);
    
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
