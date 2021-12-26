#include "Alien.h"

// Constant Definitions
#define SPRITE_X_LENGTH 7
#define SPRITE_Y_LENGTH 6

const int k_alien_sprite[6][7] = {
    { 0,0,1,1,1,1,0,},
    { 0,1,0,1,1,0,1,},
    { 0,1,0,1,1,0,1,},
    { 0,0,1,1,1,1,0,},
    { 0,1,0,1,0,1,0,},
    { 1,0,0,1,0,0,1,},
};

Alien::Alien() {

}
 
Alien::~Alien() {
    
}

void Alien::init(Gamepad &pad, int position_x_start, int position_y_start) {
    // Assign values to variables
    sprite_x_length = SPRITE_X_LENGTH;
    sprite_y_length = SPRITE_Y_LENGTH;
    position_x_ = position_x_start;
    position_y_ = position_y_start;
    alien_move_counter_ = 0;
    srand(pad.read_adc()*64000);
    random_move_counter_ = 0;
    random_direction_ = 0;
    direction_ = rand()%2;
    collision_people_element_ = -1; 
    track_flag_ = false;
}
 
void Alien::draw_alien(N5110 &lcd,Vector2D spaceship_pos,Direction d_, 
int map_length_, int position_x_map_, bool alien_collision) {
    // Moves alien with map movement 
    position_x_ += calc_sprite_movement(d_);
    
    // Moves alien at half speed of spaceship 
    if (alien_move_counter_%2 == 0) {
        
        // Alien tracks spaceship if abducted people
        if (track_flag_) {
            move_hunt_mode(spaceship_pos);
            
            // printf("tack_flag =  %d\n", track_flag_);
            // printf("pos_x = %d : pos y = %d\n",position_x_, position_y_);
            
        // If no abduction alien moves randomly 
        }else if (random_move_counter_ == 0 || alien_collision) {
            
            // Move alien to top of screen if a collision with person
            if (alien_collision) {
                random_direction_ = 6;
                  
                random_move_counter_ = 42;
                alien_collision = false;
            }else{
                set_random_move();
            }
            
        }
        // Stop alien going of map
        off_screen_x_y_checker(map_length_, position_x_map_); 
        
        // Move alien not tracking spaceship move randomly 
        if (!track_flag_) {
            move_direction();  
        }
        
        
        
        random_move_counter_ --; 
        alien_fire_counter_++;  
    }
    alien_move_counter_++;
    lcd.drawSprite(position_x_, position_y_, SPRITE_Y_LENGTH, SPRITE_X_LENGTH, 
    (int*)k_alien_sprite);
}

void Alien::off_screen_x_y_checker(int map_length_, int position_x_map_) {
    // Checks y position of alien and then alters alien movement direction if at 
    // edge  of map
    if (position_y_ < 9) {
        // Sets alien direction to one that increases y value 
        if (direction_) {
            random_direction_ = 1;
        }else{
            random_direction_ = 4;
        }
        
    }else if (position_y_ > 42) {
        // Sets alien direction to one that decrees y value 
        if (direction_) {
            random_direction_ = 2;
        }else{
            random_direction_ = 5;
        }
    } 
    
    // Loops the alien round if it reaches the end of the map 
    if (position_x_ <= (84 - map_length_)) {
       position_x_ += map_length_; 
    }else if (position_x_ >= map_length_) {
        position_x_ -= map_length_ + 10;
    }   
    
    // Debug and check variables when defined  
    #ifdef CALCULATE_ALIEN_MOVEMENT_DEBUG   
        printf("\nposition_x_map_ =  %d\n", position_x_map_);
        printf("map_length_  =  %d\n", map_length_ );
        printf("map_length_ + position_x_map_ =  %d\n", map_length_ + 
        position_x_map_);
    #endif
}   

void Alien::move_hunt_mode(Vector2D spaceship_pos) {
    if (spaceship_pos.x < position_x_) {
        position_x_ --;
    }else if (spaceship_pos.x > position_x_) {
        position_x_ ++;
    }
    
    if (spaceship_pos.y > position_y_) {
        position_y_ ++;
    }else if (spaceship_pos.y < position_y_) {
        position_y_ --;
    }
}

int Alien::get_alien_fire_counter() {
    return alien_move_counter_;
} 

void Alien::set_alien_x_pos(int position_x) {
    position_x_ = position_x;
}

void Alien::set_collision_people_element(int people_element) {
    collision_people_element_ = people_element;
}

int Alien::get_collision_people_element() {
    return collision_people_element_;
} 

void Alien::set_track_flag(bool track_flag) {
    track_flag_ = track_flag;
}

bool Alien::get_track_flag() {
    return track_flag_;
}
