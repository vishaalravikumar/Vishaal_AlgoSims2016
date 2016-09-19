//
//  Circle.hpp
//  w01_hw_c
//
//  Created by Vishaal Ravikumar on 9/18/16.
//
//

#pragma once
#include "ofMain.h"


class Circle{
    
    
public:
    
    void draw(float _circleSize);
    void update();
    
    void powUpdatePct(float _pct, float _shaper);
    
    
    
private:
    //    ofPoint pos;
    float circleSize;
};