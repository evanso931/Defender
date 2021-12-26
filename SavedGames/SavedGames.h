#ifndef SAVEDGAMES_H
#define SAVEDGAMES_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "N5110.h"
#include "SDFileSystem.h"
#include "Sprites.h"
#include "SDErrors.h"

struct SavedGamesData{
    int score; /**< Score variable */
    int lives; /**< Lives left variable */
    int smart_bombs; /**< Smart_bombs left variable */
    int alien_number; /**< Number of alien on screen variable*/
};

/** SavedGames class
 * @brief Stores saved games on sd card, stores score, lives, smart bombs and 
 * number of current alliens 
 * @author Benjamin Evans, University of Leeds
 * @date May 2020
 */      
class  SavedGames: public SDErrors{
    public:
        /** Constructor */
         SavedGames();
        
        /** Destructor */
        ~SavedGames();
        
        /** Initialises SavedGames
         */
        void init();
        
        /** Adds saved data to sd card 
         * @param sd @details sd card object
         * @param data @details SavedGamesData struct
         * @param lcd @details N5110 object
         */
        void add_saved_data(SDFileSystem &sd,SavedGamesData data, N5110 &lcd); 
        
        /** Reads saved data from sd card and return it as a struct
         * @param sd @details sd card object
         * @param lcd @details N5110 object
         * @return data @details SavedGamesData struct
         */
        SavedGamesData read_saved_data(SDFileSystem &sd, N5110 &lcd);
        
        /** Scrolls through the different saved games parts
         * @param d_ @details Direction of joystick
         */
        void saved_games_scroll(Direction d_);
        
        /** Draws the saved game screen
         * @param lcd @details N5110 object
         */
        void display_saved_games(N5110 &lcd);
        
         /** Draws the select save game select screen
         * @param lcd @details N5110 object
         */
        void save_game_screen(N5110 &lcd);
        
        /** Runs the save test unit test
         * @param lcd @details N5110 object
         * @param sd @details sd card object
         */
        void run_save_test(SDFileSystem &sd, N5110 &lcd);
        
    // Accessors and mutators --------------------------------------------------
        
        /** Gets the displayed saved game number
         * @return display_data_number_;
         */
        int get_display_data_number();
        
    private:   
    // Function prototypes -----------------------------------------------------
    
        /** Check if sd card is inserted and print message if not
         * @param lcd @details N5110 object
         * @param sd @details sd card object
         * @note Dont think sd.card_present()function actually works 
         */
        void check_sd_present(SDFileSystem &sd,N5110 &lcd); 
        
        /** Shows error if saved data files opens incorrectly
         * @param lcd @details N5110 object
         */
        void error_open_file(N5110 &lcd);
        
        /** Draws no saved files screen
         * @param lcd @details N5110 object
         */
        void no_saved_files(N5110 &lcd);
        
        /** Save test unit test, checks the saving and reading functions work
         * @param lcd @details N5110 object
         * @param sd @details sd card object
         * @param d_ @details Direction of joystick
         */
        bool save_test(Direction d_,SDFileSystem &sd, N5110 &lcd);
 
    // Varibles ---------------------------------------------------------------- 
        
        /** Variable for which vector data to select */
        int display_data_number_;
        
        
};
#endif
