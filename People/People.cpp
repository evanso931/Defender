#include "People.h"

// Constant Definitions
#define SPRITE_X_LENGTH 4
#define SPRITE_Y_LENGTH 5
#define STARTING_Y_POS 42

const int k_people_sprite[SPRITE_Y_LENGTH][SPRITE_X_LENGTH] = {
    { 0,1,1,0,},
    { 1,1,1,1,},
    { 1,1,1,1,},
    { 0,1,1,0,},
    { 0,1,1,0,},
};

People::People() {

}
 
People::~People() {
    
}

void People::init(Gamepad &pad, int position_x_start) {
    // Define variables
    sprite_x_length = SPRITE_X_LENGTH;
    sprite_y_length = SPRITE_Y_LENGTH;
    position_x_ = position_x_start;
    position_y_ = STARTING_Y_POS;
    alien_collision_flag = false;
    people_move_counter_ = 0;
    random_move_counter_ = 0;
}

void People::draw_people(N5110 &lcd, Direction d_, int map_length_, 
int position_x_map_) {
    position_x_ += calc_sprite_movement(d_);
    lcd.drawSprite(position_x_, position_y_, SPRITE_Y_LENGTH, SPRITE_X_LENGTH, 
    (int*)k_people_sprite);
    off_screen_x_y_checker(map_length_, position_x_map_);
    
    // Move alien to top of screen if collision with alien
    collision_with_alien();
    
    people_move_counter_++;
} 

void People::collision_with_alien() {
if(alien_collision_flag && !alien_track) {
    // People move on there own but at half speed of spaceship 
    if (people_move_counter_%2 == 0) {
        if (random_move_counter_ == 0) {
            // Move alien to top of screen
            random_direction_ = 6;   
            random_move_counter_ = 43;
        }
        
    // Move people
    move_direction();
    random_move_counter_ --;     
    }
}    
}

void People::off_screen_x_y_checker(int map_length_, int position_x_map_) {
    // Loops the people round if it reaches the end of the map 
    if(position_x_ <= (84 - map_length_)) {
       position_x_ += map_length_; 
    }else if (position_x_ >= map_length_) {
        position_x_ -= map_length_ + 10;
    }   
}   

bool People::get_alien_collision_flag() {
    return alien_collision_flag;
}
