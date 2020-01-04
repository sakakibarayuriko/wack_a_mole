
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //画像を表示するときに中心を指定するモードを設定
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //load image
    hammer.load("hammer.png");
    hosi.load("star.png");//②
    
    //loadfont
    ofTrueTypeFont::setGlobalDpi(72);
    font.load("SFNSText.ttf", 30);
    
    //set param in new Timer to amount of seconds you want the game to last
    time = ofGetElapsedTimeMillis()/1000;//①
    timeMax = 15;//①
    
    //穴の位置
    topRight = new ofMole(80, 90);
    topCenter1 = new ofMole(240, 90);
    topCenter2 = new ofMole(400, 90);
    topCenter3 = new ofMole(560, 90);
    topCenter4 = new ofMole(720, 90);
    topCenter5 = new ofMole(880, 90);
    topCenter6 = new ofMole(1040, 90);
    topCenter7 = new ofMole(1200, 90);
    
    mid1Right = new ofMole(80, 270);
    mid1Center1 = new ofMole(240, 270);
    mid1Center2 = new ofMole(400, 270);
    mid1Center3 = new ofMole(560, 270);
    mid1Center4 = new ofMole(720, 270);
    mid1Center5 = new ofMole(880, 270);
    mid1Center6 = new ofMole(1040, 270);
    mid1Center7 = new ofMole(1200, 270);
    mid1Left = new ofMole(1360, 270);
    
    mid2Right = new ofMole(80, 450);
    mid2Center1 = new ofMole(240, 450);
    mid2Center2 = new ofMole(400, 450);
    mid2Center3 = new ofMole(560, 450);
    mid2Center4 = new ofMole(720, 450);
    mid2Center5 = new ofMole(880, 450);
    mid2Center6 = new ofMole(1040, 450);
    mid2Center7 = new ofMole(1200, 450);
    mid2Left = new ofMole(1360, 450);
    
    mid3Right = new ofMole(80, 630);
    mid3Center1 = new ofMole(240, 630);
    mid3Center2 = new ofMole(400, 630);
    mid3Center3 = new ofMole(560, 630);
    mid3Center4 = new ofMole(720, 630);
    mid3Center5 = new ofMole(880, 630);
    mid3Center6 = new ofMole(1040, 630);
    mid3Center7 = new ofMole(1200, 630);
    mid3Left = new ofMole(1360, 630);
    
    bottomRight = new ofMole(80, 810);
    bottomCenter1 = new ofMole(240, 810);
    bottomCenter2 = new ofMole(400, 810);
    bottomCenter3 = new ofMole(560, 810);
    bottomCenter4 = new ofMole(720, 810);
    bottomCenter5 = new ofMole(880, 810);
    bottomCenter6 = new ofMole(1040, 810);
    bottomCenter7 = new ofMole(1200, 810);
    bottomLeft = new ofMole(1360, 810);
    
    //スコアを0に
    score = 0;
    star = 0;//②
    
    //state = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    /*timer = ofGetElapsedTimeMillis() / 1000 - time;
     
     nextState= 0;
     
     if(state == 0){ nextState = game(); }
     else if(state == 1){ nextState = ending(); }
     
     if(state != nextState){ time = ofGetElapsedTimeMillis() / 1000; } // 状態が遷移するので、現在の状態になった時刻を更新する
     state = nextState;*/
    
    if (gameOver == false) {//①
        //ofBackground(0);
        ofBackground(33,215,102);
        ofHideCursor();
        
        displayMoles();
        displayTimeScore();
        checkTimeOver();
        
        //ハンマーを表示
        hammer.draw(mouseX, mouseY);
        hosi.draw(1305, 100);//②
        
        topRight->checkHit();
        topCenter1->checkHit();
        topCenter2->checkHit();
        topCenter3->checkHit();
        topCenter4->checkHit();
        topCenter5->checkHit();
        topCenter6->checkHit();
        topCenter7->checkHit();
        
        mid1Right->checkHit();
        mid1Center1->checkHit();
        mid1Center2->checkHit();
        mid1Center3->checkHit();
        mid1Center4->checkHit();
        mid1Center5->checkHit();
        mid1Center6->checkHit();
        mid1Center7->checkHit();
        mid1Left->checkHit();
        
        mid2Right->checkHit();
        mid2Center1->checkHit();
        mid2Center2->checkHit();
        mid2Center3->checkHit();
        mid2Center4->checkHit();
        mid2Center5->checkHit();
        mid2Center6->checkHit();
        mid2Center7->checkHit();
        mid2Left->checkHit();
        
        mid3Right->checkHit();
        mid3Center1->checkHit();
        mid3Center2->checkHit();
        mid3Center3->checkHit();
        mid3Center4->checkHit();
        mid3Center5->checkHit();
        mid3Center6->checkHit();
        mid3Center7->checkHit();
        mid3Left->checkHit();
        
        bottomRight->checkHit();
        bottomCenter1->checkHit();
        bottomCenter2->checkHit();
        bottomCenter3->checkHit();
        bottomCenter4->checkHit();
        bottomCenter5->checkHit();
        bottomCenter6->checkHit();
        bottomCenter7->checkHit();
        bottomLeft->checkHit();
    }
    
    else {//gameOver is true//①
        drawReplayOption();
        checkReplayHit();
    }
    
}

//--------------------------------------------------------------
void ofApp::displayMoles() {
    topRight->display();
    topCenter1->display();
    topCenter2->display();
    topCenter3->display();
    topCenter4->display();
    topCenter5->display();
    topCenter6->display();
    topCenter7->display();
    
    mid1Right->display();
    mid1Center1->display();
    mid1Center2->display();
    mid1Center3->display();
    mid1Center4->display();
    mid1Center5->display();
    mid1Center6->display();
    mid1Center7->display();
    mid1Left->display();
    
    mid2Right->display();
    mid2Center1->display();
    mid2Center2->display();
    mid2Center3->display();
    mid2Center4->display();
    mid2Center5->display();
    mid2Center6->display();
    mid2Center7->display();
    mid2Left->display();
    
    mid3Right->display();
    mid3Center1->display();
    mid3Center2->display();
    mid3Center3->display();
    mid3Center4->display();
    mid3Center5->display();
    mid3Center6->display();
    mid3Center7->display();
    mid3Left->display();
    
    bottomRight->display();
    bottomCenter1->display();
    bottomCenter2->display();
    bottomCenter3->display();
    bottomCenter4->display();
    bottomCenter5->display();
    bottomCenter6->display();
    bottomCenter7->display();
    bottomLeft->display();
    
    topRight->update();
    topCenter1->update();
    topCenter2->update();
    topCenter3->update();
    topCenter4->update();
    topCenter5->update();
    topCenter6->update();
    topCenter7->update();
    
    mid1Right->update();
    mid1Center1->update();
    mid1Center2->update();
    mid1Center3->update();
    mid1Center4->update();
    mid1Center5->update();
    mid1Center6->update();
    mid1Center7->update();
    mid1Left->update();
    
    mid2Right->update();
    mid2Center1->update();
    mid2Center2->update();
    mid2Center3->update();
    mid2Center4->update();
    mid2Center5->update();
    mid2Center6->update();
    mid2Center7->update();
    mid2Left->update();
    
    mid3Right->update();
    mid3Center1->update();
    mid3Center2->update();
    mid3Center3->update();
    mid3Center4->update();
    mid3Center5->update();
    mid3Center6->update();
    mid3Center7->update();
    mid3Left->update();
    
    bottomRight->update();
    bottomCenter1->update();
    bottomCenter2->update();
    bottomCenter3->update();
    bottomCenter4->update();
    bottomCenter5->update();
    bottomCenter6->update();
    bottomCenter7->update();
    bottomLeft->update();
}

//--------------------------------------------------------------
void ofApp::checkTimeOver(){//①
    if (isFinished()) {
        mid2Center4->moleGameOver();
    }
}

//--------------------------------------------------------------
void ofApp::drawReplayOption(){//①
    ofBackground(0);
    ofShowCursor();
    font.drawString("Game Over"/*\nScore = " + ofToString(score)*/, 720 - 83, 450);
    
    //リプレイ
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255);
    ofFill();
    ofDrawRectangle(720, 618, 150, 50);
    ofSetColor(0);
    ofFill();
    font.drawString("replay", 720 - 43, 628);
    ofSetColor(255);
    ofFill();
}

//--------------------------------------------------------------
void ofApp::checkReplayHit(){//①
    //if click on replay
    if (mouseX > (720 - 75) &&  mouseX < (720 + 75) && mouseY < 618 + 25 && mouseY > 618 - 25) {
        ofSetColor(0);
        ofFill();
        ofDrawRectangle(720, 618, 150, 50);
        ofSetColor(255);
        ofFill();
        font.drawString("replay", 720 - 43, 628);
        if (ofGetMousePressed()) {
            reset();
        }
    }
}

//--------------------------------------------------------------
void ofApp::displayTimeScore(){
    font.drawString("Score: " + ofToString(score) + "\n      × " + ofToString(star), 1280,75);
    //font.drawString("Time: " + ofToString(timeMax - timer) + "\nScore: " + ofToString(score), 1280,75);
}


//--------------------------------------------------------------
void ofApp::reset(){
    score = 0;
    star = 0;
    timeMax = 15;//①
    time = ofGetElapsedTimeMillis()/1000;//①
    
    topRight->currentMole = 0;
    topCenter1->currentMole = 0;
    topCenter2->currentMole = 0;
    topCenter3->currentMole = 0;
    topCenter4->currentMole = 0;
    topCenter5->currentMole = 0;
    topCenter6->currentMole = 0;
    topCenter7->currentMole = 0;
    
    
    mid1Right->currentMole = 0;
    mid1Center1->currentMole = 0;
    mid1Center2->currentMole = 0;
    mid1Center3->currentMole = 0;
    mid1Center4->currentMole = 0;
    mid1Center5->currentMole = 0;
    mid1Center6->currentMole = 0;
    mid1Center7->currentMole = 0;
    mid1Left->currentMole = 0;
    
    mid2Right->currentMole = 0;
    mid2Center1->currentMole = 0;
    mid2Center2->currentMole = 0;
    mid2Center3->currentMole = 0;
    mid2Center4->currentMole = 0;
    mid2Center5->currentMole = 0;
    mid2Center6->currentMole = 0;
    mid2Center7->currentMole = 0;
    mid2Left->currentMole = 0;
    
    mid3Right->currentMole = 0;
    mid3Center1->currentMole = 0;
    mid3Center2->currentMole = 0;
    mid3Center3->currentMole = 0;
    mid3Center4->currentMole = 0;
    mid3Center5->currentMole = 0;
    mid3Center6->currentMole = 0;
    mid3Center7->currentMole = 0;
    mid3Left->currentMole = 0;
    
    bottomRight->currentMole = 0;
    bottomCenter1->currentMole = 0;
    bottomCenter2->currentMole = 0;
    bottomCenter3->currentMole = 0;
    bottomCenter4->currentMole = 0;
    bottomCenter5->currentMole = 0;
    bottomCenter6->currentMole = 0;
    bottomCenter7->currentMole = 0;
    bottomLeft->currentMole = 0;
    
    gameOver = false;
    draw();
    
}

//--------------------------------------------------------------
bool ofApp::isFinished() {//①
    timer = ofGetElapsedTimeMillis()/1000 - time; //seconds
    if (timer > timeMax) {
        return true;
    }
    else {
        return false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){//①
    time = 0;
    timer = 0;
    time = ofGetElapsedTimeMillis()/1000; //seconds
    timer = ofGetElapsedTimeMillis()/1000 - time; //seconds
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
