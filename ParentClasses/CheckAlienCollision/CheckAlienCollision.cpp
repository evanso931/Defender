#include "CheckAlienCollision.h"

bool CheckAlienCollision::check_alien_collision(Alien alien) {
    bool collision = false; 
    Vector2D alien_pos = alien.get_pos();
    
    // Checks collision of alien and sprite
    if (check_top_right(alien, alien_pos)) {
        collision = true;
    }else if (check_top_left(alien, alien_pos)) {
        collision = true;
    }else if (check_bottom_left(alien, alien_pos)) {
        collision = true;
    }else if (check_bottom_left(alien, alien_pos)) {
        collision = true;
    }
    alien_track = alien.get_track_flag();
    return collision;
}

bool CheckAlienCollision::check_top_left(Alien alien, Vector2D alien_pos) {
    bool check_collision = false;
    
    // Checks collision of top left corner of alien with sprite       
    if (alien_pos.x >= position_x_ &&
    alien_pos.x <= (position_x_ + sprite_x_length) && 
    position_y_ <= alien_pos.y && 
    alien_pos.y <= (position_y_ + sprite_y_length)) {
        check_collision = true;
        alien_collision_flag = true;
    }
    
    return check_collision;
}

bool CheckAlienCollision::check_top_right(Alien alien, Vector2D alien_pos) {
    bool check_collision = false;
      
    // Checks collision of top right corner of alien with sprite  
    if ((alien_pos.x + 7) >= position_x_ &&
    (alien_pos.x + 7) <= (position_x_ + sprite_x_length) && 
    position_y_ <= alien_pos.y && 
    alien_pos.y <= (position_y_ + sprite_y_length)) {
        check_collision = true;
        alien_collision_flag = true;
    }
    
    return check_collision;
}

bool CheckAlienCollision::check_bottom_left(Alien alien, Vector2D alien_pos) {
    bool check_collision = false;
    
    // Checks collision of bottom left corner of alien with sprite  
    if (alien_pos.x >= position_x_ &&
    alien_pos.x <= (position_x_ + sprite_x_length) && 
    position_y_ <= (alien_pos.y + 6)&& 
   (alien_pos.y + 6) <= (position_y_ + sprite_y_length)) {
        check_collision = true;
        alien_collision_flag = true;
    }
    
    return check_collision;
}

bool CheckAlienCollision::check_bottom_right(Alien alien, Vector2D alien_pos) {
    bool check_collision = false;
    
    // Checks collision of bottom right corner of alien with sprite      
    if ((alien_pos.x + 7) >= position_x_ &&
    (alien_pos.x + 7) <= (position_x_ + sprite_x_length) && 
    position_y_ <= (alien_pos.y + 6) && 
    (alien_pos.y + 6) <= (position_y_ + sprite_y_length)) {
       check_collision = true;
        alien_collision_flag = true;
    } 
    
    return check_collision;
}
