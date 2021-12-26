#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "Position.h"
#include "Weapons.h"

/** CheckCollision class
* @brief Check Collision perant class
* @author Benjamin Evans, University of Leeds
* @date May 2020
*/         
class CheckCollision: virtual public Position{    
    public: 
    // Function prototypes -----------------------------------------------------
    
        /** Checks if bullet collides with a sprite
         * @param bullet @details Weapons object
         */
        bool check_collision(Weapons bullet); 
        
    protected:    
    // Variables ---------------------------------------------------------------
        
        /** Length of sprite in x direction */
        int sprite_x_length; 
        
        /** Length of sprite in y direction */
        int sprite_y_length; 
        
};
 
#endif