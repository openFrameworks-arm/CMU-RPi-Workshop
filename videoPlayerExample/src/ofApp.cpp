#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	frameByframe = false;

	// Uncomment this to show movies with alpha channels
	// videoPlayer.setPixelFormat(OF_PIXELS_RGBA);

	videoPlayer.loadMovie("walkingFingers.mov");
	videoPlayer.setLoopState(OF_LOOP_NORMAL); //must set this after loadMovie on the RPI
	videoWidth = videoPlayer.getWidth();
	videoHeight = videoPlayer.getHeight();
	videoPlayer.play();
	doProcessPixels = false;
	//ofPtr<ofBaseVideoPlayer> player  = videoPlayer.getPlayer();
	//ofGstVideoUtils* utils = (ofGstVideoPlayer*) player->getGstVideoUtils();
	ofPtr<ofBaseVideoPlayer> player = ofPtr<ofBaseVideoPlayer>(player->getGstVideoUtils());
}

//--------------------------------------------------------------
void ofApp::update(){
    videoPlayer.update();
	if(videoPlayer.getCurrentFrame() == videoPlayer.getTotalNumFrames())
	{
		doProcessPixels = !doProcessPixels;
	}
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
		info << "Frame #: "		<< videoPlayer.getCurrentFrame() << "/" << videoPlayer.getTotalNumFrames()	<< "\n";
		info << "Duration: "	<< videoPlayer.getDuration()												<< "\n";
		info << "Speed: "		<< videoPlayer.getSpeed()													<< "\n";
		ofDrawBitmapString(info.str(), 100, 100);
	ofPopStyle();
	
   /* ofSetHexColor(0x000000);
	ofDrawBitmapString("press f to change",20,videoWidth);
    if(frameByframe) ofSetHexColor(0xCCCCCC);
    ofDrawBitmapString("mouse speed position",20,340);
    if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
    ofSetHexColor(0x000000);

    ofDrawBitmapString("frame: " + ofToString(videoPlayer.getCurrentFrame()) + "/"+ofToString(videoPlayer.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(videoPlayer.getPosition()*videoPlayer.getDuration(),2) + "/"+ofToString(videoPlayer.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(videoPlayer.getSpeed(),2),20,420);

    if(videoPlayer.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }*/
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch(key){
        case 'f':
            frameByframe=!frameByframe;
            videoPlayer.setPaused(frameByframe);
        break;
        case OF_KEY_LEFT:
            videoPlayer.previousFrame();
        break;
        case OF_KEY_RIGHT:
            videoPlayer.nextFrame();
        break;
        case '0':
            videoPlayer.firstFrame();
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        float speed = (2 * pct - 1) * 5.0f;
        videoPlayer.setSpeed(speed);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        videoPlayer.setPosition(pct);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(!frameByframe){
        videoPlayer.setPaused(true);
	}
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(!frameByframe){
        videoPlayer.setPaused(false);
	}
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
