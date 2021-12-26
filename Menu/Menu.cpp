#include "Menu.h"

const char menu_part_names[4][12] = {
    {"Play"},
    {"Settings"},
    {"Saved Games"},
    {"High Score"},
};

// Defining scroll_order states for scroll_order FSM
scroll_order menu_fsm[4] = {
    {high_score, play, settings},
    {play, settings, saved_games}, 
    {settings, saved_games, high_score},
    {saved_games, high_score, play},
}; 

Menu::Menu() {
    
}
 
Menu::~Menu() {
    
}

void Menu::init() {
    current_menu_part_ = main_menu;
    displayed_menu_part_ = play;
    // Attach ticker to ISR 
    ticker_title.attach(callback(this, &Menu::title_screen_isr), 0.9 );
    title_screen_flag_ = true;
}

void Menu::title_screen_isr() {
    // Set ISR flag
    title_screen_flag_ = !title_screen_flag_; 
} 

void Menu::draw_part(N5110 &lcd) {
    // Prints the menu part that should be displayed in the centre
    if (displayed_menu_part_ == play) {
        lcd.printString(menu_part_names[displayed_menu_part_],30 ,4);
    }else if (displayed_menu_part_ == settings) {
        lcd.printString(menu_part_names[displayed_menu_part_],18 ,4);
    }else if (displayed_menu_part_ == saved_games) {
        lcd.printString(menu_part_names[displayed_menu_part_],9 ,4);
    }
    else if (displayed_menu_part_ == high_score) {
        lcd.printString(menu_part_names[displayed_menu_part_],12 ,4);
    }
        
    lcd.drawSprite(39, 26, 3, 5, (int *)arrow_up);
    lcd.drawSprite(39, 42, 3, 5, (int *)arrow_down);
    
    // Flashes title screen
    if (title_screen_flag_) {
        title_screen(lcd);
    }else{
        lcd.printString("DEFENDER",18,1);
    }
    
    #ifdef MENU_DEBUG 
        printf("displayed_menu_part_ = %d\n",displayed_menu_part_);       
        printf("current_menu_part_ = %d\n", current_menu_part_);
    #endif 
}

void Menu::menu_scroll(Direction d_) {
    // printf("displayed_menu_part_ %d\n",displayed_menu_part_);
    // printf("d = %d\n",d_);
    
    // Changes displayed menu part depending on joystick input
    if (d_ == N || d_ == NE || d_ == NW ) {  
        displayed_menu_part_ = menu_fsm[displayed_menu_part_].part_next;   
    } else if (d_ == S || d_ == SW || d_ == SE) {
        displayed_menu_part_ = menu_fsm[displayed_menu_part_].part_previous;
    }
    wait(0.15);
}

void Menu::select_part(bool pressed) {
    if (pressed) {  
        current_menu_part_ = displayed_menu_part_;
        wait(0.3);
    } else {
        current_menu_part_ = main_menu;
    }  
}

MenuParts Menu::get_current_menu_part() {
    return current_menu_part_;
}

void Menu::title_screen(N5110 &lcd) {
    lcd.drawSprite(5, 8, 10,  8, (int *)title_screen_d); //D
    lcd.drawSprite(15, 8, 10, 7, (int *)title_screen_e); // E
    lcd.drawSprite(24, 8, 10, 7, (int *)title_screen_f); // F
    lcd.drawSprite(33, 8, 10, 7, (int *)title_screen_e); // E
    lcd.drawSprite(42, 8, 10, 7, (int *)title_screen_n); // N
    lcd.drawSprite(51, 8, 10, 8, (int *)title_screen_d); // D
    lcd.drawSprite(61, 8, 10, 7, (int *)title_screen_e); // E
    lcd.drawSprite(70, 8, 10, 8, (int *)title_screen_r); // R
}

