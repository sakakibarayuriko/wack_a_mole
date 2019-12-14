//
//  Mole.hpp
//  emptyExample
//
//  Created by 榊原ゆり子 on 2018/07/16.
//

#ifndef ofMole_hpp
#define ofMole_hpp

#include <stdio.h>
#include "ofMain.h"

#define LENGTH 5 //読み込む画像の枚数

class ofMole {
  public:
    ofMole(float x, float y);
    void resetTimers();
    void update();
    void display();
    void checkHit();
    void moleGameOver();
    
    float xPos;
    float yPos;
    
    ofImage moles[LENGTH];
    
    int currentMole;
    
    // how long to stay in this currentMole
    int totalCurrentMoleTime;
    
    // how long have we been in this currentMole?
    int currentMoleTime;
    
    int score, star;//②
    
};

#endif /* Mole_hpp */
