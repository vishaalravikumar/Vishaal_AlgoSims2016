#pragma once
#include "ofMain.h"

enum particleMode{
    PARTICLE_MODE_REPEL,
    PARTICLE_MODE_NEAREST_POINTS,
    PARTICLE_MODE_NOISE
};

class Particle2{
    
public:
    Particle2();
    
    void setMode(particleMode newMode);
    void setAttractPoints( vector <ofPoint> * attract );
    
    void reset();
    void update();
    void draw();
    
    ofPoint _pos;
    ofPoint _vel;
    ofPoint _frc;
    
    float _drag;
    float _uniqueVal;
    float _scale;
    
    particleMode mode2;
    
    vector <ofPoint> * _attractPoints;
};