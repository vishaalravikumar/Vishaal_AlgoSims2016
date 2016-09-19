//
//  Rectangle.hpp
//  w01_hw_b
//
//  Created by Vishaal Ravikumar on 9/18/16.
//
//

#pragma once

#include "ofMain.h"

class rectangle {
    
public:
    rectangle();
    
    void draw();
    void interpolateByPct(float myPct);
    void resetAB();
    
    ofPoint pos, posa, posb;
    
    float pct;
    float shaper;
    
    
};