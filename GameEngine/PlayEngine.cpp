#include "PlayEngine.h"

// Spaceship control -----------------------------------------------------------

void PlayEngine::read_joystick_direction() {
    d_ = pad.get_direction();
}

void PlayEngine::read_accelerometer_direction(float roll,float pitch) {  
    // printf("Pitch = %f  Roll = %f\n", pitch, roll);  
     
    // North
    if (pitch >= -35) {
        if (roll >= 10) {
            d_ = NE;
        }else if (roll <= -10) {
            d_ = NW;
        }else {
            d_ = N;
        }
    // South
    }else if (pitch <= -55) {
        if (roll >= 10) {
            d_ = SE;
        }else if (roll <= -10) {
            d_ = SW;
        }else {
            d_ = S; 
        }
    // East/west
    }else {
        if (roll >= 10) {
            d_ = E;
        }else if (roll <= -10) {
            d_ = W;
        }else{
            d_ = CENTRE;
        }
    }      
}

void PlayEngine::spaceship_lives_leds() {
    pad.leds_off(); 
    
    // Top two red leds on if 1 lives left
    if (spaceship_lives_ >= 1) {
        pad.led(1,1); 
        pad.led(4,1);
    }
    
    // Middle two orange leds also on if 2 lives left
    if (spaceship_lives_ >= 2) {
        pad.led(2,1);
        pad.led(5,1);
    }
    
    // Bottom two red leds also on if 3 lives left
    if (spaceship_lives_ == 3) {
        pad.led(3,1);
        pad.led(6,1);
    }
}




// Weapon control --------------------------------------------------------------

void PlayEngine::create_weapons_bullets() {
    // Controlls speed that bullet can be fired
    if (pad.A_pressed() && bullet_timer_ <=0) {
        // Bullet object
        Weapons new_bullet;
            
        new_bullet.init(spaceship.get_pos(), 
        spaceship.get_spaceship_sprite_direction(), true);
            
        // Stores bullet object in vector 
        bullet_vector.push_back(new_bullet);
        bullet_timer_ =  10; 
    }
    bullet_timer_--;   
}

void PlayEngine::create_weapons_smart_bomb() {  
    if (pad.B_pressed() && smart_bomb_counter_ > 0 && smart_bomb_timer_ <=0) {
        weapons.smart_bomb(lcd);
        smart_bomb_counter_--;
            
        // Deletes alien object if on screen and person object if abducted
        for (int i = (alien_vector.size() -1) ; i >= 0 ; i--) {
            Vector2D alien_pos = alien_vector[i].get_pos(); 
            
            // Creats explosion if alien was on the screen    
            if(alien_pos.x <= 84 && alien_pos.x >= -6){
                create_explosion(alien_pos); 
                
                // Delete person object if was being abducted by destroyed alien
                if(alien_vector[i].get_collision_people_element() > -1){
                    people_vector.erase(people_vector.begin() + 
                    alien_vector[i].get_collision_people_element()); 
                } 
                
                alien_vector.erase(alien_vector.begin()+ i);
                points_ ++;  
            }  
        }
    
    // Timer to stop smart bomb button be accidently pressed twice or spammed 
    smart_bomb_timer_ =  30;   
    } 
    smart_bomb_timer_--;
}

void PlayEngine::draw_bullets() {
    // Interates over bullet vectors, moves and draws bullet objects
    
    // Alien bullets
    for (int i = 0; i < alien_bullet_vector.size(); i++) {
        alien_bullet_vector[i].draw_alien_bullet(lcd, d_);
        
        // Deletes alien bullet object after bullet has moved set distance   
        if (alien_bullet_vector[i].get_bullet_delete_counter() >> 5) {
             alien_bullet_vector.erase(alien_bullet_vector.begin()+ i);
        }
        
        // Deletes bullet and spaceship if collision detected
        if (spaceship.check_collision(alien_bullet_vector[i]) && 
        !spaceship_destroyed_ ) {
            create_explosion(spaceship.get_pos());
            spaceship_destroyed_ = true;
            alien_bullet_vector.erase(alien_bullet_vector.begin()+ i);     
        }
    }
    
    // Spaceship bullets 
    for (int i = 0; i < bullet_vector.size(); i++) {
        bullet_vector[i].draw_bullet(lcd);
         
        // Deletes bullet object after bullet has moved set distance   
        if (bullet_vector[i].get_bullet_delete_counter() >> 5) {
             bullet_vector.erase(bullet_vector.begin()+ i);
        }
    }
}




// Alien Control ---------------------------------------------------------------

void PlayEngine::spawn_aliens() {
    if (alien_vector.size() <= alien_number_) {
        create_alien();
    }
    
    // printf( " alien_number_counter_ = %d\n",alien_number_counter_);
    
    // Slowly increasing the alien counter as game goes on to make harder
    if (spawn_alien_counter_%(375*spawn_time_multipler_) ==  0) {
        alien_number_++;
        spawn_time_multipler_*= 1.2;  
        
        // printf("alien_number_ %d\n",alien_number_);   
    }
    
    spawn_alien_counter_++;
}

void PlayEngine::create_alien() {
    int position_x_start = 0;
    
    // Alien object
    Alien new_alien;
    
    // Spawns aliens between x > 84 and x <0
    if (rand() % 2) {
        position_x_start = rand() % 84 + 84;
    }else{
        position_x_start =rand() % 83 - 84;
    } 
    new_alien.init(pad, position_x_start, (rand() % 33 + 9));
    
    // Stores alien object in vector 
    alien_vector.push_back(new_alien);
}

void PlayEngine::check_alien_people_collision(int i) {
    // Only a collision if all three of theses conditions are met:
    // Checks all these condition for every alien to every person
    // 1)person hasn't already had a collision
    // 2)There is an actual collision of people and alien
    for (int x = 0; x < people_vector.size(); x++) {
        if (!people_vector[x].get_alien_collision_flag() &&
            people_vector[x].check_alien_collision(alien_vector[i])) {  
            alien_vector[i].set_collision_people_element(x); 
        }
    }
    
    // Draws collision if detected
    if (alien_vector[i].get_collision_people_element() > -1) {
        alien_vector[i].draw_alien(lcd,spaceship.get_pos(),d_, 
        map.get_length_map(), map.get_position_x_map(),true);
    }else{
        alien_vector[i].draw_alien(lcd,spaceship.get_pos(),d_, 
        map.get_length_map(), map.get_position_x_map(),false);
    }    
}

void PlayEngine::alliens_fire_bullets(int i) {
    if (alien_vector[i].get_alien_fire_counter()%60 == 0) {
        Weapons alien_bullet;
            
        // Fires bullet towards direction of spaceship
        bool alien_bullet_direction = false;
        Vector2D spaceship_pos = spaceship.get_pos();
        Vector2D alien_pos = alien_vector[i].get_pos();
        if (spaceship_pos.x > alien_pos.x) {
            alien_bullet_direction = true;
        }
            
        alien_bullet.init(alien_vector[i].get_pos(), 
        alien_bullet_direction , false);
        
        // Stores bullet object in vector 
        alien_bullet_vector.push_back(alien_bullet); 
    }   
}

void PlayEngine::delete_aliens(int i) {
    for (int x = 0; x < bullet_vector.size(); x++) {
        if (alien_vector[i].check_collision(bullet_vector[x])){
            create_explosion(alien_vector[i].get_pos());
                
            //Delete person object if was carried by destroyed alien
            if(alien_vector[i].get_collision_people_element() > -1){
                people_vector.erase(people_vector.begin() + 
                alien_vector[i].get_collision_people_element()); 
            }
            
            bullet_vector.erase(bullet_vector.begin()+ x);    
            alien_vector.erase(alien_vector.begin()+ i);  
            points_ ++;   
        }
    }   
}

void PlayEngine::draw_aliens() {
    // Integrates over alien vector and draws each new_alien object 
    for (int i = 0; i < alien_vector.size(); i++) {
        
        check_alien_people_collision(i);
        
        // Deleted spaceship if alien ship touches spaceship
        if (spaceship.check_alien_collision(alien_vector[i]) && 
        !spaceship_destroyed_) {
            create_explosion(spaceship.get_pos());
            spaceship_destroyed_ = true;  
        }
        
        alliens_fire_bullets(i);
        
        delete_aliens(i);
    }
}




// Explosion Control -----------------------------------------------------------   

void PlayEngine::create_explosion(Vector2D destroyed_position) {
    // Explosion object
    Explosion new_explosion;
    
    new_explosion.init(destroyed_position);
    
    // Stores explosion object in vector 
    explosion_vector.push_back(new_explosion);
    
    
    // Plays explosion sound if sound fx on
    if (sound_fx_ == on) {
        pad.tone(40,0.1);
        // printf("playing Explosion\n");
    }
}

void PlayEngine::draw_explosions() {
    // Integrates over explosion vector and draws each explosion object 
    // then deleted object after set size
    for (int i = 0; i < explosion_vector.size(); i++) {
        explosion_vector[i].draw_explosion(lcd);
        
        // Delete explosion after reaches set size
        if (explosion_vector[i].get_explosion_radius() == 8) {
             explosion_vector.erase(explosion_vector.begin()+ i);    
        }
    }
}




// People Control --------------------------------------------------------------

void PlayEngine::spawn_people() {
    // Keeps number of people objects constant as people objects are erased
    if (people_vector.size() <= 5) {
        create_people();
    }
}

void PlayEngine::create_people() {
    // People object
    People people;
    
    people.init(pad, (rand() % 168 - 84));
    
    // Stores alien object in vector 
    people_vector.push_back(people);
}

void PlayEngine::draw_people() {
    for (int i = 0; i < people_vector.size(); i++) {
        people_vector[i].draw_people(lcd, d_, 
        map.get_length_map(), map.get_position_x_map());  
        
        // Erase person if at top of screen as captured by alien and alien is 
        // set to track mode
        Vector2D people_pos =  people_vector[i].get_pos();
        for (int x = 0; x < alien_vector.size(); x++) {
            Vector2D alien_pos = alien_vector[x].get_pos();
            if (people_pos.y < 30 && alien_pos.y < 9 &&
            alien_vector[x].get_collision_people_element() == i) {
                    
                // Set alien who abducted person to track mode
                alien_vector[x].set_track_flag(true);
                people_vector.erase(people_vector.begin()+ i);   
            }  
           
        }
    }
}




// Map Control------------------------------------------------------------------

void PlayEngine::reset_map_timer() {
    if (spaceship_destroyed_) {
        reset_map_counter_++; 
        
        // Stops map movement
        d_ = CENTRE;
        
        // Reset map after set time
        if (reset_map_counter_ == 50) {
            reset_map();
        }
    }   
}
   
void PlayEngine::reset_map() {
    // Reassign values to variables
    spaceship.init();
    spaceship_lives_--;
    spaceship_destroyed_ = false;
    reset_map_counter_ = 0;
    
    // Erase aliens so redrawn in random positions when respawning spaceship
    for (int i = (alien_vector.size() - 1); i >= 0 ; i--) {
        alien_vector.erase(alien_vector.begin()+ i);  
    }
    
    // Erase all people so redrawn at bottom of map
    for (int i = (people_vector.size() - 1); i >= 0 ; i--) {
         people_vector.erase(people_vector.begin()+ i);      
    }
    
    // Erase all alien bullets
    for (int i = (alien_bullet_vector.size() - 1); i >= 0 ; i--) {
         alien_bullet_vector.erase(alien_bullet_vector.begin()+ i);      
    }
}
