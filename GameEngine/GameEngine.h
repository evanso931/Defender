#ifndef GAMEENGINE_H
#define GAMEENGINE_H
 
// Included Headers ------------------------------------------------------------
#include "HUD.h"
#include "Menu.h"
#include "FXOS8700CQ.h"
#include "SDFileSystem.h"
#include "SavedGames.h"
#include "Settings.h"
#include "Sounds.h"
#include "HighScore.h"
#include "PlayEngine.h"

/** GameEngine class
 * @brief Runs the different parts of the menu and playable part of game
 * @author Benjamin Evans, University of Leeds
 * @date April 2020
 */
class GameEngine:private PlayEngine {
    public:
        /** Constructor */
        GameEngine();
        
        /** Destructor */
        ~GameEngine();
        
        /** Initialises GameEngine */
        void init();
        
        /** Switch statement to run different menu options */
        void game_select_part();
          
    private:
    // Function prototypes -----------------------------------------------------

    // Menu Control
        /** Runs the menu */
        void run_menu();
        
        /** Draws loading screen */
        void loading_screen();
        
        /** Selects the different parts of the playable game like the pause 
         * screen and save screen
         */
        void play_select();
    
    // Menu Play
        /** Runs the play game */
        void run_play();
        
        /** Initialises the play part of the game*/
        void play_init();
        
        /** Only runs movement when the spaceship is not destroyed */
        void spaceship_not_detroyed();
       
        /** Main gameplay loop that runs playable part of game */
        void gameplay_loop();
        
        /** Draws the game over screen*/
        void draw_game_over_screen();
                
        /** Runs the paused screen */
        void run_paused_game();

        /** Draws the pause screen*/
        void draw_pause_screen();
        
        /** Runs saved games screen */
        void run_saved_games();
        
        /** Time-triggered interrupt to wake MCU from sleep */
        void lcd_frame_time_isr();
        
        /** Plays the music if its turned on */
        void play_music();
        
        /** Stops the music if its turned off */
        void stop_music();
        
    // Menu Setting
        /** Runs settings screen*/
        void run_settings();
        
    // Menu Saved Games   
        /** Initialises the play part of the game and sets the variables to 
         * saved values 
         */
        void saved_games_overide_init();
        
        /** Runs save a game screen */
        void run_save_a_game();
        
    // Menu High Score 
        /** Runs high score screen */
        void run_highscore();
         
        /** Calculates if the current end game score is a new high score and 
         * saves it if it is 
         * @return new_high_score @detials bool true if there is new high score
         */
        bool calculate_new_score();
         
    // Variables ---------------------------------------------------------------
    
    // Menu Control 
        /** The part of the menu that is currently selected and in*/
        MenuParts current_menu_part_;
        
        /** Volatile flag for ISR */
        volatile int lcd_frame_time_flag_;  
        
        /** Flag to exit the play part of the game */
        bool exit_flag_; 
        
        /** Flag to run the save game screen */
        bool run_save_a_game_flag_;
        
        /** Counter for pause screen so pause button doesn’t double press */
        int paused_counter_;
        
        /** Hold on or off depending if music is set on or off */
        MusicParts  music_fx_;
        
        /** Paused button pressed flag for pausing during the game */
        bool paused_button_pressed_; 
        
        /** Flag for turning the music on and off in the settings*/
        bool  music_flag_;
        
    // Objects -----------------------------------------------------------------
        
        /** Define HUD object */
        HUD hud;
        
        /** Define Menu object */
        Menu menu;
        
        /** Define Setting object */
        Settings setting;
        
        /** Define Ticker object for lcd framerate */
        Ticker ticker;
        
        /** Define SavedGames object */
        SavedGames saved;
        
        /** Define HighScore object */
        HighScore h_score;
};
 
#endif
