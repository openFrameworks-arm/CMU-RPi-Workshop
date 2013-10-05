#include "ofApp.h"

int videoWidth = 0;
int videoHeight = 0;
int x = 0;
int y = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	//sourceImage.loadImage("Raspi_Colour_R.png");
	fbo.allocate(ofGetWidth(), ofGetHeight());
	
	videoPlayer.loadMovie("fingers.mp4");
	
	videoWidth = videoPlayer.getWidth()/4;
	videoHeight = videoPlayer.getHeight()/4;
	videoPlayer.play();
	videoPlayer.setLoopState(OF_LOOP_NORMAL);
}

//--------------------------------------------------------------
void ofApp::update(){
	videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (videoPlayer.isFrameNew()) 
	{
		fbo.begin();
		if (videoPlayer.getCurrentFrame() == 0) 
		{
			ofClear(0, 0, 0, 0);
		}
		ofPushStyle();
			ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
			videoPlayer.draw(x, y, videoWidth, videoHeight);
			ofDrawBitmapString(ofToString(videoPlayer.getCurrentFrame()), x, y+20);
		ofPopStyle();
		if(x+videoWidth< ofGetWidth())
		{
			x+=videoWidth;
			
		}else
		{
			x = 0;
			if (y+videoHeight<ofGetHeight()) 
			{
				y+=videoHeight;
			}else 
			{
				y = 0;
			}
		}
		
		fbo.end();
	}
	fbo.draw(0, 0);
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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