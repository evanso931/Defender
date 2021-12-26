#ifndef MAP_H
#define MAP_H
 
// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "Position.h"

/** Map class
 * @brief Draws 
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 */
class Map: private Position{
    public:
        /** Constructor */
        Map();
        
        /** Destructor */
        ~Map();
        
        /** Initialises Spaceship 
         * @param pad @details : Gamepad object
         */
        void init(Gamepad &pad); 
        
        /** Draws map out of combination of random triangle hight and random 
         * length lines so map is different each new game and loops round at ends
         * @param lcd @details N5110 object and 
         * @param d_ @details Direction variable for move map
         */
        void draw_map(N5110 &lcd, Direction d_);
    
    // Accessors and mutators --------------------------------------------------
        
        /** Gets x postion of the map for testing 
         * @return maps x postion 
         */
        int get_position_x_map();
        
        /** Gets map length
         * @return map_length_ 
         */
        int get_length_map();
       
    private:
    // Functions prototypes ----------------------------------------------------
    
        /** Draws a triangle from position with specified hight wich represents 
         * a mountain of the map
         * @param lcd @details N5110 object 
         * @param triangle_height @details random hight of triangle produced
         */
        void draw_triangle(N5110 &lcd, int triangle_height);
        
        /** Draws a horizontal line with specified length to represent flat land 
         * on map
         * @param lcd @details N5110 object
         * @param line_length @details length of horozontal line
         */
        void draw_line(N5110 &lcd, int line_length);
        
        /** Duplicates the first part of the map to fill the gap when the map 
         * loops round forwards
         * @ param lcd @details N5110 object
         */
        void check_duplicates_map_forward(N5110 &lcd);
    
        /** Duplicates the last part of the map to fill the gap when the map 
         * loops round backwards
         * @ param lcd @details  N5110 object
         */
        void check_duplicates_map_backwards(N5110 &lcd);
        
        /** Fills random lengths and hights arrays and fills arrays with random 
         * integers so same random map is drawn each frame
         * @param Pad @details : Gampad adc object used to generate seed 
         */
        void fill_random_arrays(Gamepad &pad);
        
        /** Calulates the map movement depeding on spaceship positions and 
         * joystick input 
         * @param d_ @details Direction object of joystick
         * @retrun inger @details Move map value for map draw function 
         */
        int calc_map_movement(Direction d_);
    
    // Variables ---------------------------------------------------------------
        
        /** Store random heights triangles */
        int rand_heights_[12]; 
        
        /** Store lengths of lines */
        int rand_lengths_[12]; 
        
        /** Store the final element used in the random array befor the break
         * in draw map 
         */
        int final_random_element_used_; 
        
        /** Required to reset the map to it's origonal postion at end of each  
         * frame, as draw line and triangle functions change position_x_map_ 
         */  
        int reset_position_x_map_to_origonal_;  
          
        /** Length of map */
        int map_length_; 
};
 
#endif
