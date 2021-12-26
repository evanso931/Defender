#ifndef MENU_H
#define MENU_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Sprites.h"

/** Enum for defend menu parts*/
enum MenuParts {play, settings, saved_games, high_score, main_menu};

/** scroll_orderStruct
 * @brief Struct hold differnt menu orders
 */   
struct scroll_order {
    MenuParts part_previous; /**< Previous menu part */
    MenuParts part_displayed; /**< Displayed menu part */
    MenuParts part_next; /**< Next Menu part */
};

/** Explosion class
 * @brief Selects and draws different menu parts 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */      
class Menu{
    public:
        /** Constructor */
        Menu();
        
        /** Destructor */
        ~Menu();
        
        /** Initialises Menu*/
        void init();
      
        /** Sets the current menu part to the displayed when a is pressed
         * @param pressed @details Bottom A pressed 
         */
        void select_part(bool pressed);
        
        /** Draws the name of the part that is in the middle
         * @param lcd @details N5110 object
         */
        void draw_part(N5110 &lcd);
        
        /** Scrolls through the different menu parts
         * @param d_ @details Direction of joystick
         */
        void menu_scroll(Direction d_);
        
    // Accessors and mutators --------------------------------------------------
    
        /** Gets the current menu part that is selected
         * @return current_menu_part_
         */
        MenuParts get_current_menu_part();
           
    private: 
    // Function prototypes -----------------------------------------------------  
       
        /** Prints the tile screen by printing different letter sprites 
         * @param lcd @details N5110 object
         */ 
         void title_screen(N5110 &lcd);
       
        /** Time-triggered interrupt to flash title screen */
        void title_screen_isr();
       
    // Variables ---------------------------------------------------------------- 
    
        /** The part of the menu that is displayed */ 
        MenuParts displayed_menu_part_;
        
        /** The part of the menu that is currently selected and in */ 
        MenuParts current_menu_part_;
        
        /** Volatile flag for ISR */
        volatile bool title_screen_flag_;
        
        /** Define Ticker object for flash title screen */
        Ticker ticker_title; 
};
#endif
