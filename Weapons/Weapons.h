#ifndef WEAPONS_H
#define WEAPONS_H
 
// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "RandomMovement.h"

/** Weapons class
 * @brief Draws and moves weapons 
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 */
class Weapons: public RandomMovement {
    public:
        /** Constructor */
        Weapons();
        
        /** Destructor */
        ~Weapons();
        
        /** Initialises Weapons 
         * @param sprite_pos @details vector 2D of sprite xy position 
         * @param sprite_direction @details sprite direction bool, 
         * true = E, false = W
         * @param bullet_type @details true = spaceship, false = alien
         */
        void init(Vector2D sprite_pos, bool sprite_direction,bool bullet_type);
        
        /** Draws the bullet and moves it in x direction each frame
         * @param lcd @details N5110 object
         */
        void draw_bullet(N5110 &lcd);
        
         /** Draws the aliens bullet and moves it in xy direction each frame
         * @param lcd @details N5110 object
         * @param d_ @details : Direction object of joystick
         */
        void draw_alien_bullet(N5110 &lcd, Direction d_);
        
        /** Tuns lcd back light on and off 
         * @param lcd @details N5110 object
         */
        void smart_bomb(N5110 &lcd);
         
    // Accessors and mutators --------------------------------------------------
        
        /** Sets the xy position of the bullet
         * @param pos @details vector 2D of bullet xy position 
         */
        void set_pos_one(Vector2D pos);
        
        /** Gets the bullet distance counter 
         * @return bullet_distance_counter
         */
        int get_bullet_delete_counter();
        
        /** Gets the bullet direction
         * @return bullet_direction_
         */
        bool get_direction();
        
        /** Sets the bullets movement direction when it is fired
         * @param spaceship_sprite_direction_ @details sprite direction bool, 
         * true = E, false = W
         */
        void set_direction(bool sprite_direction_);
        
    private:
    // Function prototypes -----------------------------------------------------
    
        /** Calculates bullets start position
         * @param spaceship_pos @details x and y postion of spaceship
         * @param spaceship_sprite_direction_ @details sprite direction bool, 
         * true = E, false = W
         */
        void calc_bullets_start_pos(Vector2D spaceship_pos, 
        bool spaceship_sprite_direction_);
        
        /** Calculates alien bullets start position
         * @param alien_pos @details x and y postion of spaceship
         * @param alien_sprite_direction_ @details sprite direction bool, 
         * true = E, false = W
         */
        void calc_alien_bullets_start_pos(Vector2D alien_pos, 
        bool alien_sprite_direction_);
    
    // Variables ---------------------------------------------------------------
        
        /** Counter to deleted bullet */
        int bullet_delete_counter_; 
};
 
#endif
