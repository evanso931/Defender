#ifndef RANDOMMOVEMENT_H
#define RANDOMMOVEMENT_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "Position.h"

/** Random Movement class
* @brief Random Movement parent class
* @author Benjamin Evans, University of Leeds
* @date May 2020
*/         
class RandomMovement: virtual public Position{    
    protected: 
    // Function prototypes -----------------------------------------------------
    
        /** Changes the x and y positions of the sprite object depending on the  
         * movement direction 
         * @param x_change @details number to change sprite x position by
         * @param y_change @detials number to change sprite y position by
         */
        void set_sprite_direction(int x_change,int y_change);
        
        /** Generates the random move direction and length for the sprite */
        void set_random_move();
        
        /** Gets the movement direction of the sprite */
        void move_direction();
        
        /** Calculates the sprite movement depending on spaceship positions and 
         * joystick input 
         * @param d_ @details : Direction object of joystick
         * @return integer @details move alien value for alien draw function 
         */
        int calc_sprite_movement(Direction d_);
        
    // Variables ---------------------------------------------------------------
        
        /** Sprite random move counter */
        int random_move_counter_;
         
        /** Random direction variable */
        int random_direction_;  
};
 
#endif
