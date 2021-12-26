#ifndef CHECKALIENCOLLISION_H
#define CHECKALIENCOLLISION_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "Position.h"
#include "Alien.h"

/** CheckAlienCollision class
* @brief Check Alien Collision parent class
* @author Benjamin Evans, University of Leeds
* @date May 2020
*/         
class CheckAlienCollision: virtual public Position{    
    public: 
    // Function prototypes -----------------------------------------------------
        
         /** Checks if alien collides with a sprite
         * @param alien @details Alien object
         */
        bool check_alien_collision(Alien alien);
        
    protected: 
    // Function prototypes -----------------------------------------------------
        
        /** Checks if alien collides with top right of sprite and return flag
         * @param alien @details Alien object
         * @param alien_pos @details vector2D of alien xy position
         * @return check_collision @details check collision flag 
         */
        bool check_top_right(Alien alien, Vector2D alien_pos);
        
         /** Checks if alien collides with top left of sprite and return flag
         * @param alien @details Alien object
         * @param alien_pos @details vector2D of alien xy position
         * @return check_collision @details check collision flag 
         */
        bool check_top_left(Alien alien, Vector2D alien_pos);
        
        /** Checks if alien collides with bottom right sprite and return flag
         * @param alien @details Alien object
         * @param alien_pos @details vector2D of alien xy position
         * @return check_collision @details check collision flag  
         */
        bool check_bottom_right(Alien alien, Vector2D alien_pos);
       
        /** Checks if alien collides with bottom left sprite and return flag
         * @param alien @details Alien object
         * @param alien_pos @details vector2D of alien xy position
         * @return check_collision @details check collision flag 
         */
        bool check_bottom_left(Alien alien, Vector2D alien_pos);
        
    // Variables ---------------------------------------------------------------
        
        /** Length of sprite in x direction */
        int sprite_x_length; 
        
        /** Length of sprite in y direction */
        int sprite_y_length; 
        
        /** Flag if there is is a alien collision*/
        bool alien_collision_flag;
        
         /** Flag if the alien that colided is tracking */
        bool alien_track;
};
 
#endif
