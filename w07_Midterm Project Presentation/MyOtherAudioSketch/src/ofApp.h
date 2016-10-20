#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        void audioOut(float* buffer, int bufferSize, int nChannels);
    
        void audioIn(float * input, int bufferSize, int nChannels);

		void mouseMoved(int x, int y);
        void exit();
    
    float myArray[100];
    float frequency;
    float phase;
    float phaseInc;
    float amplitude;
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int bufferCounter;
    int drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    
    
};
