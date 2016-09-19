//
//  rectangle.hpp
//  w01_hw_d
//
//  Created by Vishaal Ravikumar on 9/19/16.
//
//

#pragma once
#include "ofMain.h"

class Rectangle{
    
public:
    //constructor
    Rectangle();
    
    void draw(float _color);
    void xenoToPoint(float catchX, float catchY);
    
    ofPoint pos;
    
    float catchUpSpeed;
};