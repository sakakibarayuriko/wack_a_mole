#pragma once

#include "ofMain.h"
#include "ofMole.hpp"

#define LENGTH 9

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void displayMoles();
    void checkTimeOver();
    void drawReplayOption();
    void checkReplayHit();
    void displayTimeScore();
    void reset();
    bool isFinished();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofTrueTypeFont font;
    ofImage hammer;
    ofImage star;
    
    ofMole *top[LENGTH-1];
    ofMole *mid1[LENGTH];
    ofMole *mid2[LENGTH];
    ofMole *mid3[LENGTH];
    ofMole *bottom[LENGTH];
    
    bool gameOver;
    
    int score;
    int starScore;
    int timer;
    int time;
    int timeMax;
};
