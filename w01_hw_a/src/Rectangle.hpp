//
//  Rectangle.hpp
//  Homework 1
//
//  Created by Vishaal Ravikumar on 9/16/16.
//
//

#pragma once

#include "ofMain.h"

class rectangle {
    
public:
    rectangle();
    
    void draw();
    void interpolateByPct(float myPct);
    
    ofPoint pos, posa, posb;
    
    float pct;
    float shaper;
    
    
};