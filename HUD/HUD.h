#ifndef HUD_H
#define HUD_H
 
// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"

/** HUD class
 * @brief Draws the HUD(Heads Up Display) on the lcd
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */ 
class HUD {
    public:
        /** Constructor */
         HUD();
        
        /** Destructor */
        ~HUD();
        
        /** Draws the HUD 
         * @param lcd @details N5110 object
         * @param spaceship_lives @details number of lives of spaceship
         * @param points @details number of points you have
         * @param smart_bomb_counter @details number of smart bombs left
         */
        void draw_HUD(N5110 &lcd,int spaceship_lives, int points,  
        int smart_bomb_counter);
        
    private:
    // Function prototypes -----------------------------------------------------
    
        /** Draws the lives sprites depending on number of lives left
         * @param lcd @details N5110 object
         * @param spaceship_lives @details number of lives of spaceship
         */
        void draw_lives(N5110 &lcd, int spaceship_lives);
        
        /** Draws the smart bomb sprites depending on number of bombs left
         * @param lcd @details N5110 object
         * @param smart_bomb_counter @details number of smart bombs left
         */
        void draw_smart_bombs(N5110 &lcd, int smart_bomb_counter);    
        
        
        
};
 
#endif
