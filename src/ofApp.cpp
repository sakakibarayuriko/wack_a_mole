
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //画像読み込み
    hammer.load("hammer.png");
    star.load("star.png");
    
    //フォント読み込み
    ofTrueTypeFont::setGlobalDpi(72);
    font.load("SFNSText.ttf", 30);
    
    //時間初期化
    time = ofGetElapsedTimeMillis()/1000;
    timeMax = 15;
    
    //スコアセット
    score = 0;
    starScore = 0;
    
    //穴の位置
    int count = 1;
    for (int i=0; i<LENGTH; i++) {
        if(i<LENGTH-1) top[i] = new ofMole(count*80, 90);
        mid1[i] = new ofMole(count*80, 270);
        mid2[i] = new ofMole(count*80, 450);
        mid3[i] = new ofMole(count*80, 630);
        bottom[i] = new ofMole(count*80, 810);
        count += 2;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    //タイマー
    timer = ofGetElapsedTimeMillis() / 1000 - time;
    //ゲーム中
    if (gameOver == false) {
        //画面描写
        ofBackground(33,215,102);
        ofHideCursor();
        displayMoles();
        displayTimeScore();
        star.draw(1305, 100);
        hammer.draw(mouseX, mouseY);
        
        //終了判定
        checkTimeOver();
        
        //当たり判定
        for (int i=0; i<LENGTH; i++) {
            if(i<LENGTH-1) top[i]->checkHit();
            mid1[i]->checkHit();
            mid2[i]->checkHit();
            mid3[i]->checkHit();
            bottom[i]->checkHit();
        }
    }
    //ゲームオーバー
    else {
        //画面描写
        drawReplayOption();
        //リプレイ
        checkReplayHit();
    }
}

//--------------------------------------------------------------
void ofApp::displayMoles() {
    //モグラ表示
    for (int i=0; i<LENGTH; i++) {
        if(i<LENGTH-1) top[i]->display();
        mid1[i]->display();
        mid2[i]->display();
        mid3[i]->display();
        bottom[i]->display();
    }
    
    //モグラのモーション
    for (int i=0; i<LENGTH; i++) {
        if(i<LENGTH-1) top[i]->update();
        mid1[i]->update();
        mid2[i]->update();
        mid3[i]->update();
        bottom[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::checkTimeOver(){
    //終了している場合
    if (isFinished()) {
        gameOver = true;
    }
}

//--------------------------------------------------------------
void ofApp::drawReplayOption(){
    //画面描写
    ofBackground(0);
    ofShowCursor();
    font.drawString("Game Over", 720 - 83, 450);
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
void ofApp::checkReplayHit(){
    //リプレイボタンにマウスが当たった時
    if (mouseX > (720 - 75) &&  mouseX < (720 + 75) && mouseY < 618 + 25 && mouseY > 618 - 25) {
        //リプレイボタン描写
        ofSetColor(0);
        ofFill();
        ofDrawRectangle(720, 618, 150, 50);
        ofSetColor(255);
        ofFill();
        font.drawString("replay", 720 - 43, 628);
        //リプレイボタンを押した時
        if (ofGetMousePressed()) {
            //ゲーム再スタート
            reset();
        }
    }
}

//--------------------------------------------------------------
void ofApp::displayTimeScore(){
    //スコア描写
    font.drawString("Score: " + ofToString(score) + "\n      × " + ofToString(starScore), 1280,75);
}

//--------------------------------------------------------------
void ofApp::reset(){
    //時間初期化
    time = ofGetElapsedTimeMillis()/1000;
    timeMax = 15;
    
    //スコアセット
    score = 0;
    starScore = 0;
    
    //穴表示
    for (int i=0; i<LENGTH; i++) {
        if(i<LENGTH-1) top[i]->currentMole = 0;
        mid1[i]->currentMole = 0;
        mid2[i]->currentMole = 0;
        mid3[i]->currentMole = 0;
        bottom[i]->currentMole = 0;
    }
    
    //ゲーム再スタート
    gameOver = false;
}

//--------------------------------------------------------------
bool ofApp::isFinished() {
    //タイマー>15秒
    if (timer > timeMax) {
        //ゲームオーバー
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
void ofApp::mouseMoved(int x, int y){
    //時間初期化
    time = ofGetElapsedTimeMillis()/1000;
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
