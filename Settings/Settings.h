#ifndef SETTINGS_H
#define SETTINGS_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Sprites.h"

/** Enum for different menu parts*/
enum SettingsParts {contrast, controls, sound_fx, music };

/** Enum for different control settings parts, joystick and accelerometer*/
enum ControlsParts {joy, acc};

/** Enum for different sound setting parts*/
enum SoundParts {on, off};

/** Enum for different music setting parts*/
enum MusicParts {music_on, music_off};

/** scroll_order Struct
 * @brief Struct hold differnt settings orders
 */   
struct scroll_order_setting {
    SettingsParts  part_previous; /**< Previous settings part */
    SettingsParts  part_displayed; /**< Displayed settings part */
    SettingsParts  part_next; /**< Next settings part */
};

/** On/off sound fx Struct
 * @brief Struct hold different sound fx orders
 */   
struct on_off_order {
    SoundParts part_next; /**< Next onoff part */
    SoundParts part_displayed; /**< Displayed onoff part */
};

/** On/off music Struct
 * @brief Struct hold differnt music orders
 */   
struct music_on_off_order {
    MusicParts part_next; /**< Next onoff part */
    MusicParts part_displayed; /**< Displayed onoff part */
};

/** Controll_order Struct
 * @brief Struct hold differnt controls orders
 */   
struct control_order {
    ControlsParts part_next; /**< Next controls part */
    ControlsParts part_displayed; /**< Displayed controls part */
};

/** Settings class
 * @brief Change change contrast, control method 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */      
class Settings{
    public:
        /** Constructor */
        Settings();
        
        /** Destructor */
        ~Settings();
        
        /** Initialises Settings*/
        void init();
        
        /** Draws the settings screen
         * @param lcd @details N5110 object
         * @param pot_read @details Potentiometer read value
         */
        void display_settings_screen(N5110 &lcd, float pot_read);
        
        /** Changes the current displayed setting part
         * @param pressed @details Buttom A pressed 
         */
        void change_setting(bool pressed);
        
        /** Scrolls through the different settings parts
         * @param d_ @details Direction of joystick
         */
        void settings_scroll(Direction d_);
        
    // Accessors and mutators --------------------------------------------------
        
        /** Return the control method that set-in setting menu  
         * @return control_method_
         */
        ControlsParts get_control_method();
        
        /** Return the sound method that set-in setting menu  
         * @return sound_method_
         */
        SoundParts get_sound_method();
        
        /** Return the music method that set-in setting menu  
         * @return music_method_
         */
        MusicParts get_music_method();
        
        /** Return the setting part that is displayed 
         * @return get_displayed_settings_part_
         */
        SettingsParts get_displayed_settings_part();
        
    private:   
       
    // Varibles ---------------------------------------------------------------- 
        
        /** LCD contrast */
        int lcd_contrast; 
            
        /** Control method of the spaceship */
        ControlsParts control_method_; 
       
        /** Controls whether sound fx are on or not */
        SoundParts sound_method_;
        
        /** Controls whether music are on or not */
        MusicParts music_method_;
        
        /** The part of setting that is displayed */ 
        SettingsParts displayed_settings_part_;
    
};
#endif
