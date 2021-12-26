#ifndef POSITION_H
#define POSITION_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "Gamepad.h"

/** Position class
* @brief Position parent class
* @author Benjamin Evans, University of Leeds
* @date May 2020
*/         
class Position { 
    public:
    // Function prototypes -----------------------------------------------------
    
        /** Gets the xy position of the sprite
         * @return position_x_
         * @return position_x_
         */
        Vector2D get_pos();
    
    protected:   
    // Variables ---------------------------------------------------------------- 
        
        /** X position on lcd */
        int position_x_; 
        
        /** Y position on lcd */     
        int position_y_; 
        
        /** Movement direction 
         * @note true = East, false = West 
         */
        bool direction_; 
};
 
#endif 
