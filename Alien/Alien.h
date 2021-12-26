#ifndef ALIEN_H
#define ALIEN_H
 
// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "RandomMovement.h"
#include "CheckCollision.h"

/** Alien class
 * @brief Draws and moves aliens 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */ 
class Alien: public RandomMovement, public CheckCollision {
    public:
        /** Constructor */
        Alien();
        
        /** Destructor */
        ~Alien();
        
        /** Initialises Alien 
         * @param position_x_start @details Random x start pos of alien
         * @param position_y_start @details Random y start pos of alien
         * @param pad @details Gamepad object
         */
        void init(Gamepad &pad, int position_x_start, int position_y_start);
    
        /** Draws the alien
         * @param lcd @details N5110 object
         * @param spaceship_pos @details xy spaceship position
         * @param d_ @details Direction of joystick
         * @param map_length_ @details length of map
         * @param position_x_map_ @details x position of map
         * @param alien_collision @details bool if a collision happened
         */
        void draw_alien(N5110 &lcd, Vector2D spaceship_pos, Direction d_, 
        int map_length_, int position_x_map_, bool alien_collision);
    
    // Accessors and mutators --------------------------------------------------
    
        /** Gets the counter for alien time to fire
         * @return alien_fire_counter_ 
         */
        int get_alien_fire_counter(); 
        
        /** Sets the position_x_ of alien
         * @param position_x 
         */
        void set_alien_x_pos(int position_x);
        
        /** Sets the collision_people_element number
         * @param people_element
         */
        void set_collision_people_element(int people_element);
        
         /** Gets the collision_people_element number
         * @return collision_people_element
         */
        int get_collision_people_element(); 
        
        /** Sets alien track_flag
         * @param track_flag_
         */
        void set_track_flag(bool track_flag);
        
        /** Gets alien track_flag
         * @return track_flag_
         */
        bool get_track_flag();
        
    private:
    // Function prototypes -----------------------------------------------------
       
        /** Moves the alien towards the spaceship and around the map 
         * @param spaceship_pos @details : Position of the spaceship
         */
        void move_hunt_mode(Vector2D spaceship_pos);
        
        /** Stops the alien from moving off the edge of the map and moves alien 
         * if the map loops
         * @param map_length_@details : length of the map  
         * @param position_x_map_ @detials : the drawing start posisiton of the 
         * map 
         */
        void off_screen_x_y_checker(int map_length_, int position_x_map_);
        
    // Variables ---------------------------------------------------------------
         
        /** Alien movement counter */
        int alien_move_counter_; 
        
        /** Alien fire bullet counter */
        int alien_fire_counter_; 
        
        /** People element that alien as collided with */
        int collision_people_element_;  
        
        /** Alien abducted people and now track spaceship flag */
        bool track_flag_;  
        
};
 
#endif
