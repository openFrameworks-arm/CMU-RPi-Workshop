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
	
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(10, 10, 10);
	
	videoGrabber.update();
	
	if (ofGetFrameNum() % 500 == 0) 
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
		
	ofPushMatrix();
	ofTranslate(cameraWidth/2, (ofGetHeight()-cameraHeight)/2, 0);
	videoGrabber.draw(0, 0);
	ofDrawBitmapString("SOURCE", 0, -20);
	ofTranslate(cameraWidth, 0);
	if(doInvertPixels)
	{
		ofDrawBitmapString("PIXELS, FPS: " + ofToString(ofGetFrameRate(), 0), 0, -20);
		invertedTexture.draw(0, 0);
	}
	else
	{
		ofTranslate(cameraWidth, 0);
		ofDrawBitmapString("SHADER, FPS: " + ofToString(ofGetFrameRate(), 0), 0, -20);
		shader.begin();
			videoGrabber.draw(0, 0);
		shader.end();
	}
	ofPopMatrix();
	
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