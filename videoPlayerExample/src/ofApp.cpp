#include "ofApp.h"

void ofApp::onEndOfStream(ofEventArgs& args)
{
	ofLogVerbose() << "onEOS";
	doProcessPixels = !doProcessPixels;
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	
	//We want to receive an event when gstreamer reaches the end of stream
	//so we need to get access to some internals to attach as a listener
	
	//Create a pointer to a new ofGstVideoPlayer
	gstVideoPlayer = new ofGstVideoPlayer();
	
	//Create a smart pointer that ofVideoPlayer requires 
	ofPtr<ofBaseVideoPlayer> baseVideoPlayer = ofPtr<ofBaseVideoPlayer>(gstVideoPlayer);
	
	//ofGstVideoUtils is what dispatches the events - get a reference
	gstVideoUtils = gstVideoPlayer->getGstVideoUtils();
	
	//We add our listener
	ofAddListener(gstVideoUtils->eosEvent, this, &ofApp::onEndOfStream);
	
	//If you were creating multiple players you would want to do this at cleanup
	//We are only using one player so we are okay
	//ofRemoveListener(gstVideoUtils->eosEvent, &ofApp::onEndOfStream);
	
	videoPlayer.setPlayer(baseVideoPlayer);
	
	
	// Uncomment this to show movies with alpha channels
	// videoPlayer.setPixelFormat(OF_PIXELS_RGBA);
	
	
	videoPlayer.loadMovie("walkingFingers.mov");
	videoPlayer.setLoopState(OF_LOOP_NORMAL); //must set this after loadMovie on the RPI
	videoWidth = videoPlayer.getWidth();
	videoHeight = videoPlayer.getHeight();
	videoPlayer.play();
	
	doProcessPixels = false;
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
    videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::darkGray);
	ofPushMatrix();
		ofTranslate((ofGetWidth()/2) - videoWidth, (ofGetHeight()-videoHeight)/2); //move to the center
		videoPlayer.draw(0, 0);
		if (doProcessPixels) 
		{
			ofTranslate(videoWidth, 0);
			ofPushStyle();
			ofSetColor(ofColor::black);
			
			int numChannels = videoPlayer.getPixelsRef().getNumChannels();
			unsigned char * pixels = videoPlayer.getPixels();
			// let's move through the "RGB(A)" char array
			// using the red pixel to control the size of a circle.
			int xStep =	4;
			int yStep = 8;
			//going across the width
			for (int x = xStep; x < videoWidth; x+=yStep)
			{
				//going across the height
				for (int y = xStep; y < videoHeight; y+=yStep)
				{
					//we are now at our target pixel
					int position = (y * videoWidth + x)*numChannels;
					//grab the pixel from the pixel array
					unsigned char pixel = pixels[position];
					//measure the red value
					float redValue = 1.0 - ((float)pixel/255.0f);
					//multiply it to use as the circle radius
					float radius = 10*redValue;
					//draw the circle
					ofCircle(x, y, radius);
				}
			}
			ofPopStyle();
		}
		
	ofPopMatrix();
	
	ofPushStyle();
		ofSetColor(ofColor::white);
		stringstream info;
		info << "App FPS: "		<< ofGetFrameRate()															<< "\n";
		info << "Frame: "		<< videoPlayer.getCurrentFrame() << "/" << videoPlayer.getTotalNumFrames()	<< "\n";
		info << "Duration: "	<< videoPlayer.getDuration()												<< "\n";
		info << "Speed: "		<< videoPlayer.getSpeed()													<< "\n";
		ofDrawBitmapString(info.str(), 100, 100);
	ofPopStyle();
	}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
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
