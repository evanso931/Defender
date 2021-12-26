#ifndef SDERRORS_H
#define SDERRORS_H

// Included Headers ------------------------------------------------------------
#include "mbed.h"
#include "Gamepad.h"

/** SD Errors class errors
* @brief Errors for SD related functions parent class
* @author Benjamin Evans, University of Leeds
* @date May 2020
*/         
class SDErrors { 
    public:
    // Function prototypes -----------------------------------------------------
    
        /** Gets error flag
         * @return error_;
         */
        bool get_error();
        
         /** Set error
         * @param error;
         */
        void set_error(bool error);
    
    protected:   
    // Variables ---------------------------------------------------------------- 
        
        /** Flag for error, 
         * @note true = error 
         */
        bool error_;
};
 
#endif
