#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(180);
    ofBackground(0);
    
    soundStream.printDeviceList();
    
    frequency = 440;
    amplitude = 0.1;
    phase = 0;
    phaseInc = (TWO_PI * frequency) / (float)48000;
    
    
    //2 is output channels, input is 0, samp rate is 48000, buffer size is 512, number of buffers is 4
    
    int bufferSize = 900;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 3;
    smoothedVol     = 2.0;
    scaledVol		= 2.0;
    
    ofSoundStreamSetup(2, 0, 48000, 512, 4);
    soundStream.setup(this, 0, 2, 48000, bufferSize, 4);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }


}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, -50, 0);
    
    
    ofSetColor(245, 58, 135);
    ofSetLineWidth(1);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 20, 0);
    
    
    ofSetColor(24, 158, 15);
    ofSetLineWidth(1);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 90, 0);
    
    
    ofSetColor(35, 208, 35);
    ofSetLineWidth(1.5);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 160, 0);
    
    
    ofSetColor(100, 158, 100);
    ofSetLineWidth(2);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 230, 0);
    
    
    ofSetColor(200, 250, 235);
    ofSetLineWidth(2.5);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    // draw the left channel:
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 300, 0);
    
    ofSetColor(24, 58, 235);
    ofSetLineWidth(3);
    
    ofBeginShape();
    for (unsigned int i = 0; i < left.size(); i++){
        ofVertex(i*2, 100 -left[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    // draw the right channel:
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 370, 0);
    
    
    ofSetColor(245, 250, 5);
    ofSetLineWidth(3.5);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 440, 0);
    
    
    ofSetColor(100, 158, 10);
    ofSetLineWidth(4);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 510, 0);
    
    
    ofSetColor(100, 58, 235);
    ofSetLineWidth(4.5);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 580, 0);
    
    
    ofSetColor(245, 190, 15);
    ofSetLineWidth(5);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(0, 650, 0);
    
    
    ofSetColor(135, 58, 245);
    ofSetLineWidth(5.5);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*2, 100 -right[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
    
    
    
    //    drawCounter++;
    //
    //    ofSetColor(225);
    //    string reportString = "buffers received: "+ofToString(bufferCounter)+"\ndraw routines called: "+ofToString(drawCounter)+"\nticks: " + ofToString(soundStream.getTickCount());
    //    ofDrawBitmapString(reportString, 32, 589);
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    if( key == 's' ){
        soundStream.start();
    }
    
    if( key == 'e' ){
        soundStream.stop();
    }
}

//--------------------------------------------------------------

void ofApp::audioOut(float* buffer, int bufferSize, int nChannels){
    
    for(int i = 0; i < bufferSize; i++){
        
        float currentSample = 0;
        
        currentSample = sin(phase) * amplitude;
        phase = phase + phaseInc;
        
        buffer[i * nChannels + 0] = currentSample; // left
        buffer[i * nChannels + 1] = currentSample; // right
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    frequency = ofMap(x, 0, ofGetWidth(), 40, 2000);
    phaseInc = (TWO_PI*frequency) / (float)44000;
    amplitude = ofMap(y, 0, ofGetHeight(), 1, 0);

}

                       
//--------------------------------------------------------------
void ofApp::exit(){
    
    ofSoundStreamClose();
    
}