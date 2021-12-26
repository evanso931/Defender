#include "CheckCollision.h"

bool CheckCollision::check_collision(Weapons bullet) {
    bool collision = false; 
    Vector2D bullet_pos = bullet.get_pos();
    // printf ("Collision 1 = %d\n", collision);
    
    // Checks collision if bullet is going in east direction 
    if (bullet.get_direction()) {
    // int bullet_pos_twox = bullet_pos.x;
    // int bullet_pos_twoy = bullet_pos.y;
    // printf ("alien x = %d, bullet x = %d\n", position_x_,bullet_pos_twox);
    // printf ("alien y = %d, bullet y = %d\n", position_y_,bullet_pos_twoy);
        
        // Collision if the bullet is inside of the xy ranges of sprite drawing
        if ((bullet_pos.x + 1) >= position_x_ && 
        (bullet_pos.x + 1) <= (position_x_ + sprite_x_length ) && 
        position_y_ <= bullet_pos.y && 
        bullet_pos.y <= (position_y_ + sprite_y_length )) {
            collision = true;
        }
        
    // printf ("Collision 2 = %d\n", collision);  
      
    // Checks collision if bullet is going in west direction 
    }else if (!bullet.get_direction()) {
        
        if (bullet_pos.x <= (position_x_ + sprite_x_length ) && 
        bullet_pos.x >= position_x_ && 
        position_y_ <= bullet_pos.y && 
        bullet_pos.y <= (position_y_ + sprite_y_length )) {
            collision = true;
        }
        
     // printf ("Collision 3 = %d\n", collision);   
    }
    
    // printf ("Collision 4 = %d\n", collision);   
    return collision;
}

