#include "Weapons.h"

Weapons::Weapons() {
    
}
 
Weapons::~Weapons() {
    
}
 
void Weapons::init(Vector2D sprite_pos, bool sprite_direction, 
bool bullet_type) {
    // Bullet for alien or for spaceship 
    set_direction(sprite_direction);
    if (bullet_type) {
        calc_bullets_start_pos(sprite_pos, sprite_direction);
    }else{
        calc_alien_bullets_start_pos(sprite_pos, sprite_direction);
    }
    bullet_delete_counter_ = 0;
}

void Weapons::smart_bomb(N5110 &lcd) {
    // Turn backlight off and on twice
    lcd.backLightOff();
    wait(0.02);
    lcd.backLightOn();
    wait(0.02);
    lcd.backLightOff();
    wait(0.02);
    lcd.backLightOn();
}


void Weapons::calc_bullets_start_pos(Vector2D spaceship_pos, 
bool spaceship_sprite_direction_) {
    // Sets start position of bullet to spaceships nose
    if (spaceship_sprite_direction_) {
        position_x_ = spaceship_pos.x + 13;
        position_y_ = spaceship_pos.y + 2;
    }else{
        position_x_ = spaceship_pos.x;
        position_y_ = spaceship_pos.y + 2;
    }
    #ifdef POSITION_BULLET_DEBUG   
        printf("X = %d\n", position_x_);       
        printf("Y = %d\n", position_y_);
    #endif 
}

void Weapons::draw_bullet(N5110 &lcd) {
    // Draws then moves the bullet position
    lcd.drawLine(position_x_, position_y_, position_x_+1, position_y_, 1);
    if (direction_) {
        position_x_ += 3;
    }else{
        position_x_ -= 3;
    }
  
    // Increments counter
    bullet_delete_counter_++;
}

void Weapons::calc_alien_bullets_start_pos(Vector2D alien_pos, 
bool alien_sprite_direction_) {
    // Sets start position of bullet to middle of alien
    position_x_ = alien_pos.x + 3;
    position_y_ = alien_pos.y + 3;
    
    // Gets a random direction for the bullet to travel in
    set_random_move();
}

void Weapons::draw_alien_bullet(N5110 &lcd,Direction d_) {
    // Draws then moves the bullet position
    lcd.drawLine(position_x_, position_y_, position_x_+1, position_y_, 1);
    
    // Moves bullet in random direction and accommodates for spaceship movement
    move_direction();
    position_x_ += calc_sprite_movement(d_);
    
    // Increments counter
    bullet_delete_counter_++;
}

void Weapons::set_pos_one(Vector2D pos) {
    position_x_ = pos.x;
    position_y_ = pos.y;
}

void Weapons::set_direction(bool sprite_direction) {
    direction_ = sprite_direction;   
}

int Weapons::get_bullet_delete_counter() {
    return bullet_delete_counter_; 
}

bool Weapons::get_direction() {
    return direction_;   
}