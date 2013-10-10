#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(false);
	//Load in an image from bin/data
	sourceImage.loadImage("Raspi_Colour_R.png");
	
	//ofFbos must be allocated, you get RGBA by default
	fbo.allocate(ofGetWidth(), ofGetHeight());
	counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// Fbo operations must currently be done inside draw() on the Rpi

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);

	//Let's work in our Fbo
	fbo.begin();
	
		//clear once we have drawn 1000 pis
		if (counter>=1000) 
		{
			ofClear(0, 0, 0, 0);
			counter = 0;
		}
	
		//use ofPushMatrix/ofPopMatrix to isolate transforms
		ofPushMatrix();
	
			//move our focus to a random position
			ofTranslate(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	
			//We want to scale from the center as opposed to the default upper left
			ofSetRectMode(OF_RECTMODE_CENTER);
	
				//our image is kinda large - scaling it to at most 1/5 the size
				float randomScale = ofRandom(0.01, 0.05);
				ofScale(randomScale, randomScale);
				
				//With OF_RECTMODE_CENTER our image will rotate 
				//using the center point as the anchor
				ofRotate(ofRandom(360));
				//since our focus has been modified with ofTranslate we can use a clean x,y of 0,0
				sourceImage.draw(0, 0);
	
			//Set the OF_RECTMODE back to default
			ofSetRectMode(OF_RECTMODE_CORNER);
	
		//Leave our transform sandbox
		ofPopMatrix();
	
	//Stop our Fbo work
	fbo.end();
	
	//Even though we are in draw(), nothing will happen unless we explicitly draw the Fbo
	fbo.draw(0, 0);
	
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