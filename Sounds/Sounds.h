#ifndef SOUNDS_H
#define SOUNDS_H

const int star_wars[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4,NOTE_F5, NOTE_C6,NOTE_AS5, NOTE_A5, NOTE_G5, 
  NOTE_F6, NOTE_C6,NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5,NOTE_F5, 
  NOTE_C6,NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,NOTE_AS5, NOTE_A5, 
  NOTE_G5, NOTE_F6, NOTE_C6,NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, 
  NOTE_C5, NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5,NOTE_C5, NOTE_C5,NOTE_D5, NOTE_D5, 
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,NOTE_F5, NOTE_G5, 
  NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5,NOTE_C6, NOTE_C6,NOTE_F6, NOTE_DS6, 
  NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5,NOTE_C6
};

const int star_wars_note_time[] = {
     8,8,8,2,2,8,8,8,2,4,8,8,8,2,4,8,8,8,2,8,8,8,2,2,8,8,8,2,4,8,8,8,2,4,8,8,8,
     2,-8,16,-4,8,8,8,8,8,8,8,8,4,8,4,-8,16,-4,8,8,8,8,8,-8,16,2,8,8,-4,8,8,8,8,
     8,8,8,8,4,8,4,-8,16,4,8, 4,8,4, 8,4,8,1  
};

const int melody_off[] = {
    REST
};

const int melody_off_note_time[] = {
    8,6
};

const int god_farther[] = {
    NOTE_E4,  NOTE_A4,  NOTE_C5,
    NOTE_B4,  NOTE_A4,  NOTE_C5,  NOTE_A4,  NOTE_B4,  NOTE_A4,  NOTE_F4,  
    NOTE_G4, NOTE_E4,  NOTE_E4,  NOTE_A4,  NOTE_C5, NOTE_B4,  NOTE_A4,  NOTE_C5, 
    NOTE_A4,  NOTE_C5,  NOTE_A4, NOTE_E4,  NOTE_DS4
};

const int god_farther_note_time[] = {
    8, 8,  8, 1, 8, 8,  8, 8,  8, 8,  8,  8, 2,  8, 8,  8,
    8, 8,  8, 8,  8, 8, 1
};


const int take_on_me[] = {
    NOTE_FS5, NOTE_FS5,NOTE_D5, NOTE_B4, REST, NOTE_B4, REST, NOTE_E5, REST, 
    NOTE_E5, REST, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,NOTE_A5, 
    NOTE_A5, NOTE_A5, NOTE_E5, REST, NOTE_D5, REST, NOTE_FS5, REST, NOTE_FS5, 
    REST, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5,NOTE_FS5, NOTE_FS5,
    NOTE_D5, NOTE_B4, REST, NOTE_B4, REST, NOTE_E5,
    
    REST, NOTE_E5, REST, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
    NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, REST, NOTE_D5, REST, NOTE_FS5, 
    REST, NOTE_FS5, REST, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};


const int take_on_me_note_time[] = {
8, 8,8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
8, 8, 8, 8, 8, 8, 8,8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,8, 8, 
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
    
};

#endif
