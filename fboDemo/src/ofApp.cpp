#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

	videoDrawX = 0;
	videoDrawY = 0;
	
	fbo.allocate(ofGetWidth(), ofGetHeight());
	
	videoPlayer.loadMovie("fingers.mp4");
	videoPlayer.setLoopState(OF_LOOP_NORMAL); //On the RPI you currently need to call this after loadMovie
	videoDrawWidth = videoPlayer.getWidth()/4;
	videoDrawHeight = videoPlayer.getHeight()/4;
	videoPlayer.play();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	if (videoPlayer.isFrameNew()) 
	{
		fbo.begin();
		if (videoPlayer.getCurrentFrame() == 0) 
		{
			ofClear(0, 0, 0, 0);
		}
		ofPushStyle();
			ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
			videoPlayer.draw(videoDrawX, videoDrawY, videoDrawWidth, videoDrawHeight);
			ofDrawBitmapString(ofToString(videoPlayer.getCurrentFrame()), videoDrawX, videoDrawY+20);
		ofPopStyle();
		
		if(videoDrawX+videoDrawWidth < ofGetWidth())
		{
			videoDrawX+=videoDrawWidth;
			
		}else
		{
			videoDrawX = 0;
			if (videoDrawY+videoDrawHeight < ofGetHeight()) 
			{
				videoDrawY+=videoDrawHeight;
			}else 
			{
				videoDrawY = 0;
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