#include "Settings.h"

const char settings_part_names[4][9] = {
    {"Contrast"},
    {"Controls"},
    {"Sound FX"}, 
    {"  Music "}, 
};

const char controls_part_names[2][4] = {
    {"Joy"},
    {"Acc"},
};

const char sound_part_names[2][4] = {
    {"On"},
    {"Off"},
};

const char music_part_names[2][4] = {
    {"On"},
    {"Off"},
};

// Defining scroll_order_settings states for scroll_order_settings FSM
scroll_order_setting settings_fsm[4] = { 
    {music, contrast, controls}, 
    {contrast, controls, sound_fx},
    {controls, sound_fx, music},
    {sound_fx, music, contrast}, 
}; 

// Defining on_off_order states for _on_off FSM
on_off_order settings_on_off_fsm[2] = {
    {off, on},
    {on, off}, 
};

// Defining on_off_order states for music_on_off FSM
music_on_off_order music_on_off_fsm[2] = {
    {music_off, music_on},
    {music_on, music_off}, 
};  

// Defining control_order states for settings_joy_acc FSM
control_order settings_joy_acc_fsm[2] = {
    {acc, joy}, 
    {joy, acc},
}; 

Settings::Settings() {
    
}
 
Settings::~Settings() {
    
}

void Settings::init() {
    control_method_ = joy;
    sound_method_ = on;
    displayed_settings_part_ = controls;
    music_method_ = music_on;
}

ControlsParts Settings::get_control_method() {
    return control_method_;
}


SoundParts Settings::get_sound_method() {
    return sound_method_;
}

MusicParts Settings::get_music_method() {
    return music_method_;
}

SettingsParts Settings::get_displayed_settings_part() {
    return displayed_settings_part_;
}

void Settings::display_settings_screen(N5110 &lcd, float pot_read) {
    // Prints different settings parts
    if(displayed_settings_part_ == controls) {
        lcd.printString(settings_part_names[displayed_settings_part_],6 ,3);
        lcd.printString(controls_part_names[control_method_],60 ,3);
    }else if(displayed_settings_part_ == sound_fx) {
        lcd.printString(settings_part_names[displayed_settings_part_],6 ,3);
        lcd.printString(sound_part_names[sound_method_],60 ,3);
    }else if(displayed_settings_part_ == music) {
        lcd.printString(settings_part_names[displayed_settings_part_],6 ,3);
        lcd.printString(music_part_names[music_method_],60 ,3);
    }else if(displayed_settings_part_ == contrast) {
        lcd.printString(settings_part_names[displayed_settings_part_],6 ,3);
        char buffer[2]; 
        sprintf(buffer,"%.2f",pot_read);
        lcd.printString(buffer,58,3);
    }
    
    // prints setting title and button instructions and arrows
    lcd.printString("Settings",18,0);
    lcd.drawSprite(39, 18, 3, 5, (int *)arrow_up);
    lcd.drawSprite(39, 34, 3, 5, (int *)arrow_down);
    lcd.printString("Back(B)Alt(A)",3,5);
}

void Settings::change_setting(bool pressed) {
    // When a is pressed changes the settings for the displayed setting part
    if (pressed) { 
        if (displayed_settings_part_ == sound_fx) { 
        sound_method_ = settings_on_off_fsm[sound_method_].part_next;  
        }else if(displayed_settings_part_ == controls) {
            control_method_ = settings_joy_acc_fsm[control_method_].part_next;  
        }else if(displayed_settings_part_ == music) {
            music_method_ =  music_on_off_fsm[music_method_].part_next; 
        }   
    wait(0.3);   
    }
    
}

void Settings::settings_scroll(Direction d_) {
    // Changes displayed settings part depending on joystick input
    if (d_ == N || d_ == NE || d_ == NW ) {  
        // printf(" displayed_settings_part_ %d\n",displayed_settings_part_);
        displayed_settings_part_ = 
        settings_fsm[displayed_settings_part_].part_next;   
    } else if (d_ == S || d_ == SW || d_ == SE) {
        displayed_settings_part_= 
        settings_fsm[displayed_settings_part_].part_previous; 
    }
    wait(0.15);
}
