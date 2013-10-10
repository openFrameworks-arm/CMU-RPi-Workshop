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
	primitive.getMesh().setMode( OF_PRIMITIVE_TRIANGLES );
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
			namedPrimitives[i].primitive.getMesh().setFromTriangles(namedPrimitives[i].triangles, true);
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
