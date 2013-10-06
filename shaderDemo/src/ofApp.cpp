#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sourceImage.loadImage("Raspi_598x720.png");
	
	shader.load("simpleShader");
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::black, ofColor::red, OF_GRADIENT_CIRCULAR);
	shader.begin();
		shader.setUniformTexture("tex0", sourceImage.getTextureReference(), sourceImage.getTextureReference().texData.textureID);
		shader.setUniform1f("time", ofGetElapsedTimef());
		shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
		
		sourceImage.draw((ofGetWidth()-sourceImage.getWidth())/2,	//x
						 (ofGetHeight()-sourceImage.getHeight())/2, //y
						 sourceImage.getWidth(),					//width
						 sourceImage.getHeight());					//height
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