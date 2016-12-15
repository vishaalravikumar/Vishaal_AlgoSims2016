#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    bgs.load("drums.mp3");
    bgs.setVolume(0.5);
    bgs.play();
    bgs.setLoop(true);
    bgs.setSpeed(1);
    
    
    image.load("pixelPicture.png");
    
    ofSetColor(100, 0, 100);
    
    ofSetVerticalSync(true);
    
    int num = 1500;
    p.assign(num, Particle());
    currentMode = PARTICLE_MODE_NEAREST_POINTS;
    
    _p.assign(num, Particle());
    _currentMode = PARTICLE_MODE_REPEL;
    
    resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){
    
    attractPoints.clear();
    for(int i = 0; i < 4; i++){
        attractPoints.push_back( ofPoint( ofMap(i, 0, 4, 20, ofGetWidth()-100) , ofRandom(20, ofGetHeight()-100) ) );
    }
    
    attractPointsWithMovement = attractPoints;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setMode(currentMode);
        p[i].setAttractPoints(&attractPointsWithMovement);;
        p[i].reset();
    }
    
    _attractPoints.clear();
    for(int i = 0; i < 4; i++){
        _attractPoints.push_back( ofPoint( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) ) );
    }
    
    _attractPointsWithMovement = _attractPoints;
    
    for(unsigned int i = 0; i < p.size(); i++){
        _p[i].setMode(_currentMode);
        _p[i].setAttractPoints(&_attractPointsWithMovement);;
        _p[i].reset();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setMode(currentMode);
        p[i].update();
    }
    
    //lets add a bit of movement to the attract points
    for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
        attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 4, ofGetElapsedTimef() * 0.2) * 4.0;
        attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -4, ofGetElapsedTimef() * 0.2) * 4.0;
    }
    
    for(unsigned int i = 0; i < p.size(); i++){
        _p[i].setMode(_currentMode);
        _p[i].update();
    }
    
    //lets add a bit of movement to the attract points
    for(unsigned int i = 0; i < _attractPointsWithMovement.size(); i++){
        _attractPointsWithMovement[i].x = _attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
        _attractPointsWithMovement[i].y = _attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
        ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));
    
    
    for(unsigned int i = 0; i < _p.size(); i++){
        _p[i].draw();
    }
    
    ofSetColor(190);
    if( _currentMode == PARTICLE_MODE_REPEL ){
        for(unsigned int i = 0; i < _attractPoints.size(); i++){
        }
    }
    //
    
        for(unsigned int i = 0; i < p.size(); i++){
            p[i].draw();
        }
    
        ofSetColor(190);
        if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
            for(unsigned int i = 0; i < attractPoints.size(); i++){
                ofNoFill();
                ofDrawCircle(attractPointsWithMovement[i], 8);
                ofSetColor(208, 255, 63);
                ofDrawCircle(attractPointsWithMovement[i], 9);
            }
        }
    
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
 
    
    }


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == ' ' ){
        resetParticles();
    }
}
