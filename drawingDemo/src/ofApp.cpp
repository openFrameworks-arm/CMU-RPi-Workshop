#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofLoadImage(texture, "of.png");
	//
	// resize the plane to the size of the texture //
	plane.resizeToTexture( texture );
	// setTexCoordsFromTexture sets normalized or non-normalized tex coords based on an ofTexture passed in.
	box.mapTexCoordsFromTexture( texture );
	sphere.mapTexCoordsFromTexture( texture );
	icoSphere.mapTexCoordsFromTexture( texture );
	cylinder.mapTexCoordsFromTexture( texture );
	cone.mapTexCoordsFromTexture( texture );
	
	primitives.push_back(plane);
	primitives.push_back(box);
	primitives.push_back(sphere);
	primitives.push_back(icoSphere);
	primitives.push_back(cylinder);
	primitives.push_back(cone);
	counter = 0;
	wireframeMode = false;
	consoleListener.setup(this);
	enableTexture = true;

	triangles = icoSphere.getMesh().getUniqueFaces();
	doBreakApart = false;
	doResetIco = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum()%100 == 0) 
	{
		if (counter+1 < primitives.size()) 
		{
			counter++;
		}else 
		{
			counter = 0;
		}
		
	}
	if (doResetIco)
	{
		icoSphere.setMode( OF_PRIMITIVE_TRIANGLES );
		triangles = icoSphere.getMesh().getUniqueFaces();
		icoSphere.getMesh().setFromTriangles(triangles, true);
		icoSphere.mapTexCoordsFromTexture( texture );
		doResetIco = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//ofEnableAlphaBlending();
	/*ofPushMatrix();
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
		ofRotateY(ofGetFrameNum()%360);
		float randomScale = ofRandom(1.0f, 4.0f);
		ofScale(randomScale, randomScale, randomScale);
		ofPushStyle();
			if(enableTexture) texture.bind();
				primitives[counter].draw();
			if(enableTexture) texture.unbind();
		ofPopStyle();
	ofPopMatrix();*/
	
	ofEnableDepthTest();
    
    //ofEnableLighting();
	
	ofPushMatrix();
		ofTranslate(200, 200);
		ofRotateY(ofGetFrameNum()%360);
		ofScale(4.0, 4.0, 4.0);
		ofPushStyle();
			if(enableTexture) texture.bind();
				if (wireframeMode) 
				{
					sphere.drawWireframe();
				}else 
				{
					sphere.draw();
				}
			if(enableTexture) texture.unbind();
		ofPopStyle();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(400, 200);
	ofRotateY(ofGetFrameNum()%360);
	ofScale(4.0, 4.0, 4.0);
	ofPushStyle();
	if(enableTexture) texture.bind();
	if (wireframeMode) 
	{
		icoSphere.drawWireframe();
	}else 
	{
		icoSphere.draw();
	}
	if (doBreakApart) 
	{
		float angle = (ofGetElapsedTimef() * 1.4);
		ofVec3f faceNormal;
		for(std::size_t i = 0; i < triangles.size(); i++ ) {
			float frc = ofSignedNoise(angle* (float)i * .1, angle*.05) * 4;
			faceNormal = triangles[i].getFaceNormal();
			for(std::size_t j = 0; j < 3; j++ ) {
				triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal * frc );
			}
		}
		icoSphere.getMesh().setFromTriangles( triangles );
	}
	
	if(enableTexture) texture.unbind();
	ofPopStyle();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(600, 200);
	ofRotateY(ofGetFrameNum()%360);
	ofScale(1.5, 1.5, 1.5);
	ofPushStyle();
	if(enableTexture) texture.bind();
	if (wireframeMode) 
	{
		cylinder.drawWireframe();
	}else 
	{
		cylinder.draw();
	}
	if(enableTexture) texture.unbind();
	ofPopStyle();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(800, 200);
	ofRotateY(ofGetFrameNum()%360);
	ofScale(4.0, 4.0, 4.0);
	ofPushStyle();
	if(enableTexture) texture.bind();
	if (wireframeMode) 
	{
		cone.drawWireframe();
	}else 
	{
		cone.draw();
	}
	if(enableTexture) texture.unbind();
	ofPopStyle();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(200, 400);
	ofRotateY(ofGetFrameNum()%360);
	ofScale(1.5, 1.5, 1.5);
	ofPushStyle();
	if(enableTexture) texture.bind();
	if (wireframeMode) 
	{
		box.drawWireframe();
	}else 
	{
		box.draw();
	}
	if(enableTexture) texture.unbind();
	ofPopStyle();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(400, 400);
	ofRotateY(ofGetFrameNum()%360);
	ofScale(0.5, 0.5, 0.5);
	ofPushStyle();
	if(enableTexture) texture.bind();
	if (wireframeMode) 
	{
		plane.drawWireframe();
	}else 
	{
		plane.draw();
	}
	if(enableTexture) texture.unbind();
	ofPopStyle();
	ofPopMatrix();
	
	/*sphere.draw();
	box.draw();
	icoSphere.draw();
	cylinder.draw();
	cone.draw();*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 'w') 
	{
		wireframeMode = !wireframeMode;
		
	}
	if (key == 't') 
	{
		enableTexture = !enableTexture;
	}
	if (key == 'b') 
	{
		if (doBreakApart) 
		{
			doResetIco = true;
			
			
		}
		doBreakApart = !doBreakApart;
		
		
	}
	
}

void ofApp::onCharacterReceived(SSHKeyListenerEventData& e)
{
	keyPressed((int)e.character);
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
