#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//We load our source Image
	sourceImage.loadImage("Raspi_598x720.png");
	
	//And now our shader located in bin/data
	
	//If you use the same name with .vert and .frag you can do this
	shader.load("shaderExample");
	
	//Or if you want be explicit to mix file you can do this
	//shader.load("shaderExample.vert", "shaderExample.frag");
	
	//Our image has transparency so we need to do this
	//otherwise it will fill in the alpha with white
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//Fancy background gradient
	ofBackgroundGradient(ofColor::red, ofColor::black, OF_GRADIENT_CIRCULAR);
	
	//Let start our shader work
	shader.begin();
		//We tell our shader what texture to use
		shader.setUniformTexture("tex0", sourceImage.getTextureReference(), sourceImage.getTextureReference().texData.textureID);
	
		//We give it a changing value to work with
		shader.setUniform1f("time", ofGetElapsedTimef());
		
		//We give it a resolution variable to work with (our entire screen size)
		shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
		
		//We draw our image which essentially kicks off the process
		sourceImage.draw((ofGetWidth()-sourceImage.getWidth())/2,	//x
						 (ofGetHeight()-sourceImage.getHeight())/2, //y
						 sourceImage.getWidth(),					//width
						 sourceImage.getHeight());					//height
	
	//We end our shader so we now draw things again that are uneffected
	shader.end();
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