//
//  Planets.hpp
//  Planets homework 1
//
//  Created by Vishaal Ravikumar on 9/28/16.
//
//
#pragma once

#include "ofMain.h"

class PlanetClass{
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameterGroup planetGroup;
    ofParameter<float> rotateSpeed;
    ofParameter<float> posX;
    ofParameter<float> posY;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    
    float rotation = 0.0;
    
    
};