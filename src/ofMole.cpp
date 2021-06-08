//
//  Mole.cpp
//
//  Created by 榊原ゆり子 on 2018/07/16.
//

#include "ofMole.hpp"
#include "ofApp.h"

ofMole::ofMole(float x, float y) {
    xPos = x;
    yPos = y;
    
    //穴が表示される
    currentMole = 0;
    
    //モグラの画像読み込み
    for (int i = 0; i < TYPE_LENGTH; i++) {
        moles[i].load("mole" + ofToString(i) + ".png");
    }
    
    //時間セット
    resetTimers();
}

void ofMole::resetTimers() {
    //出現時間
    appearanceTime = ofRandom(50, 600);
    //隠れ時間
    hiddenTime = 0;
}

void ofMole::update() {
    //隠れ時間増える
    hiddenTime++;
    
    //隠れ時間>=出現時間
    if (hiddenTime >= appearanceTime) {
        //穴が表示されている時
        if (currentMole == 0) {
            //タイマーが0秒〜4秒しか進んでいない時
            if(((ofApp*) ofGetAppPtr())->timer >= 0 && ((ofApp*) ofGetAppPtr())->timer <= 4) {
                //30点間隔
                if(((ofApp*) ofGetAppPtr())->score % 30 == 0 && ((ofApp*) ofGetAppPtr())->score > 0) {
                    //星を持ったモグラが現れる
                    currentMole = 3;
                }
                //星が10個集まった
                else if(((ofApp*) ofGetAppPtr())->starScore == 10) {
                    //王冠のモグラが現れる
                    currentMole = 4;
                    //星がリセットされる
                    ((ofApp*) ofGetAppPtr())->starScore = 0;
                }
                else{
                    //穴か普通のモグラがランダムで表示される
                    currentMole = ofRandom(0, 2);
                }
            }
            //タイマーが5秒〜12秒進んだ時
            else if(((ofApp*) ofGetAppPtr())->timer >= 5 && ((ofApp*) ofGetAppPtr())->timer <= 12) {
                //怒ったモグラか穴が表示される
                currentMole = ofRandom(0, 3);
            }
            //タイマーが13秒〜15秒進んだ時
            else if(((ofApp*) ofGetAppPtr())->timer >= 13 && ((ofApp*) ofGetAppPtr())->timer <= 15) {
                //怒ったモグラが表示される
                currentMole = 2;
            }
        } else {
            //穴が表示される
            currentMole = 0;
        }
        //時間セット
        resetTimers();
    }
}

void ofMole::display() {
    //描写されるモグラの種類と場所
    moles[currentMole].draw(xPos, yPos);
}

void ofMole::checkHit() {
    //ハンマーがモグラに当たった時
    if (ofDist(((ofApp*) ofGetAppPtr())->mouseX, ((ofApp*) ofGetAppPtr())->mouseY, xPos, yPos) < 70) {
        switch(currentMole) {
            //普通のモグラ
            case 1:
                //穴が表示される
                currentMole = 0;
                //1点加算される
                ((ofApp*) ofGetAppPtr())->score++;
                break;
            //怒ったモグラ
            case 2:
                //穴が表示される
                currentMole = 0;
                //1点加算される
                ((ofApp*) ofGetAppPtr())->score++;
                break;
            //星を持ったモグラ
            case 3:
                //穴が表示される
                currentMole = 0;
                //1点加算される
                ((ofApp*) ofGetAppPtr())->score++;
                //星が加算される
                ((ofApp*) ofGetAppPtr())->starScore++;
            //王冠のモグラ
            case 4:
                //穴が表示される
                currentMole = 0;
                //5点加算される
                ((ofApp*) ofGetAppPtr())->score += 5;
            default:
                break;
        }
    }
}
