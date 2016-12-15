#pragma once
#include "ofMain.h"

enum particleMode{
    PARTICLE_MODE_REPEL,
    PARTICLE_MODE_NEAREST_POINTS,
    PARTICLE_MODE_NOISE
};

class Particle{
    
public:
    Particle();
    
    void setMode(particleMode newMode);
    void setAttractPoints( vector <ofPoint> * attract );
    
    void reset();
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    particleMode mode;
    
    vector <ofPoint> * attractPoints;
    
    ofPoint _pos;
    ofPoint _vel;
    ofPoint _frc;
    
    float _drag;
    float _uniqueVal;
    float _scale;
    
    particleMode mode2;
    
    vector <ofPoint> * _attractPoints;
};