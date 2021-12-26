#ifndef HIGHSCORE_H
#define HIGHSCORE_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "SDFileSystem.h"
#include "Sprites.h"
#include "SDErrors.h"

/** High Score class
 * @brief Displays the highest score
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */      
class  HighScore:public SDErrors{
    public:
        /** Constructor */
         HighScore();
        
        /** Destructor */
        ~HighScore();
        
        /** Initialises HighScore
         */
        void init();
        
        /** Saves the sore if a new High score 
         * @param lcd @details N5110 object
         * @param sd @details sd card object
         * @param new_high_score
         */
        void save_new_high_score(SDFileSystem &sd, N5110 &lcd, 
        int new_high_score);
        
        /** Reads and returns the highest score
         * @param sd @details sd card object
         * @return high_score
         */
        int read_high_score(SDFileSystem &sd);
        
        /** Draws no high scores screen
         * @param lcd @details N5110 object
         */
        void no_high_scores(N5110 &lcd);
        
        /** Runs the save test unit test
         * @param lcd @details N5110 object
         * @param sd @details sd card object
         */
        void run_save_test(SDFileSystem &sd, N5110 &lcd);
        
    private:   
    // Function prototypes -----------------------------------------------------
        
        /** Shows error if high data files opens incorrectly
         * @param lcd @details N5110 object
         */
        void error_open_file(N5110 &lcd);
        
        /** Save test unit test, checks the saving and reading functions work
         * @param lcd @details N5110 object
         * @param sd @details sd card object
         * @param score @details score at end of game
         */
        bool save_test(int score,SDFileSystem &sd, N5110 &lcd);
        
};
#endif
