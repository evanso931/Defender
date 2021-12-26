#ifndef PLAYENGINE_H
#define PLAYENGINE_H

// Included Headers ------------------------------------------------------------
#include "Spaceship.h"
#include "Map.h"
#include "Weapons.h"
#include "Alien.h"
#include "Explosion.h"
#include "People.h"
#include "Settings.h"
#include <vector> 

/** PlayEngine Class
 * @brief Runs the interactions between the different classes in the playable 
 * part of the game. Also to break down the size of game engine class. Means I 
 * can define the functions publicly to test them then inherit them privately.
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */      
class PlayEngine {
    public:
        
    // Function prototypes -----------------------------------------------------
    
    // Spaceship Control      
        /** Gets joystick direction from gamepad and stores it in d_ */
        void read_joystick_direction();
        
        /** Gets the pitch and roll of the gamepad and calculates d_ */
        void read_accelerometer_direction(float roll, float pitch);
        
        /** Turns on specific leds depending on how many lives left */
        void spaceship_lives_leds();
        
    // Weapon Control      
        /** Creates weapons object if button A is pressed and stores in vector*/
        void create_weapons_bullets();
        
        /** Creates smart bomb if button B is pressed */
        void create_weapons_smart_bomb();
       
        /** Draws each bullet object and deleted object after set movement 
         * distance
         */
        void draw_bullets();
        
    // Alien Control    
        /** Spawns aliens in random position of the screen*/
        void spawn_aliens();
        
        /** Creates alien object and stores in vector*/
        void create_alien();
        
        /** Checks for alien people collision and sets abduction movements
         * @param i @details iterator from draw_alien for loop
         */
        void check_alien_people_collision(int i);
        
        /** Gets alien to fire bullets randomly towards spaceship
         * @param i @details iterator from draw_alien for loop
         */
        void alliens_fire_bullets(int i);
        
        /**Deletes bullet and alien if collision detected and draws explosion
         * @param i @details iterator from draw_alien for loop
         */
        void delete_aliens(int i);
        
        /** Draws each alien object and deletes both objects if collision 
         * detected 
         */
        void draw_aliens();
        
    // Explosion Control   
        /** Creates bullet object if button A is pressed and stores in vector */
        void create_explosion(Vector2D destroyed_position);
       
        /** Draws each explosion object if collision detected */
        void draw_explosions();
        
    // People Control 
        /** Spawns people in random places at bottom of screen */
        void spawn_people();
        
        /** Spawns people in random position at bottom of the screen*/
        void create_people();
        
        /** Draws each people object */
        void draw_people();
   
    // Map Control      
        /** Resets map after set time so spaceship explosion animation shows */
        void reset_map_timer();
        
        /** Resets the map after spaceship death and timer has ended */
        void reset_map();
    
    // Variables --------------------------------------------------------------- 
     
    // Spaceship Control  
        /** Define points*/
        int points_; 
        
        /** Define direction d of joystick*/
        Direction d_; 
        
        /** Flag for if spaceship is destroyed*/
        bool spaceship_destroyed_;
        
        /** Number of spaceship lives remaining*/
        int spaceship_lives_;
        
    // Weapon Control   
        /** Counter for smart bomb timer*/
        int smart_bomb_timer_;
        
        /** Counter for bullet timer*/
        int bullet_timer_;
        
        /** Counter for how smart bombs left*/
        int smart_bomb_counter_;
    
    // Alien Control     
        /** Counter for spawning aliens*/
        int spawn_alien_counter_;
        
        /** Number of aliens on the screen at a time*/
        int alien_number_;
        
        /** Multiplier to increase number of alien as time goes on */
        int spawn_time_multipler_;
     
    // Map Control     
        /** Counter to reset map after set amount of frames*/
        int reset_map_counter_;
        
    // FX sound 
        /** Hold on or off depending if sound fx are set on or off */
        SoundParts sound_fx_;
            
    // Vectors -----------------------------------------------------------------  
        
        /** Vector to store each new bullet object*/
        std::vector<Weapons> bullet_vector;
        
        /** Vector to store each alien bullet object*/
        std::vector<Weapons> alien_bullet_vector;
        
        /** Vector to store each new alien object*/
        std::vector<Alien> alien_vector;
        
        /** Vector to store each new explosion object*/
        std::vector<Explosion> explosion_vector;
        
        /** Vector to store each new people object*/
        std::vector<People> people_vector; 
        
    // Objects -----------------------------------------------------------------
        
        /** Define Gamepad object */ 
        Gamepad pad;
        
        /** Define LCD object */
        N5110 lcd;
        
        /** Define Spaceship object */
        Spaceship spaceship;
        
        /** Define Map object */
        Map map; 
        
        /** Define Weapons object */
        Weapons weapons;   
};

#endif
