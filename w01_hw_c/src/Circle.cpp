//
//  Circle.cpp
//  w01_hw_c
//
//  Created by Vishaal Ravikumar on 9/18/16.
//
//

#include "Circle.hpp"



void Circle::draw(float _circleSize){
    
    circleSize = _circleSize;
    ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, circleSize);
    
    
    
}

void Circle::update(){
    
    
    
}