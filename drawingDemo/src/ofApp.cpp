#include "ofApp.h"





//--------------------------------------------------------------
void ofApp::setup(){

	consoleListener.setup(this);
	
	ofLoadImage(texture, "of.png");

	// resize the plane to the size of the texture //
	//plane.resizeToTexture( texture );
	//createNamedPrimitive(plane, "plane", 0.5, texture);
	
	createNamedPrimitive(box, "box", 1.5);
	createNamedPrimitive(sphere, "sphere", 4.0);
	createNamedPrimitive(icoSphere, "icoSphere", 4.0);
	createNamedPrimitive(cylinder, "cylinder", 1.5);
	createNamedPrimitive(cone, "cone", 4.0);

	counter = 0;
	wireframeMode = false;
	
	enableTexture = true;

	doBreakApart = false;
	doResetPrimitives = false;
}

void ofApp::createNamedPrimitive(of3dPrimitive& primitive, string name, float scaleFactor)
{
	NamedPrimitive namedPrimitive;
	namedPrimitive.primitive = primitive;
	namedPrimitive.name = name;
	namedPrimitive.scaleFactor = scaleFactor;
	
	//setTexCoordsFromTexture sets normalized or non-normalized tex coords based on an ofTexture passed in.
	
	primitive.mapTexCoordsFromTexture( texture );
	namedPrimitive.triangles = primitive.getMesh().getUniqueFaces();
	namedPrimitives.push_back(namedPrimitive);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum()%100 == 0) 
	{
		if (counter+1 < namedPrimitives.size()) 
		{
			counter++;
		}else 
		{
			counter = 0;
		}
	}
	
	if (doResetPrimitives)
	{
		
		for (size_t i=0; i<namedPrimitives.size(); i++) 
		{
			namedPrimitives[i].primitive.getMesh().setMode( OF_PRIMITIVE_TRIANGLES );
			vector<ofMeshFace> triangles = namedPrimitives[i].triangles;
			namedPrimitives[i].primitive.getMesh().setFromTriangles(triangles, true);
			namedPrimitives[i].primitive.mapTexCoordsFromTexture( texture );
			namedPrimitives[i].triangles = namedPrimitives[i].primitive.getMesh().getUniqueFaces();
		}
		doResetPrimitives = false;
	}
}

void ofApp::draw()
{
	ofEnableDepthTest();
	for (size_t i=0; i<namedPrimitives.size(); i++) 
	{
		ofPushMatrix();
			ofTranslate(400, 200);
			ofTranslate(250*i, 0);
			ofRotateY(ofGetFrameNum()%360);
			float scale = namedPrimitives[i].scaleFactor;
			ofScale(scale, scale, scale);
			ofPushStyle();
			if(enableTexture) texture.bind();
				if (wireframeMode) 
				{
					namedPrimitives[i].primitive.drawWireframe();
				}else 
				{
					namedPrimitives[i].primitive.draw();
				}
				if (doBreakApart) 
				{
					breakApart(namedPrimitives[i].primitive);
				}
			if(enableTexture) texture.unbind();
			ofPopStyle();
		ofPopMatrix();
	}
}

void ofApp::breakApart(of3dPrimitive& primitive)
{
	primitive.getMesh().setMode( OF_PRIMITIVE_TRIANGLES );
	vector<ofMeshFace> triangles = primitive.getMesh().getUniqueFaces();
	float angle = (ofGetElapsedTimef() * 1.4);
	ofVec3f faceNormal;
	for(std::size_t i = 0; i < triangles.size(); i++ ) 
	{
		float frc = ofSignedNoise(angle* (float)i * .1, angle*.05) * 4;
		faceNormal = triangles[i].getFaceNormal();
		for(std::size_t j = 0; j < 3; j++ ) 
		{
			triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal * frc );
		}
	}
	primitive.getMesh().setFromTriangles( triangles );
	
}

#if 0
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
				namedPrimitives[counter].draw();
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
#endif
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
			doResetPrimitives = true;
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
