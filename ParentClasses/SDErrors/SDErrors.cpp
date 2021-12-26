#include "SDErrors.h"


bool SDErrors::get_error() {
    return error_;   
}

void SDErrors::set_error(bool error) {
    error_ = error;   
}