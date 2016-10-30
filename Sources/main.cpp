#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "music_common.h"

void buzz(long frequency, long length) {
   for(int i=0;i<10;++i) {
          
          for(int j=0;j<1000/melody[i]*tempo[i];++j) {
            PTT = PTT | 0x20;      //make PT5=1
            MSDelay(melody[i]);         //change the delay size to see what happens
            PTT = PTT & 0xDF;      //Make PT5=0
            MSDelay(melody[i]);         //change delay size....
          }
      
        }
}

//millisecond delay for XTAL=8MHz, PLL=48MHz
//The HCS12 Serial Monitor is used to download and  the program.
//Serial Monitor uses PLL=48MHz

 void MSDelay(unsigned int itime)
  {
    unsigned int i; unsigned int j;
    for(i=0;i<itime;i++)
      for(j=0;j<4000;j++);    //1 msec. tested using Scope
  }
  
  

void main(void) 
{  
       
    DDRT = DDRT | 0b00100000;    // PTT5 as output 
     
    

}