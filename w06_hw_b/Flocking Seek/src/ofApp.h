#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofPoint dest1, dest2, dest3, dest4, dest5, dest6, dest7, dest8, dest9, dest10, dest11, dest12, dest13, dest14, dest15, dest16, dest17, dest18, dest19, dest20;
    Particle car1, car2, car3, car4, car5, car6, car7, car8, car9, car10, car11, car12, car13, car14, car15, car16, car17, car18, car19, car20;
};
