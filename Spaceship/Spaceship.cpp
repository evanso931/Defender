#include "Spaceship.h"

// Constant Definitions
#define SPRITE_X_LENGTH 13
#define SPRITE_Y_LENGTH 4
#define STARTING_X_POS 36
#define STARTING_Y_POS 22
#define OFF_SCREEN_Y_ONE 9
#define OFF_SCREEN_Y_TWO 44
#define OFF_SCREEN_X_ONE 56
#define OFF_SCREEN_X_TWO 15

 
const int k_spaceship_sprite_E[SPRITE_Y_LENGTH][SPRITE_X_LENGTH] = {
    { 1,1,1,1,1,1,0,0,0,0,0,0,0 },
    { 0,1,1,1,1,1,1,1,1,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 0,0,1,1,1,1,1,0,0,0,0,0,0 },
};

const int k_spaceship_sprite_W[SPRITE_Y_LENGTH][SPRITE_X_LENGTH] = {
    { 0,0,0,0,0,0,0,1,1,1,1,1,1 },
    { 0,0,0,0,1,1,1,1,1,1,1,1,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 0,0,0,0,0,0,1,1,1,1,1,0,0 },
};
 
Spaceship::Spaceship() {
    
}
 
Spaceship::~Spaceship() {
    
}
 
void Spaceship::init() {
    // Assign values to variables
    CheckCollision::sprite_x_length = SPRITE_X_LENGTH;
    CheckCollision::sprite_y_length = SPRITE_Y_LENGTH;
    CheckAlienCollision::sprite_x_length = SPRITE_X_LENGTH;
    CheckAlienCollision::sprite_y_length = SPRITE_Y_LENGTH;
    position_x_ = STARTING_X_POS;
    position_y_ = STARTING_Y_POS;
    
    // Sets original spaceship direction to facing East
    direction_ = true;
}
 
void Spaceship::draw(N5110 &lcd) {
    off_screen_x_y_checker();
    
    // Draws spaceships at defined x and y positions with different sprite 
    // Direction depending on joystick position 
    if (direction_) {
        lcd.drawSprite(position_x_, position_y_, SPRITE_Y_LENGTH, 
        SPRITE_X_LENGTH,(int*)k_spaceship_sprite_E);
    }else if (!direction_) {
    lcd.drawSprite(position_x_, position_y_, SPRITE_Y_LENGTH, SPRITE_X_LENGTH, 
    (int*)k_spaceship_sprite_W);
    }
    
    // printf("Spaceship Y postion = %d\n",position_y_);
}

void Spaceship::off_screen_x_y_checker() {
    // Checks y position of spaceship and then alters y position if off map
    if (position_y_ < OFF_SCREEN_Y_ONE) {
        position_y_ = OFF_SCREEN_Y_ONE;
    }else if (position_y_ > OFF_SCREEN_Y_TWO) {
        position_y_ = OFF_SCREEN_Y_TWO;
    }  
    
    // Checks x position of spaceship and alters x position 
    if (position_x_ > OFF_SCREEN_X_ONE) {
        position_x_ = OFF_SCREEN_X_ONE;
    }else if (position_x_ < OFF_SCREEN_X_TWO) {
        position_x_ = OFF_SCREEN_X_TWO;
    }
}   
 
void Spaceship::movement(Direction d_) {
    // Switch statement to change spaceship parameters depending on 
    // Joystick direction
    switch (d_) {
    case CENTRE: set_spaceship_peram(0, 0, false , false); break;
    case N: set_spaceship_peram(0, -1, false , false); break;
    case NE: set_spaceship_peram(-1, -1, true, true); break;
    case E: set_spaceship_peram(-1, 0, true, true); break;
    case SE: set_spaceship_peram(-1, 1, true, true); break;
    case S: set_spaceship_peram(0, 1, false, false); break;
    case SW: set_spaceship_peram(1, 1, true, false); break;
    case W: set_spaceship_peram(1, 0, true, false); break;
    case NW: set_spaceship_peram(1, -1, true, false); break;
    }
    
    // printf("y= %d\n", position_y_);
}

void Spaceship::set_spaceship_peram(int x_change,int y_change, 
bool sprite_change, bool sprite_param) {
    position_x_ += x_change;
    position_y_ += y_change;
    
    // Only changes sprite direction when joystick direction isn't N or S
    if (sprite_change) {
        direction_ = sprite_param;
    }
}

bool Spaceship::get_spaceship_sprite_direction() {
    return direction_;
}
