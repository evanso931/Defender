#include "Map.h"

// Constant Definitions
#define MAP_TERRAIN_Y_POSITION 41
#define MAP_TERRAIN_X_POSITION -84
#define MAP_TERRAIN_X_LENGTH 0

Map::Map() {
    
}
 
Map::~Map() {
    
}

void Map::init(Gamepad &pad) {
    // Assign values to variables
    map_length_ = MAP_TERRAIN_X_LENGTH;
    position_x_ = MAP_TERRAIN_X_POSITION;
    position_y_ = MAP_TERRAIN_Y_POSITION;
    
    // Initialises random arrays to make random map
    fill_random_arrays(pad);
    
}

void Map::fill_random_arrays(Gamepad &pad) {
    srand(pad.read_adc()*64000);
    for (int i = 0; i < 11; i++) {
        rand_heights_[i]= rand() % 8 + 5;
        rand_lengths_[i]= rand() % 16 + 15;
    }   
    
    // To check random numbers generated are actually random 
    #ifdef RANDOM_NUMBER_DEBUG   
    for (int i = 0; i < 11; i++) { 
       printf("map height random array = %d\n", rand_heights_[i]);
    }
    #endif
}

void Map::draw_triangle(N5110 &lcd,int triangle_height) { 
    // Draws triangle by drawing two lines with one line having negative gradient 
    lcd.drawLine(position_x_, position_y_, position_x_ + triangle_height, 
    position_y_ - triangle_height,1); 
    lcd.drawLine(position_x_ + triangle_height, position_y_ - triangle_height,
    position_x_ + 2*triangle_height,position_y_,1);
    
    // Changes the position of the map next draw line starts at the end of the 
    // drawn triangle
    position_x_ = position_x_ + 2*triangle_height,position_y_;
}

void Map::draw_line(N5110 &lcd,int line_length) { 
    lcd.drawLine(position_x_, position_y_, position_x_ + line_length, 
    position_y_,1);
    
    // Changes the position of the map next draw triangle starts at the end of 
    // the drawn line
    position_x_ += line_length;
}

void Map::draw_map(N5110 &lcd, Direction d_) {
    // printf("position_x_ map = %d\n", position_x_);
    // printf("move map = %d\n", move_map);
    
    reset_position_x_map_to_origonal_ = position_x_;
    map_length_ = 0;
    
    // Prints main part of map
    for (int i = 0; i < 11; i++) {
        draw_triangle(lcd,rand_heights_[i]);
        draw_line(lcd,rand_lengths_[i]);
        final_random_element_used_ = i;
        
        // Calculates the length of the random map produced
        map_length_ += rand_lengths_[i] + 2*rand_heights_[i];
        
        // Stops random maps lengths being to large only want it about 3 screen 
        // widths
        if (map_length_ >252) { 
            break;
        }
    }
    
    // Checks if the map need duplicating in forward and backwards loop and 
    // fills gap 
    check_duplicates_map_forward(lcd);
    check_duplicates_map_backwards(lcd);
    
    // Resets position of map and moves it 
    position_x_ = reset_position_x_map_to_origonal_ + calc_map_movement(d_);
    
    // Moves map to different position so make it look like its looping 
    if (position_x_+ map_length_ < 0) {
       position_x_ = 0;
    } else if (position_x_ > 84) {
        position_x_ = 84 - map_length_;
    }
}

void Map::check_duplicates_map_forward(N5110 &lcd) { 
    // Prints 1st part of map to fill gap wear map isn't present just before its 
    // about to loop round it's self
    if (reset_position_x_map_to_origonal_ + map_length_ <84 ) {
        for (int i = 0; i < 4; i++) {
            draw_triangle(lcd,rand_heights_[i]);
            draw_line(lcd,rand_lengths_[i]);
        }
    }
    
}

void Map::check_duplicates_map_backwards(N5110 &lcd) {
    // Prints last part of map to fill gap wear map isn't present just before its 
    // about to loop round it's self
    if (reset_position_x_map_to_origonal_ > 0 ) {
        int print_reverse_position = 0;
        
        // prints the last 4 parts of the map to fill gap
        for (int i = final_random_element_used_ ;
         i > final_random_element_used_ - 4; i--) {
            position_x_ = reset_position_x_map_to_origonal_ - rand_lengths_[i] - 
            print_reverse_position;
            draw_line(lcd,rand_lengths_[i]);
            print_reverse_position += rand_lengths_[i];
            position_x_ = reset_position_x_map_to_origonal_ - 2*rand_heights_[i]
            - print_reverse_position;
            draw_triangle(lcd,rand_heights_[i]);
            print_reverse_position += 2*rand_heights_[i];
        }
    }
}

int Map::calc_map_movement(Direction d_) {  
    // Moves the map in opposite direction to spaceship when it's position is at 
    // min and max x positions and joystick has direction     
    if (d_ == W || d_ == NW || d_ == SW) { 
        return 2;
    }else if (d_ == E || d_ == NE || d_ == SE) { 
        return -2; 
    }else {
        return 0;
    }
    
    // Debug and check variables when defined  
    #ifdef CALCULATE_MAP_MOVEMENT_DEBUG   
        printf("move map = %d\n", move_map_);   
        printf("direction = %d\n", d_);     
        printf("x = %d\n", position_x_spaceship_);
    #endif
}

int Map::get_position_x_map() {
    return position_x_;
}

int Map::get_length_map() {
    return map_length_;
}
