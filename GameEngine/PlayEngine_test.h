#ifndef PLAYENGINE_TEST_H
#define PLAYENGINE_TEST_H

/** PlayEngine Test
 * @brief Checks that the engine functions of the playable part of game work
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 * @return true if test are passed 
 */
 
bool read_accelerometer_direction_test(Direction expected_d, float roll, 
float pitch) {
    // Objects required for test 
    PlayEngine engine;;
    
    printf("read_accelerometer_direction = %d : ", expected_d);
    
    engine.read_accelerometer_direction(roll, pitch);
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (expected_d == engine.d_) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", expected_d, 
        engine.d_);
        return false;
    }
}

bool spawn_aliens_test(int expected_alien_num) {
    // Objects required for test 
    PlayEngine engine;
    engine.alien_number_ = expected_alien_num;
    
    printf("spawn_aliens  : ");
    
    //spawn number of expected aliens
    for (int i = 1; i <= expected_alien_num; i++) {
        engine.spawn_aliens();
    }
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.alien_vector.size() == expected_alien_num) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", 
        engine.alien_vector.size(), expected_alien_num);
        return false;
    }
}

bool create_alien_test(int expected_alien_num) {
    // Objects required for test 
    PlayEngine engine;
    engine.alien_number_ = expected_alien_num;
    
    printf("create_aliens  : ");
    
    //spawn number of expected aliens
    for (int i = 1; i <= expected_alien_num; i++) {
        engine.create_alien();
    }
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.alien_vector.size() == expected_alien_num) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", 
        engine.alien_vector.size(), expected_alien_num);
        return false;
    }
}

bool create_explosion_test(int expected_explosion_num) {
    // Objects required for test 
    PlayEngine engine;
    GameEngine GameEngine;
    Vector2D pos = {5,4};
    
    printf("Create_explosion  : ");
    
    //spawn number of expected aliens
    for (int i = 1; i <= expected_explosion_num; i++) {
        engine.create_explosion(pos);
    }
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.explosion_vector.size() == expected_explosion_num) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", 
        engine.explosion_vector.size(), expected_explosion_num);
        return false;
    }
}

bool spawn_people_test(int expected_people_num) {
    // Objects required for test 
    PlayEngine engine;
    
    printf("spawn_people  : ");
    
    //spawn number of expected aliens
    for (int i = 1; i <= expected_people_num; i++) {
        engine.spawn_people();
    }
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.people_vector.size() == expected_people_num) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", 
        engine.people_vector.size(), expected_people_num);
        return false;
    }
}

bool create_people_test(int expected_people_num) {
    // Objects required for test 
    PlayEngine engine;
   
    printf("create_people  : ");
    
    //spawn number of expected aliens
    for (int i = 1; i <= expected_people_num; i++) {
        engine.create_people();
    }
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.people_vector.size() == expected_people_num) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n", 
        engine.people_vector.size(), expected_people_num);
        return false;
    }
}

bool reset_map_timer_test(Direction expected_d, bool spaceship_destroyed) {
    // Objects required for test 
    PlayEngine engine;
    
    printf("reset_map_timer  %d: ",spaceship_destroyed);
    
    // Pre defines variables
    engine.spaceship_destroyed_ = spaceship_destroyed;
    engine.d_ = N;
    
    engine.reset_map_timer();
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.d_ == expected_d) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d  (expecting  %d)\n",engine.d_, expected_d);
        return false;
    }
}

bool reset_map_test() {
    // Objects required for test 
    PlayEngine engine;
    
    
    printf("reset_map_  : ");
    
    // Create object for map functions
    engine.spawn_people();
    engine.spawn_aliens();
    
    engine.reset_map();
    
    // Checks if pixel is drawn and therefor testing it hasn’t gone of screen
    if (engine.people_vector.size()== 0 && engine.alien_vector.size() == 0) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed! value = %d,%d,  (expecting  0,0)\n",
        engine.people_vector.size(), engine.alien_vector.size());
        return false;
    }
}
#endif
