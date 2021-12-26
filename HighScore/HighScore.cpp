#include "HighScore.h"

HighScore::HighScore() {
    
}

HighScore::~HighScore() {
    
}

bool HighScore::save_test(int score,SDFileSystem &sd, N5110 &lcd) {
    printf("Score = %d  : ",score);
    
    save_new_high_score(sd, lcd, score); 
    
    int output_score = read_high_score(sd); 
    
    // Checks if the input and output are equal
    if (output_score == score) {
        printf ( "Passed!\n");
        return true;
    } else {
        printf ( "Failed!\n");
        return false;
    }
}

void HighScore::run_save_test(SDFileSystem &sd, N5110 &lcd) {
    printf ("\nTesting high_score_save_test() \n\n");
    int passed_counter = 0;

    // Runs test with all different possible inputs
    if (save_test(4, sd, lcd)) passed_counter++;
    if (save_test(3, sd, lcd)) passed_counter++;
    if (save_test(250, sd, lcd)) passed_counter++;
    if (save_test(-3, sd, lcd)) passed_counter++;
    if (save_test(222, sd, lcd)) passed_counter++;
    if (save_test(9999, sd, lcd)) passed_counter++;
    if (save_test(-9999, sd, lcd)) passed_counter++;
    if (save_test(0, sd, lcd)) passed_counter++;
       
    // prints results
    printf ("\n high_score_save_test %d tests out of 8\n\n\n",
    passed_counter);
}

void HighScore::init() {
    error_ = false;
}

void HighScore::no_high_scores(N5110 &lcd) {
    // Print error screen
    lcd.clear();
    lcd.printString("No High Scores",0,3);
    lcd.printString("Or No SD Card",3,4);
    lcd.refresh();
    wait(3); 
}

void HighScore::error_open_file(N5110 &lcd) {
    error_ = true;

    // Print error screen
    lcd.clear();
    lcd.printString(" Unable to  ",9,3);
    lcd.printString("Save",30,4);
    lcd.printString("High Score",12,4);
    lcd.refresh();
}

void HighScore::save_new_high_score(SDFileSystem &sd, N5110 &lcd, 
int new_high_score) {
    FILE *fp;
    
    // Overwrites previous high score
    fp = fopen("/sd/HighScore.csv", "w");
    
     
    if (fp == NULL) {
        error_open_file(lcd);
            
    }else{   
        
        // Add data to file if no error
        fprintf(fp, "%d", new_high_score); 
        fclose(fp);
    }      
}

int HighScore::read_high_score(SDFileSystem &sd) {
    FILE *fp;
    int saved_high_score = 0;
       
    fp = fopen("/sd/HighScore.csv", "r");

    // Check if high score game files
    if (fp == NULL) {
        error_ = true;   
        
    // Reads current high score if no high score is set zero is returned
    }else{
        
        // Read save file and add values to saved_high_score int
        fscanf(fp, "%d", &saved_high_score);
          
        fclose(fp);           
    } 
     
    return saved_high_score;
}

