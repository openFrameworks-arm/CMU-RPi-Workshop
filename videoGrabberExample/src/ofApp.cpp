#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(false);
	cameraWidth		= 320;
	cameraHeight	= 240;
	
	videoGrabber.listDevices();
	videoGrabber.setDesiredFrameRate(60); 
	videoGrabber.initGrabber(cameraWidth, cameraHeight);
	
	numInvertedPixels = cameraWidth*cameraHeight*3;
	invertedPixels = new unsigned char[numInvertedPixels];
	invertedTexture.allocate(cameraWidth, cameraHeight, GL_RGB);
	
	doInvertPixels = false;
	shader.load("inverse");
	ofSetBackgroundColor(10, 10, 10, 255);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	videoGrabber.update();
	
	if (ofGetFrameNum() % 1000 == 0) 
	{
		doInvertPixels = !doInvertPixels;
	}
	if (videoGrabber.isFrameNew() && doInvertPixels)
	{
		unsigned char* pixels = videoGrabber.getPixels();
		for (int i = 0; i < numInvertedPixels; i++)
		{
			invertedPixels[i] = 255 - pixels[i];
		}
		invertedTexture.loadData(invertedPixels, cameraWidth, cameraHeight, GL_RGB);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	videoGrabber.draw(20, 0);
	if(doInvertPixels)
	{
		invertedTexture.draw(cameraWidth+20, 0);
	}
	else
	{
		shader.begin();
			videoGrabber.draw(cameraWidth+20, 240);
		shader.end();
	}
	ofDrawBitmapString(ofToString(ofGetFrameRate(), 0), 100, cameraHeight+20);
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