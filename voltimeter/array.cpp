#include <Arduino.h>
#include <stdint.h>

#include "array.h"
#include "pins.h"

const byte digits[] = {pinD1, pinD2, pinD3, pinD4}; // digit pins
                            
const byte seg[] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinH};

byte Char[37][9] = { 
           {1,1,1,1,1,1,0,0,'0'},//0
           {0,1,1,0,0,0,0,0,'1'},//1
           {1,1,0,1,1,0,1,0,'2'},//2
           {1,1,1,1,0,0,1,0,'3'},//3
           {0,1,1,0,0,1,1,0,'4'},//4
           {1,0,1,1,0,1,1,0,'5'},//5
           {1,0,1,1,1,1,1,0,'6'},//6
           {1,1,1,0,0,0,0,0,'7'},//7
           {1,1,1,1,1,1,1,0,'8'},//8
           {1,1,1,1,0,1,1,0,'9'}, //9
           {1,1,1,0,1,1,1,0,'a'},//A/1
           {0,0,1,1,1,1,1,0,'b'},//b/2
           {0,0,0,1,1,0,1,0,'c'},//C/3
           {0,1,1,1,1,0,1,0,'d'},//d/4
           {1,0,0,1,1,1,1,0,'e'},//E/5
           {1,0,0,0,1,1,1,0,'f'},//F/6
           {1,0,1,1,1,1,0,0,'g'},//G/7
           {0,1,1,0,1,1,1,0,'h'},//H/8
           {0,1,1,0,0,0,0,0,'i'},//I/9
           {0,1,1,1,1,0,0,0,'j'},//J/10
           {0,0,0,1,1,1,0,0,'l'},//L/11
           {0,0,1,0,1,0,1,0,'n'},//n/12
           {0,0,1,1,1,0,1,0,'o'},//o/13
           {1,1,0,0,1,1,1,0,'p'},//P/14
           {1,1,1,0,0,1,1,0,'q'},//q/15
           {0,0,0,0,1,0,1,0,'r'},//r/16
           {1,0,1,1,0,1,1,0,'s'},//S/17   looks like number 5
           {0,0,0,1,1,1,1,0,'t'},//t/18
           {0,1,1,1,1,1,0,0,'u'},//U/19
           {0,1,1,1,0,1,1,0,'y'},//y/20
           {0,0,0,0,0,0,0,1,'.'},//.
           {0,0,0,0,0,0,1,0,'-'},//dash/negative
           {0,0,0,1,0,0,0,0,'_'},//underscore
           {1,0,0,1,1,1,0,0,'['},//[
           {1,1,1,1,0,0,0,0,']'},//]
           {1,1,0,0,1,0,1,0,'?'},//?
           {0,0,0,0,0,0,0,0,' '}//blank
        };
        
