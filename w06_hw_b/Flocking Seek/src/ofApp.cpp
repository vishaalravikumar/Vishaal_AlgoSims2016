#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest3 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest4 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest5 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest6 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest7 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest8 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest9 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest10 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest11 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest12 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest13 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest14 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest15 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest16 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest17 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest18 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest19 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest20 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    
    car1.setInit( ofGetWindowSize() / 2, ofPoint(10, -5) );
    car2.setInit( ofGetWindowSize() / 2, ofPoint(10, 5) );
    car3.setInit( ofGetWindowSize() / 2, ofPoint(9, -5) );
    car4.setInit( ofGetWindowSize() / 2, ofPoint(6, 8) );
    car5.setInit( ofGetWindowSize() / 2, ofPoint(2, -8) );
    car6.setInit( ofGetWindowSize() / 2, ofPoint(8, 4) );
    car7.setInit( ofGetWindowSize() / 2, ofPoint(9, -3) );
    car8.setInit( ofGetWindowSize() / 2, ofPoint(10, 9) );
    car9.setInit( ofGetWindowSize() / 2, ofPoint(10, -8) );
    car10.setInit( ofGetWindowSize() / 2, ofPoint(0, 5) );
    car11.setInit( ofGetWindowSize() / 2, ofPoint(9, -5) );
    car12.setInit( ofGetWindowSize() / 2, ofPoint(12, 7) );
    car13.setInit( ofGetWindowSize() / 2, ofPoint(2, -2) );
    car14.setInit( ofGetWindowSize() / 2, ofPoint(0, 3) );
    car15.setInit( ofGetWindowSize() / 2, ofPoint(9, -9) );
    car16.setInit( ofGetWindowSize() / 2, ofPoint(12, 7) );
    car17.setInit( ofGetWindowSize() / 2, ofPoint(8, -1) );
    car18.setInit( ofGetWindowSize() / 2, ofPoint(8, 1) );
    car19.setInit( ofGetWindowSize() / 2, ofPoint(7, 0) );
    car20.setInit( ofGetWindowSize() / 2, ofPoint(0, 7) );
    
    car1.color = ofColor(0,255,0);
    car2.color = ofColor(0,0,255);
    car3.color = ofColor(5,145,0);
    car4.color = ofColor(5,36,236);
    car5.color = ofColor(55,10,112);
    car6.color = ofColor(53,122,145);
    car7.color = ofColor(255,134,13);
    car8.color = ofColor(75,126,63);
    car9.color = ofColor(125,10,10);
    car10.color = ofColor(95,90,90);
    car11.color = ofColor(0,255,0);
    car12.color = ofColor(0,0,255);
    car13.color = ofColor(5,145,0);
    car14.color = ofColor(5,36,236);
    car15.color = ofColor(55,10,112);
    car16.color = ofColor(53,122,145);
    car17.color = ofColor(255,134,133);
    car18.color = ofColor(175,26,163);
    car19.color = ofColor(25,150,130);
    car20.color = ofColor(9,190,190);
    
    ofBackground(255);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // apply steering force
    car1.seek( dest1 );
    car2.seek( dest2 );
    car3.seek( dest3 );
    car4.seek( dest4 );
    car5.seek( dest5 );
    car6.seek( dest6 );
    car7.seek( dest7 );
    car8.seek( dest8 );
    car9.seek( dest9 );
    car10.seek( dest10 );
    car11.seek( dest11 );
    car12.seek( dest12 );
    car13.seek( dest13 );
    car14.seek( dest14 );
    car15.seek( dest15 );
    car16.seek( dest16 );
    car17.seek( dest17 );
    car18.seek( dest18 );
    car19.seek( dest19 );
    car20.seek( dest20 );
    
    // apply repelling force
    float area = 200;
    if( car1.getPosition().distance( car2.getPosition() ) < area ){
        car1.color = ofColor(255,0,0);
        car2.color = ofColor(28,123,0);
        car3.color = ofColor(25,15,0);
        car4.color = ofColor(255,33,56);
        car5.color = ofColor(255,0,12);
        car6.color = ofColor(5,12,45);
        car7.color = ofColor(25,034,03);
        car8.color = ofColor(55,66,33);
        car9.color = ofColor(55,0,0);
        car10.color = ofColor(25,10,10);
        car11.color = ofColor(25,230,0);
        car12.color = ofColor(28,13,0);
        car13.color = ofColor(25,125,0);
        car14.color = ofColor(255,13,56);
        car15.color = ofColor(255,032,122);
        car16.color = ofColor(125,142,145);
        car17.color = ofColor(75,074,03);
        car18.color = ofColor(55,96,33);
        car19.color = ofColor(155,10,0);
        car20.color = ofColor(225,110,190);
        
        car1.addRepulsionForce( car2.getPosition(), area,  0.1 );
        car2.addRepulsionForce( car3.getPosition(), area, 0.1 );
        car3.addRepulsionForce( car4.getPosition(), area,  0.1 );
        car4.addRepulsionForce( car5.getPosition(), area, 0.1 );
        car5.addRepulsionForce( car6.getPosition(), area,  0.1 );
        car6.addRepulsionForce( car7.getPosition(), area, 0.1 );
        car7.addRepulsionForce( car8.getPosition(), area,  0.1 );
        car8.addRepulsionForce( car9.getPosition(), area, 0.1 );
        car9.addRepulsionForce( car10.getPosition(), area,  0.1 );
        car10.addRepulsionForce( car11.getPosition(), area, 0.1 );
        car11.addRepulsionForce( car12.getPosition(), area,  0.1 );
        car12.addRepulsionForce( car13.getPosition(), area, 0.1 );
        car13.addRepulsionForce( car14.getPosition(), area,  0.1 );
        car14.addRepulsionForce( car15.getPosition(), area, 0.1 );
        car15.addRepulsionForce( car16.getPosition(), area,  0.1 );
        car16.addRepulsionForce( car17.getPosition(), area, 0.1 );
        car17.addRepulsionForce( car18.getPosition(), area,  0.1 );
        car18.addRepulsionForce( car19.getPosition(), area, 0.1 );
        car19.addRepulsionForce( car20.getPosition(), area,  0.1 );
        car20.addRepulsionForce( car1.getPosition(), area, 0.1 );
    }else{
        car1.color = ofColor(0,255,0);
        car2.color = ofColor(0,0,255);
        car3.color = ofColor(5,145,0);
        car4.color = ofColor(5,36,236);
        car5.color = ofColor(55,10,112);
        car6.color = ofColor(53,122,145);
        car7.color = ofColor(255,134,13);
        car8.color = ofColor(75,126,63);
        car9.color = ofColor(125,10,10);
        car10.color = ofColor(95,90,90);
        car11.color = ofColor(0,255,0);
        car12.color = ofColor(0,0,255);
        car13.color = ofColor(5,145,0);
        car14.color = ofColor(5,36,236);
        car15.color = ofColor(55,10,112);
        car16.color = ofColor(53,122,145);
        car17.color = ofColor(255,134,133);
        car18.color = ofColor(175,26,163);
        car19.color = ofColor(25,150,130);
        car20.color = ofColor(9,190,190);
    }
    
    // update physics
    car1.update();
    car2.update();
    car3.update();
    car4.update();
    car5.update();
    car6.update();
    car7.update();
    car8.update();
    car9.update();
    car10.update();
    car11.update();
    car12.update();
    car13.update();
    car14.update();
    car15.update();
    car16.update();
    car17.update();
    car18.update();
    car19.update();
    car20.update();
    
    if( car1.getPosition().distance(dest1) < 5){
        dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car2.getPosition().distance(dest2) < 5){
        dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car3.getPosition().distance(dest3) < 6){
        dest3 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car4.getPosition().distance(dest4) < 8){
        dest4 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car5.getPosition().distance(dest5) < 6){
        dest5 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car6.getPosition().distance(dest6) < 5){
        dest6 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car7.getPosition().distance(dest7) < 5){
        dest7 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car8.getPosition().distance(dest8) < 5){
        dest8 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car9.getPosition().distance(dest9) < 5){
        dest9 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car10.getPosition().distance(dest10) < 5){
        dest10 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car11.getPosition().distance(dest11) < 5){
        dest11 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car12.getPosition().distance(dest12) < 5){
        dest12 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car13.getPosition().distance(dest13) < 5){
        dest13 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car14.getPosition().distance(dest14) < 5){
        dest14 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car15.getPosition().distance(dest15) < 6){
        dest15 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car16.getPosition().distance(dest16) < 5){
        dest16 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car17.getPosition().distance(dest17) < 5){
        dest17 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car18.getPosition().distance(dest18) < 5){
        dest8 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car19.getPosition().distance(dest19) < 5){
        dest19 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car20.getPosition().distance(dest20) < 5){
        dest20 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofSetColor( car1.color );
    ofCircle( dest1, 4 );
    car1.draw();
    
    ofSetColor( car2.color );
    ofCircle( dest2, 4 );
    car2.draw();
    
    ofSetColor( car3.color );
    ofCircle( dest3, 4 );
    car3.draw();
    
    ofSetColor( car4.color );
    ofCircle( dest4, 4 );
    car4.draw();
    
    ofSetColor( car5.color );
    ofCircle( dest5, 4 );
    car5.draw();
    
    ofSetColor( car6.color );
    ofCircle( dest6, 4 );
    car6.draw();
    
    ofSetColor( car7.color );
    ofCircle( dest7, 4 );
    car7.draw();
    
    ofSetColor( car8.color );
    ofCircle( dest8, 4 );
    car8.draw();
    
    ofSetColor( car9.color );
    ofCircle( dest9, 4 );
    car9.draw();
    
    ofSetColor( car10.color );
    ofCircle( dest10, 4 );
    car10.draw();
    
    ofSetColor( car11.color );
    ofCircle( dest11, 4 );
    car11.draw();
    
    ofSetColor( car12.color );
    ofCircle( dest12, 4 );
    car12.draw();
    
    ofSetColor( car13.color );
    ofCircle( dest13, 4 );
    car13.draw();
    
    ofSetColor( car14.color );
    ofCircle( dest14, 4 );
    car14.draw();
    
    ofSetColor( car15.color );
    ofCircle( dest15, 4 );
    car15.draw();
    
    ofSetColor( car16.color );
    ofCircle( dest16, 4 );
    car16.draw();
    
    ofSetColor( car17.color );
    ofCircle( dest17, 4 );
    car17.draw();
    
    ofSetColor( car18.color );
    ofCircle( dest18, 4 );
    car18.draw();
    
    ofSetColor( car19.color );
    ofCircle( dest19, 4 );
    car19.draw();
    
    ofSetColor( car20.color );
    ofCircle( dest20, 4 );
    car20.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}