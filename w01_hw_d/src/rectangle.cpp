//
//  rectangle.cpp
//  w01_hw_d
//
//  Created by Vishaal Ravikumar on 9/19/16.
//
//

#include "rectangle.hpp"

Rectangle::Rectangle(){
    catchUpSpeed = ofRandom(0.08);
    //    cout<<  _x  <<endl;
}

void Rectangle::draw(float _color){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(_color,_color,_color);
    ofDrawRectangle(pos.x,pos.y,40,40);
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    //myPos = (1-pct) * myPos + pct * targetPos
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}