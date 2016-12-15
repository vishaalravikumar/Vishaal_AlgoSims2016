#include "Particle2.hpp"

//------------------------------------------------------------------
Particle2::Particle2(){
    _attractPoints = NULL;
}

//------------------------------------------------------------------
void Particle2::setMode(particleMode newMode){
    mode2 = newMode;
}

//------------------------------------------------------------------
void Particle2::setAttractPoints( vector <ofPoint> * attract ){
    _attractPoints = attract;
}

//------------------------------------------------------------------
void Particle2::reset(){
    //the unique val allows us to set properties slightly differently for each particle
    _uniqueVal = ofRandom(-10000, 10000);
    
    _pos.x = ofRandomWidth();
    _pos.y = ofRandomHeight();
    
    _vel.x = ofRandom(-3.9, 3.9);
    _vel.y = ofRandom(-3.9, 3.9);
    
    _frc   = ofPoint(0,0,0);
    
    _scale = ofRandom(0.5, 1.0);
    
    if( mode2 == PARTICLE_MODE_NOISE ){
        _drag  = ofRandom(0.97, 0.99);
        _vel.y = fabs(_vel.y) * 3.0; //make the particles all be going down
    }else{
        _drag  = ofRandom(0.95, 0.998);
    }
}

//------------------------------------------------------------------
void Particle2::update(){
    
    if( mode2 == PARTICLE_MODE_REPEL ){
        ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
        _frc = attractPt-_pos;
        
        //let get the distance and only repel points close to the mouse
        float dist = _frc.length();
        _frc.normalize();
        
        _vel *= _drag;
        if( dist < 150 ){
            _vel += -_frc * 0.6; //notice the frc is negative
        }else{
            //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
            _frc.x = ofSignedNoise(_uniqueVal, _pos.y * 0.01, ofGetElapsedTimef()*0.2);
            _frc.y = ofSignedNoise(_uniqueVal, _pos.x * 0.01, ofGetElapsedTimef()*0.2);
            _vel += _frc * 0.04;
        }
    }
    
    //2 - UPDATE OUR POSITION
    
    _pos += _vel;
    
    
    //3 - (optional) LIMIT THE PARTICLES TO STAY ON SCREEN
    //we could also pass in bounds to check - or alternatively do this at the ofApp level
    if( _pos.x > ofGetWidth() ){
        _pos.x = ofGetWidth();
        _vel.x *= -1.0;
    }else if( _pos.x < 0 ){
        _pos.x = 0;
        _vel.x *= -1.0;
    }
    if( _pos.y > ofGetHeight() ){
        _pos.y = ofGetHeight();
        _vel.y *= -1.0;
    }
    else if( _pos.y < 0 ){
        _pos.y = 0;
        _vel.y *= -1.0;
    }
    
}

//------------------------------------------------------------------
void Particle2::draw(){
    
    if( mode2 == PARTICLE_MODE_REPEL ){
        ofSetColor(103, 160, 237);
    }
    
    ofDrawCircle(_pos.x, _pos.y, _scale * 4.0);
}

