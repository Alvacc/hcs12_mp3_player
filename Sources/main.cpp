#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "music_common.h"
#include "buzz.h"

  
  
  void sing(unsigned int song) {
  
  
  if(song == 1) {
    
    unsigned int size = sizeof(melody) / sizeof(int);
    for (unsigned int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      unsigned int noteDuration = 110 / tempo[thisNote];

      buzz(melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      unsigned int pauseBetweenNotes = noteDuration*13/10;
      MSDelay(pauseBetweenNotes); 
      
      // stop the tone playing:
      //buzz(0, noteDuration);
      
    }
    
  }else{
     unsigned int size = sizeof(underworld_melody) / sizeof(int);
    for (unsigned int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      
      unsigned int noteDuration = 130 / underworld_tempo[thisNote];
      
      buzz(underworld_melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      unsigned int pauseBetweenNotes = noteDuration*13/10;
      MSDelay(pauseBetweenNotes); 
      
      // stop the tone playing:
      //buzz(0, noteDuration);
      
    }
  }
    
  }
  

void main(void) 
{  
       
    DDRT = DDRT | 0b00100000;    // PTT5 as output
    
    DDRB = DDRB | 0xFF;    // PTB as output
    DDRJ = DDRJ | 0xFF;    // PTJ as output
    PTJ = PTJ & 0;
    
    while(1) {
      sing(1);
      sing(2);
      sing(1); 
    }

}