//
//  Mole.hpp
//
//  Created by 榊原ゆり子 on 2018/07/16.
//

#ifndef ofMole_hpp
#define ofMole_hpp

#include <stdio.h>
#include "ofMain.h"

#define TYPE_LENGTH 5

class ofMole {
public:
    ofMole(float x, float y);
    void resetTimers();
    void update();
    void display();
    void checkHit();
    
    float xPos;
    float yPos;
    
    ofImage moles[TYPE_LENGTH];
    
    int currentMole;
    int appearanceTime;
    int hiddenTime;
    int score;
    int starScore;
};

#endif /* Mole_hpp */
