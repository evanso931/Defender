#include "HUD.h"
 
const int k_spaceship_lives[6][7] = {
    { 0,1,1,0,1,1,0 },
    { 1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1 },
    { 0,1,1,1,1,1,0 },
    { 0,0,1,1,1,0,0 },
    { 0,0,0,1,0,0,0 },
};

const int k_smart_bombs[6][5] = {
    { 0,0,1,0,0 },
    { 0,1,1,1,0 },
    { 0,1,1,1,0 },
    { 0,1,1,1,0 },
    { 1,1,1,1,1 },
    { 0,1,0,1,0 },
};
 
HUD::HUD() {
    
}
 
HUD::~HUD() {
    
}

void HUD::draw_HUD(N5110 &lcd,int spaceship_lives, int points,  
int smart_bomb_counter) {
    lcd.drawLine(0, 8, 84, 8,1);
    
    // Draws points at top of screen
    char buffer[4];  
    sprintf(buffer,"%.4d",points); 
    lcd.printString(buffer,30,0);  
    
    // Draw lives and smart bombs 
    draw_lives(lcd, spaceship_lives);  
    draw_smart_bombs(lcd, smart_bomb_counter);         
}

void HUD::draw_lives(N5110 &lcd,int spaceship_lives) {
    // Draw one two or three lives 
    if (spaceship_lives >= 1) {
        lcd.drawSprite(1, 1, 6, 7, (int*)k_spaceship_lives);
    }
    if (spaceship_lives >= 2) {
        lcd.drawSprite(9, 1, 6, 7, (int*)k_spaceship_lives);
    }
    if (spaceship_lives == 3) {
        lcd.drawSprite(17, 1, 6, 7, (int*)k_spaceship_lives);
    }
}

void HUD::draw_smart_bombs(N5110 &lcd,int smart_bomb_counter) {
    // Draws each smart bomb depending on counter
    if (smart_bomb_counter >= 1) {
        lcd.drawSprite(78, 1, 6, 5, (int*)k_smart_bombs);
    }
    if (smart_bomb_counter >= 2) {
        lcd.drawSprite(72, 1, 6, 5, (int*)k_smart_bombs);
    }
    if (smart_bomb_counter >= 3) {
        lcd.drawSprite(66, 1, 6, 5, (int*)k_smart_bombs);
    }
    if (smart_bomb_counter >= 4) {
        lcd.drawSprite(60, 1, 6, 5, (int*)k_smart_bombs);
    }
}