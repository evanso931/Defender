#include "RandomMovement.h"

void RandomMovement::move_direction() {
    switch (random_direction_) {
    case 0: set_sprite_direction(1, 0); break;
    case 1: set_sprite_direction(1, 1); break;
    case 2: set_sprite_direction(1, -1); break;
    case 3: set_sprite_direction(-1, 0); break;
    case 4: set_sprite_direction(-1, 1); break;
    case 5: set_sprite_direction(-1, -1); break;
    case 6: set_sprite_direction(0, -1); break;
    }
}

void RandomMovement::set_sprite_direction(int x_change,int y_change) {
    position_x_ += x_change;
    position_y_ += y_change;
}

void RandomMovement::set_random_move() {
    // Sprite only moves in one general direction
    if (direction_) {
        random_direction_ = rand() % 3;
    }else{
        random_direction_ = rand() % 3 + 3;
        // printf("\random_direction_ =  %d\n", random_direction_);
    }    
    random_move_counter_ = rand() % 10 + 20;
}

int RandomMovement::calc_sprite_movement(Direction d_) {  
    // Moves the people in opposite direction to spaceship when it's position is 
    // at min and max x positions and joystick has direction     
    if (d_ == W || d_ == NW || d_ == SW) { 
        return 2;
    }else if (d_ == E || d_ == NE || d_ == SE) { 
        return -2; 
    }else {
        return 0;
    }
}  
