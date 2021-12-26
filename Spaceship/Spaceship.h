#ifndef SPACESHIP_H
#define SPACESHIP_H
 
// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "CheckCollision.h"
#include "CheckAlienCollision.h"

/** Spaceship class
 * @brief Draws and moves spaceship
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 */
class Spaceship: public CheckAlienCollision, public CheckCollision {
    public:
        /** Constructor */
        Spaceship();
        
        /** Destructor */
        ~Spaceship();
        
        /** Initalises Spaceship */
        void init();
        
        /** Draws Spaceship 
         * @param lcd @details N5110 object
         */
        void draw(N5110 &lcd);
        
        /** Move Spaceship around the screen depedning on joystick input
         * @param d_ @details Direction of joystick
         */
        void movement(Direction d_);   
        
    // Accessors and mutators --------------------------------------------------
        
        /** Gets sprtie directon if spaceship 
         * @return spaceship_sprite_direction_ @details true = east, 
         * false = west
         */
        bool get_spaceship_sprite_direction(); 
        
    private:
    // Function prototypes -----------------------------------------------------
    
        /** Sets the x, y position and sprite direction of the spaceship for
         * movement function  
         * @peram x_change 
         * @peram y_change
         * @peram sprite_change
         * @peram prite_param 
         */
        void set_spaceship_peram(int x_change,int y_change, bool sprite_change, 
        bool sprite_param);
        
        /** Checks sapceship x and y position and stops spacship comming of the 
         * screen in y direction. Keeps spaceship in middle 3rd of screen in 
         * x direction 
         */
        void off_screen_x_y_checker();
};
 
#endif