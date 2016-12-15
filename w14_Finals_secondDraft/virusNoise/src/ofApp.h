#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp
{
	public:
	
		//--------------------------------------------------------------
		void setup()
		{
            
            bgs.load("drums.mp3");
            bgs.setVolume(0.5);
            bgs.play();
            bgs.setLoop(true);
            bgs.setSpeed(.5);
            
            
            image.load("pixelPicture.png");
            
            ofSetColor(100, 0, 100);
			
			resolution.addListener(this, &ofApp::resolutionChanged );
			
			gui.setup( "Main", "Main.xml" );
			
			gui.add( resolution.set( "Resolution", 800, 6, 1024 ) );
			gui.add( noiseFrequency.set( "Noise Frequency", 80.0f, 0.00001f, 4096.0f ) );
			gui.add( animate.set( "Animate", true ) );
			
			gui.add( doThreshold.set( "Threshold", true ) );
			gui.add( thresholdLow.set( "Treshold Low", 52, 0, 54 ) );
			gui.add( thresholdHigh.set( "Treshold High", 61, 0, 63 ) );
			gui.add( invert.set( "Invert Threshold", false ) );
			
			noiseStartX = 0;
			noiseStartY = 0;
			
//			drawGui = true;
			
			noiseImage.allocate( resolution, resolution, OF_IMAGE_GRAYSCALE );
		}
		
		//--------------------------------------------------------------
		void update()
		{
			if( ofGetKeyPressed(OF_KEY_LEFT)  )  { noiseStartX += 5; }
			if( ofGetKeyPressed(OF_KEY_RIGHT ) ) { noiseStartX -= 5; }
			if( ofGetKeyPressed(OF_KEY_UP)  )    { noiseStartY += 5; }
			if( ofGetKeyPressed(OF_KEY_DOWN ) )  { noiseStartY -= 5; }
			
			float time = 0.0f;
			if( animate ) time = ofGetElapsedTimef();
			
			ofPixelsRef pixels = noiseImage.getPixelsRef();
			
			int tmpIndex = 0;
			for( int y = 0; y < noiseImage.getHeight(); y++ )
			{
				for( int x = 0; x < noiseImage.getWidth(); x++ )
				{
					// We're grabbing a single reading from the noise function here, but we can also add together more
					// readings at different frequencies to make more complex patterns
					
					float tmpNoise = ofNoise( (noiseStartX + x) / noiseFrequency, (noiseStartY + y) / noiseFrequency, time );
					
					pixels[tmpIndex] = tmpNoise * 255.0f;
					tmpIndex++;
				}
			}
			
			if( doThreshold)
			{
				threshold( false );
			}
			
			noiseImage.update(); // uploads the new pixels to the gfx card
		}
		
		//--------------------------------------------------------------
		void threshold( bool _upload )
		{
			ofPixelsRef pixels = noiseImage.getPixelsRef();
			
			int tmpIndex = 0;
			for( int y = 0; y < noiseImage.getHeight(); y++ )
			{
				for( int x = 0; x < noiseImage.getWidth(); x++ )
				{
					if( pixels[tmpIndex] >= thresholdLow && pixels[tmpIndex] <= thresholdHigh )
					{
						pixels[tmpIndex] = 255;
					}
					else
					{
						pixels[tmpIndex] = 0;
					}
					
					if( invert )
					{
						pixels[tmpIndex] = 255 - pixels[tmpIndex];
					}
					
					tmpIndex++;
				}
			}
			
			
			if( _upload )
			{
				noiseImage.update();
			}
		}
		
		
		//--------------------------------------------------------------
		void draw()
		{
			ofBackgroundGradient( ofColor(0), ofColor(0), OF_GRADIENT_CIRCULAR );
            
//            ofDrawCircle(noiseImage.getWidth(), noiseImage.getHeight(), 10);
//            imageRect.scaleTo( ofDrawCircle(ofGetWidth(), ofGetHeight(), 10) );
//            noiseImage.draw( imageRect);
			
			ofRectangle imageRect(0,0,noiseImage.getWidth(), noiseImage.getHeight() );
			imageRect.scaleTo( ofRectangle(0,0,ofGetWidth(),ofGetHeight()) );
			noiseImage.draw( imageRect );
			
			if( drawGui )
			{
				gui.draw();
			}
            
            image.draw(0, 0, ofGetWidth(), ofGetHeight());
			
		}
		
		//--------------------------------------------------------------
		void resolutionChanged( int& _res )
		{
			noiseImage.allocate( _res, _res, OF_IMAGE_GRAYSCALE );
		}


		//--------------------------------------------------------------
		void keyPressed( int _key )
		{
			if( _key == 'f' )
			{
				ofToggleFullscreen();
			}
		}
	
		ofParameter<int> resolution;
		ofParameter<float> noiseFrequency;
		ofParameter<bool> animate;
	
		ofParameter<bool> doThreshold;
		ofParameter<int> thresholdLow;
		ofParameter<int> thresholdHigh;
		ofParameter<bool> invert;
	
		int noiseStartX;
		int noiseStartY;
	
		ofImage noiseImage;
	
		ofxPanel gui;
		bool drawGui;
    
    ofImage image;
    
    ofSoundPlayer bgs;
};
