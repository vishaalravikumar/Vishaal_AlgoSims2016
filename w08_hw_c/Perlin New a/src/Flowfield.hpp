//
//  Flowfield.hpp
//  Perlin New a
//
//  Created by Vishaal Ravikumar on 11/2/16.
//
//

#pragma once

#include "ofMain.h"

class Flowfield {
public:
    
    void setup (int _width, int _height, int _depth, int _resolution);
    void update ();
    void draw ();
    void setPerlin();
    ofVec3f getForceAtPosition( ofVec3f pos );
    
    int width, height, depth, resolution;
    vector < vector< vector<ofVec3f> > > flowList;
    
};