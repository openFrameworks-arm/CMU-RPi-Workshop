#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//Load in an image from bin/data
	sourceImage.loadImage("Raspi_Colour_R.png");
	
	//ofFbos must be allocated, you get RGBA by default
	fbo.allocate(ofGetWidth(), ofGetHeight());
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// Fbo operations must currently be done inside draw() on the Rpi

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//Let's work in our Fbo
	fbo.begin();
	
		//clear every 100 frames
		if (ofGetFrameNum()%100 == 0) 
		{
			ofClear(0, 0, 0, 0);
		}
	
		//use ofPushMatrix/ofPopMatrix to isolate transforms
		ofPushMatrix();
	
			//move our focus to a random position
			ofTranslate(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	
			//We want to scale from the center as opposed to the default uppper left
			ofSetRectMode(OF_RECTMODE_CENTER);
	
				//our image is kinda large - scaling it to at most half the size
				float randomScale = ofRandom(0.1, 0.5);
				ofScale(randomScale, randomScale);
	
				//since our focus has been modified with ofTranslate we can use a clean x,y of 0,0
				sourceImage.draw(0, 0);
	
			//Set the OF_RECTMODE back to default
			ofSetRectMode(OF_RECTMODE_CORNER);
	
		//Leave our transform sandbox
		ofPopMatrix();
		
		//Spin one in the center
		ofPushMatrix();
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
			int randomRotation = ofRandom(360);
			ofSetRectMode(OF_RECTMODE_CENTER);
				ofScale(.5, .5);
				ofRotate(randomRotation);
				sourceImage.draw(0, 0);
			ofSetRectMode(OF_RECTMODE_CORNER);
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