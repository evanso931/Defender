#ifndef PEOPLE_H
#define PEOPLE_H
 
// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "RandomMovement.h"
#include "CheckAlienCollision.h"

/** People class
 * @brief Draws people and moves them if collected by aliens
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */ 
class People: public RandomMovement, public CheckAlienCollision {
    public:
        /** Constructor */
        People();
        
        /** Destructor */
        ~People();
        
        /** Initalises Alien 
         * @param position_x_start @details Random x start pos of people
         * @param pad @detials Gamepad object
         */
        void init(Gamepad &pad, int position_x_start);
        
        /** Draws the people
         * @param lcd @details N5110 object
         * @param d_ @details joystick direction 
         * @param map_length @details length of the map
         * @param position_x_map_ @details x posisition that map starts 
         */
        void draw_people(N5110 &lcd, Direction d_, int map_length_, 
        int position_x_map_);
    
    // Accessors and mutators --------------------------------------------------
        
        /** Gets alien collision flag
         * @return alien_collision_flag
         */
        bool get_alien_collision_flag();
        
    private:
    // Function prototypes -----------------------------------------------------
        
        /** Stops the people from moving off the edge of the map and moves 
         * people if the map loops
         * @param map_length_@details : length of the map  
         * @param position_x_map_ @detials : the drawing start posisiton of the 
         * map 
         */
        void off_screen_x_y_checker(int map_length_, int position_x_map_);
        
        /** Move alien to top of screen if collision with alien */
        void collision_with_alien();
        
    // Variables ---------------------------------------------------------------
        
        /** People movement counter */
        int people_move_counter_; 
        
};
 
#endif