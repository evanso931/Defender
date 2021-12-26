#ifndef MENU_TEST_H
#define MENU_TEST_H

/** Menu Test
 * @brief Test the different Menu functions
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
bool menu_select_part_test(MenuParts expected_menu_part, bool pressed) {
    // Objects required for test
    Menu menu;
    
    // Initialise the menu
    menu.init();
    
    if (pressed) {
        printf("Expected menu part play :  ");
    }else{
        printf("Expected menu part main menu :  ");
    }
    
    // Calls menu select function with pressed and not pressed
    menu.select_part(pressed);
    
    
    // Gets the current menu part and checks if it is the expected menu part
    if ( menu.get_current_menu_part() == expected_menu_part) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed!\n");
        return false;
    }
}

bool menu_scroll_test(Direction d_,MenuParts expected_menu_part) {
    // Objects required for test
    Menu menu;
    
    // Initialise the menu
    menu.init();
    
    printf("Expected menu part %d :  ",expected_menu_part);
    
    menu.menu_scroll(d_);
    
    // Calls menu select function to so we can then get the displayed menu part
    menu.select_part(true);
    
    MenuParts actual_menu_part = menu.get_current_menu_part();
    
    // Gets the current menu part and checks if it is the expected menu part
    if ( actual_menu_part == expected_menu_part) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! %d (expecting  %d,)\n", actual_menu_part,
        expected_menu_part);
        return false;
    }
}

bool menu_draw_part_test(int expected_pixel_status, 
int expected_postion_x, int expected_postion_y) {
    // Objects required for test
    Menu menu;
    N5110 lcd;
    
    // Initialise the Menu
    menu.init();
    lcd.init();

    printf("menu_draw_part x,y = %d,%d : ",expected_postion_x,
    expected_postion_y );
    
    menu.draw_part(lcd);
    
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
