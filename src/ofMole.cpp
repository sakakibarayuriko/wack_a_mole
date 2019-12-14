//
//  Mole.cpp
//  emptyExample
//
//  Created by 榊原ゆり子 on 2018/07/16.
//

#include "ofMole.hpp"
#include "ofApp.h"

ofMole::ofMole(float x, float y) {
    xPos = x;
    yPos = y;
    
    //start it empty
    currentMole = 0;
    
    //load the images
    for (int i = 0; i < LENGTH; i++) {
        moles[i].load("mole" + ofToString(i) + ".png");
    }
    
    resetTimers();
}

void ofMole::resetTimers() {
    // pick a random amount of time to stay in this currentMole
    totalCurrentMoleTime = int(ofRandom(50, 200));//出現時間
    
    // reset our current counter
    currentMoleTime = 0;//隠れ時間
}

void ofMole::update() {
    // increase amount of time in our current currentMole
    currentMoleTime++;//隠れ時間増

    // have we gone over our total currentMole time?
    if (currentMoleTime >= totalCurrentMoleTime)//隠れ時間＞＝出現時間
    {
        // switch!
        if (currentMole == 0) {
            
            if(((ofApp*) ofGetAppPtr())->timer >= 0 && ((ofApp*) ofGetAppPtr())->timer <= 4){//①
                if(((ofApp*) ofGetAppPtr())->score % 30 == 0 && ((ofApp*) ofGetAppPtr())->score > 0){//30点間隔//②
                    currentMole = 3;
                }
                else if(((ofApp*) ofGetAppPtr())->star == 10){//②
                    currentMole = 4;
                    ((ofApp*) ofGetAppPtr())->star = 0;
                }
                else{
                currentMole = (int) ofRandom(0, 2);
                }
            }
            
            else if(((ofApp*) ofGetAppPtr())->timer >= 5 && ((ofApp*) ofGetAppPtr())->timer <= 12){//①
            currentMole = (int) ofRandom(0, 3);
            }
            
            else if(((ofApp*) ofGetAppPtr())->timer >= 13 && ((ofApp*) ofGetAppPtr())->timer <= 15){//①
            currentMole = 2;
            }
            
            
        }
        else {
            currentMole = 0;
        }
        
        // reset timers
        resetTimers();
    }
}

void ofMole::display() {
    moles[currentMole].draw(xPos, yPos);
    }

void ofMole::checkHit() {
    //generic
    if (ofDist(((ofApp*) ofGetAppPtr())->mouseX, ((ofApp*) ofGetAppPtr())->mouseY, xPos, yPos) < 70) {
        //if good
        if (currentMole > 0 && currentMole < 2) {
            currentMole = 0;
            ((ofApp*) ofGetAppPtr())->score++;
      }
        if (currentMole == 3) {//②
            currentMole = 0;
            ((ofApp*) ofGetAppPtr())->score++;
            ((ofApp*) ofGetAppPtr())->star++;
            //星集め 5つ集まると5点のモグラが発生
        }
        if (currentMole == 4) {//②
            currentMole = 0;
            ((ofApp*) ofGetAppPtr())->score += 5;
        }
   }
}

void ofMole::moleGameOver() {//①
    ((ofApp*) ofGetAppPtr())->gameOver = true;
}

