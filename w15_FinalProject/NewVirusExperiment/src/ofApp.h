#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void resetParticles();
    
    void keyPressed  (int key);
    
    particleMode currentMode;
    string currentModeStr;
    
    vector <Particle> p;
    vector <ofPoint> attractPoints;
    vector <ofPoint> attractPointsWithMovement;
    
    particleMode _currentMode;
    string _currentModeStr;
    
    vector <Particle> _p;
    vector <ofPoint> _attractPoints;
    vector <ofPoint> _attractPointsWithMovement;
    
    ofImage image;
    
    ofSoundPlayer bgs;
    
};