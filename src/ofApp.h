#pragma once

#include "ofMain.h"
#include "ofMole.hpp"

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
    ofMole *topRight;
    ofMole *topCenter1;
    ofMole *topCenter2;
    ofMole *topCenter3;
    ofMole *topCenter4;
    ofMole *topCenter5;
    ofMole *topCenter6;
    ofMole *topCenter7;
    
    ofMole *mid1Right;
    ofMole *mid1Center1;
    ofMole *mid1Center2;
    ofMole *mid1Center3;
    ofMole *mid1Center4;
    ofMole *mid1Center5;
    ofMole *mid1Center6;
    ofMole *mid1Center7;
    ofMole *mid1Left;
    
    ofMole *mid2Right;
    ofMole *mid2Center1;
    ofMole *mid2Center2;
    ofMole *mid2Center3;
    ofMole *mid2Center4;
    ofMole *mid2Center5;
    ofMole *mid2Center6;
    ofMole *mid2Center7;
    ofMole *mid2Left;
    
    ofMole *mid3Right;
    ofMole *mid3Center1;
    ofMole *mid3Center2;
    ofMole *mid3Center3;
    ofMole *mid3Center4;
    ofMole *mid3Center5;
    ofMole *mid3Center6;
    ofMole *mid3Center7;
    ofMole *mid3Left;
    
    ofMole *bottomRight;
    ofMole *bottomCenter1;
    ofMole *bottomCenter2;
    ofMole *bottomCenter3;
    ofMole *bottomCenter4;
    ofMole *bottomCenter5;
    ofMole *bottomCenter6;
    ofMole *bottomCenter7;
    ofMole *bottomLeft;
    
    bool gameOver;
    
    int score;
    int starScore;
    
    int timer;
    int time;
    int timeMax;
};
