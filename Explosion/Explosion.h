#ifndef EXPLOSION_H
#define EXPLOSION_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "Position.h"

/** Animation Struct
 * @brief Struct to draw explosion animation 
 */   
struct Animation{
    bool draw_circle_one; /**< Bool to draw circle one */
    bool draw_circle_two; /**< Bool to draw circle two */
    FillType circle_one; /**< Fill type of circle one */
    FillType circle_two; /**< Fill type of circle two */
};

/** Explosion class
 * @brief Draws explosion animation 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */      
class Explosion: public Position {
    public:
        /** Constructor */
        Explosion();
        
        /** Destructor */
        ~Explosion();
        
        /** Initialises explosion 
         * @param destroyed_position @details Vector2D of destroyed xy pos
         */
        void init(Vector2D destroyed_position);
    
        /** Draws the explosion 
         * @param lcd @details N5110 object
         */
        void draw_explosion(N5110 &lcd);
    
    // Accessors and mutators --------------------------------------------------
        
        /** Gets the explosion radius
         * @returns explosion_radius_
         */
        int get_explosion_radius();
        
    private:   
       
    // Variables --------------------------------------------------------------- 
        
        /** Explosion circle radius */ 
        int explosion_radius_;
        
        /** FSM counter for state in FSM */ 
        int fsm_counter_;
        
        /** Draw cunter  */
        int draw_counter;
};
 
#endif
