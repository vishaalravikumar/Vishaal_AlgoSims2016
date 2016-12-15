#include "Particle.hpp"

//------------------------------------------------------------------
Particle::Particle(){
    attractPoints = NULL;
    _attractPoints = NULL;
}

//------------------------------------------------------------------
void Particle::setMode(particleMode newMode){
    mode = newMode;
    mode2 = newMode;
}

//------------------------------------------------------------------
void Particle::setAttractPoints( vector <ofPoint> * attract ){
    attractPoints = attract;
    _attractPoints = attract;
}

//------------------------------------------------------------------
void Particle::reset(){
    //the unique val allows us to set properties slightly differently for each particle
    uniqueVal = ofRandom(-10000, 10000);
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    vel.x = ofRandom(-3.9, 3.9);
    vel.y = ofRandom(-3.9, 3.9);
    
    frc   = ofPoint(0,0,0);
    
    scale = ofRandom(0.5, 1.0);
    
    if( mode == PARTICLE_MODE_NOISE ){
        drag  = ofRandom(0.97, 0.99);
        vel.y = fabs(vel.y) * 3.0; //make the particles all be going down
    }else{
        drag  = ofRandom(0.95, 0.998);	
    }
    
    
//    ----
    
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
void Particle::update(){
    
    if( mode2 == PARTICLE_MODE_REPEL ){
        ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
        _frc = attractPt-_pos;
        
        //let get the distance and only repel points close to the mouse
        float dist = _frc.length();
        _frc.normalize();
        
        _vel *= _drag;
        if( dist < 60 ){
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
    if( _pos.x > ofGetWidth()/2 ){
        _pos.x = ofGetWidth()/2;
        _vel.x *= -1.0;
    }else if( _pos.x < 0 ){
        _pos.x = 0;
        _vel.x *= -1.0;
    }
    if( _pos.y > ofGetHeight()/2 ){
        _pos.y = ofGetHeight()/2;
        _vel.y *= -1.0;
    }
    else if( _pos.y < 0 ){
        _pos.y = 0;
        _vel.y *= -1.0;
    }

    
    //
    
    if( mode == PARTICLE_MODE_REPEL ){
        ofPoint attractPt(ofRandom(4), ofRandom(5));
        frc = attractPt-pos;

        
        //let get the distance and only repel points close to the mouse
        float dist = frc.length();
        frc.normalize();
        
        vel *= drag;
        if( dist < 150 ){
            vel += -frc * 0.6; //notice the frc is negative
        }else{
            //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
            frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
            frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
            vel += frc * 0.04;
        }
    }
    

    if( mode == PARTICLE_MODE_NEAREST_POINTS ){
        
        if( attractPoints ){
            
            //1 - find closest attractPoint
            ofPoint closestPt;
            int closest = -10;
            float closestDist = 9999999;
            
            for(unsigned int i = 0; i < attractPoints->size(); i++){
                float lenSq = ( attractPoints->at(i)-pos ).lengthSquared();
                if( lenSq < closestDist ){
                    closestDist = lenSq;
                    closest = i;
                }
            }
            
            //2 - if we have a closest point - lets calcuate the force towards it
            if( closest != -1 ){
                closestPt = attractPoints->at(closest);
                float dist = sqrt(closestDist);
                
                //in this case we don't normalize as we want to have the force proportional to distance
                frc = closestPt - pos;
                
                vel *= drag;
                
                //lets also limit our attraction to a certain distance and don't apply if 'f' key is pressed
                if( dist < 300 && dist > 15 && !ofGetKeyPressed('f') ){
                    vel += frc * 0.00003;
                }else{
                    //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
                    frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
                    frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
                    vel += frc * 0.4;
                }
                
            }
            
        }
        
    }
    
    //2 - UPDATE OUR POSITION
    
    pos += vel;
    
    
    //3 - (optional) LIMIT THE PARTICLES TO STAY ON SCREEN
    //we could also pass in bounds to check - or alternatively do this at the ofApp level
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }	
    
}

//------------------------------------------------------------------
void Particle::draw(){

    if( mode == PARTICLE_MODE_NEAREST_POINTS ){
        ofSetColor(238, 60, 238);
    }
    if( mode2 == PARTICLE_MODE_REPEL ){
        ofSetColor(ofRandom(70, 90));
    }
    
    ofDrawCircle(pos.x, pos.y, scale * 4.0);
}


