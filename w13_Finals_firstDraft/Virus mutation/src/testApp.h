#pragma once

#include "ofMain.h"
//#include "ofxPostGlitch.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
	
	private:
		vector<ofPoint> ofpAgents;
      vector<ofColor> ofcAgentColors;
    vector<ofPoint> ofpAgents2;
    vector<ofColor> ofcAgentColors2;
    vector<ofPoint> ofpAgents3;
    vector<ofColor> ofcAgentColors3;
		int iAgents, iDirection;
    	int iAgents2, iDirection2;
      float fAgentSize, fAgentStep;
      float fAgentSize2, fAgentStep2;
    int iAgents3, iDirection3;
    float fAgentSize3, fAgentStep3;
    
    ofImage image;
    
    ofSoundPlayer bgs;
    
//    ofFbo myFbo;
//    ofxPostGlitch myGlitch;
};
