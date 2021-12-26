#include "Explosion.h"

// Defining animation states for explosion FSM
Animation animation_fsm[2] = {
    {false, true, FILL_WHITE, FILL_BLACK},
    {true, false, FILL_TRANSPARENT, FILL_WHITE},   
};

Explosion::Explosion() {
     
}
 
Explosion::~Explosion() { 
 
}

void Explosion::init(Vector2D destroyed_position) {
    // Assign values to variables
    position_x_ = destroyed_position.x + 3; 
    position_y_ = destroyed_position.y + 3; 
    fsm_counter_ = 0;  
    explosion_radius_ = 4;
    draw_counter = 0;
}

void Explosion::draw_explosion(N5110 &lcd) {
    // Draws each explosion frame depending on state 
    // Draw circle one
    if (animation_fsm[fsm_counter_].draw_circle_one) {
        lcd.drawCircle(position_x_, position_y_,explosion_radius_ + 1, 
        animation_fsm[fsm_counter_].circle_one);
    }
    // Draw circle two
    if (animation_fsm[fsm_counter_].draw_circle_two) {
        lcd.drawCircle(position_x_, position_y_,(explosion_radius_ - 2), 
        animation_fsm[fsm_counter_].circle_two);
    }
    
    // Slows down animation change time, so explosion animation is longer
    if (draw_counter%2 == 0) {
        explosion_radius_++;
        fsm_counter_ = !fsm_counter_;
    }
    draw_counter++;
}

int Explosion::get_explosion_radius() {
    return explosion_radius_;
}
