#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
//    myFbo.allocate(640,480);
//    myGlitch.setup(&myFbo);

    
    bgs.load("drums.mp3");
    bgs.setVolume(0.5);
    bgs.play();
    bgs.setLoop(true);
    bgs.setSpeed(.36);

    
    image.load("pixelPicture.png");
    
	ofBackground( 0, 0, 0 );
   // no background repainting
	ofSetBackgroundAuto( false );

   // some grafical niceness
   ofEnableAlphaBlending();
   ofEnableSmoothing();

   // how many agents we want on screen
    
	iAgents = 40;
    iAgents2 = 8;
    iAgents3 = 13;

	ofpAgents.resize( iAgents );
    ofcAgentColors.resize( iAgents );
    ofpAgents2.resize( iAgents2 );
    ofcAgentColors2.resize( iAgents2 );
    ofpAgents3.resize( iAgents3 );
    ofcAgentColors3.resize( iAgents3 );

   // the agents size and step size
    
    fAgentSize = 2.0;
    fAgentStep = 2;
    
    fAgentSize2 = 2.0;
    fAgentStep2 = 2;
    
    fAgentSize3 = 3.0;
    fAgentStep3 = 3;


   // initiate the agents position randomly
	for( int i = 0; i < ofpAgents.size(); i++ ){
		ofpAgents[ i ].x = ofRandomWidth();
		ofpAgents[ i ].y = ofRandomHeight();
	}

   // and get some random color for every agent
   for( int i = 0; i < ofcAgentColors.size(); i++ ){
      ofcAgentColors[ i ].setHsb( ofRandom( 255.0 ), 255.0, 255.0, 50.0 );
   }
    
    // initiate the agents position randomly
    for( int i = 0; i < ofpAgents2.size(); i++ ){
        ofpAgents2[ i ].x = ofRandomWidth();
        ofpAgents2[ i ].y = ofRandomHeight();
    }
    
    // and get some random color for every agent
    for( int i = 0; i < ofcAgentColors2.size(); i++ ){
        ofcAgentColors2[ i ].setHsb( ofRandom( 255.0 ), 255.0, 255.0, 50.0 );
    }
    
    // initiate the agents position randomly
    for( int i = 0; i < ofpAgents3.size(); i++ ){
        ofpAgents3[ i ].x = ofRandomWidth();
        ofpAgents3[ i ].y = ofRandomHeight();
    }
    
    // and get some random color for every agent
    for( int i = 0; i < ofcAgentColors3.size(); i++ ){
        ofcAgentColors3[ i ].setHsb( ofRandom( 255.0 ), 255.0, 255.0, 50.0 );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
//    myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE,true);
    
	for( int i = 0; i < ofpAgents.size(); i++ ){
		iDirection = static_cast<int>( ofRandom( 0.0, 7.9 ) );
        

      // set the new position for the agent according to 
      // the random int we got above
		switch( iDirection ){
			case 0: // north
            ofpAgents[ i ].y -= fAgentStep;
            break;
			case 1: // north-east
            ofpAgents[ i ].x += fAgentStep;
            ofpAgents[ i ].y -= fAgentStep;
            break;
			case 2: // east
            ofpAgents[ i ].x += fAgentStep;
            break;
			case 3: // south-east
            ofpAgents[ i ].x += fAgentStep;
            ofpAgents[ i ].y += fAgentStep;
            break;
			case 4: // south
            ofpAgents[ i ].y += fAgentStep;
            break;
			case 5: // south-west
            ofpAgents[ i ].x -= fAgentStep;
            ofpAgents[ i ].y += fAgentStep;
            break;
			case 6: // west
            ofpAgents[ i ].x -= fAgentStep;
            break;
			case 7: // north-west
            ofpAgents[ i ].x -= fAgentStep;
            ofpAgents[ i ].y -= fAgentStep;
            break;
		}
        
      // in case the agent goes over canvas border set
      // it somewhere new randomly
      if( ofpAgents[ i ].x < 0 || ofpAgents[ i ].x > ofGetWidth() ){
         ofpAgents[ i ].x = ofRandomWidth();
      }
      if( ofpAgents[ i ].y < 0 || ofpAgents[ i ].y > ofGetHeight() ){
         ofpAgents[ i ].y = ofRandomHeight();
      }
	}
    
    for( int i = 0; i < ofpAgents2.size(); i++ ){
        iDirection2 = static_cast<int>( ofRandom( 0.0, 7.8 ) );
        
        
        // set the new position for the agent according to
        // the random int we got above
        switch( iDirection ){
            case 0: // north
                ofpAgents2[ i ].y -= fAgentStep2;
                break;
            case 1: // north-east
                ofpAgents2[ i ].x += fAgentStep2;
                ofpAgents2[ i ].y -= fAgentStep2;
                break;
            case 2: // east
                ofpAgents2[ i ].x += fAgentStep2;
                break;
            case 3: // south-east
                ofpAgents2[ i ].x += fAgentStep2;
                ofpAgents2[ i ].y += fAgentStep2;
                break;
            case 4: // south
                ofpAgents2[ i ].y += fAgentStep2;
                break;
            case 5: // south-west
                ofpAgents2[ i ].x -= fAgentStep2;
                ofpAgents2[ i ].y += fAgentStep2;
                break;
            case 6: // west
                ofpAgents2[ i ].x -= fAgentStep2;
                break;
            case 7: // north-west
                ofpAgents2[ i ].x -= fAgentStep2;
                ofpAgents2[ i ].y -= fAgentStep2;
                break;
        }
        
        // in case the agent goes over canvas border set
        // it somewhere new randomly
        if( ofpAgents2[ i ].x < 0 || ofpAgents2[ i ].x > ofGetWidth() ){
            ofpAgents2[ i ].x = ofRandomWidth();
        }
        if( ofpAgents2[ i ].y < 0 || ofpAgents2[ i ].y > ofGetHeight() ){
            ofpAgents2[ i ].y = ofRandomHeight();
        }
    }
    
    for( int i = 0; i < ofpAgents3.size(); i++ ){
        iDirection3 = static_cast<int>( ofRandom( 0.0, 7.7 ) );
        
        
        // set the new position for the agent according to
        // the random int we got above
        switch( iDirection ){
            case 0: // north
                ofpAgents3[ i ].y -= fAgentStep3;
                break;
            case 1: // north-east
                ofpAgents3[ i ].x -= fAgentStep3;
                ofpAgents3[ i ].y += fAgentStep3;
                break;
            case 2: // east
                ofpAgents3[ i ].x += fAgentStep3;
                break;
            case 3: // south-east
                ofpAgents3[ i ].x -= fAgentStep3;
                ofpAgents3[ i ].y -= fAgentStep3;
                break;
            case 4: // south
                ofpAgents3[ i ].y += fAgentStep3;
                break;
            case 5: // south-west
                ofpAgents3[ i ].x += fAgentStep3;
                ofpAgents3[ i ].y -= fAgentStep3;
                break;
            case 6: // west
                ofpAgents3[ i ].x += fAgentStep3;
                break;
            case 7: // north-west
                ofpAgents3[ i ].x -= fAgentStep3;
                ofpAgents3[ i ].y -= fAgentStep3;
                break;
        }
        
        // in case the agent goes over canvas border set
        // it somewhere new randomly
        if( ofpAgents3[ i ].x < 0 || ofpAgents3[ i ].x > ofGetWidth() ){
            ofpAgents3[ i ].x = ofRandomWidth();
        }
        if( ofpAgents3[ i ].y < 0 || ofpAgents3[ i ].y > ofGetHeight() ){
            ofpAgents3[ i ].y = ofRandomHeight();
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
   
    
    // loop through the two vectors and draw them a new
	for( int i = 0; i < ofpAgents.size(); i++ ){
      ofSetColor( 255, 0, 255 );
//        ofDrawRectangle(ofpAgents[ i ].x, ofpAgents[ i ].y, 8 , 8);
		ofCircle( ofpAgents[ i ].x, ofpAgents[ i ].y, 2 );
	}
    
    // loop through the two vectors and draw them a new
    for( int i = 0; i < ofpAgents2.size(); i++ ){
        ofSetColor( 200, 0, 200 );
        ofDrawRectangle(ofpAgents[ i ].x, ofpAgents2[ i ].y, 6 , 6);
        //	ofCircle( ofpAgents2[ i ].x, ofpAgents2[ i ].y, 2 );
    }
    
    // loop through the two vectors and draw them a new
    for( int i = 0; i < ofpAgents3.size(); i++ ){
        ofSetColor( 170, 0, 170 );
        ofDrawRectangle(ofpAgents3[ i ].x, ofpAgents[ i ].y, 3 , 3);
        //	ofCircle( ofpAgents3[ i ].x, ofpAgents3[ i ].y, 2 );
    }
    
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
    
//    myGlitch.generateFx();
//    myFbo.draw(0,0);
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
   // reset the canvas
   switch( key ){
      case 114:
         ofBackground( 0 );
         break;
   }
}
