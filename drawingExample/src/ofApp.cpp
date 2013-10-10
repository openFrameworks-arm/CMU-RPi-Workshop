#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	ofEnableSmoothing();
	ofEnableAntiAliasing();
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

ofColor getRandomColor()
{
	/*
	 white, gray, black, red, green, blue, cyan, magenta,
	 yellow,aliceBlue,antiqueWhite,aqua,aquamarine,azure,beige,bisque,blanchedAlmond,
	 blueViolet,brown,burlyWood,cadetBlue,chartreuse,chocolate,coral,cornflowerBlue,cornsilk,
	 crimson,darkBlue,darkCyan,darkGoldenRod,darkGray,darkGrey,darkGreen,darkKhaki,
	 darkMagenta,darkOliveGreen,darkorange,darkOrchid,darkRed,darkSalmon,darkSeaGreen,
	 darkSlateBlue,darkSlateGray,darkSlateGrey,darkTurquoise,darkViolet,deepPink,
	 deepSkyBlue,dimGray,dimGrey,dodgerBlue,fireBrick,floralWhite,forestGreen,fuchsia,
	 gainsboro,ghostWhite,gold,goldenRod,grey,greenYellow,honeyDew,hotPink,indianRed,indigo,
	 ivory,khaki,lavender,lavenderBlush,lawnGreen,lemonChiffon,lightBlue,lightCoral,
	 lightCyan,lightGoldenRodYellow,lightGray,lightGrey,lightGreen,lightPink,lightSalmon,
	 lightSeaGreen,lightSkyBlue,lightSlateGray,lightSlateGrey,lightSteelBlue,lightYellow,
	 lime,limeGreen,linen,maroon,mediumAquaMarine,mediumBlue,mediumOrchid,mediumPurple,
	 mediumSeaGreen,mediumSlateBlue,mediumSpringGreen,mediumTurquoise,mediumVioletRed,
	 midnightBlue,mintCream,mistyRose,moccasin,navajoWhite,navy,oldLace,olive,oliveDrab,
	 orange,orangeRed,orchid,paleGoldenRod,paleGreen,paleTurquoise,paleVioletRed,papayaWhip,
	 peachPuff,peru,pink,plum,powderBlue,purple,rosyBrown,royalBlue,saddleBrown,salmon,
	 sandyBrown,seaGreen,seaShell,sienna,silver,skyBlue,slateBlue,slateGray,slateGrey,snow,
	 springGreen,steelBlue,blueSteel,tan,teal,thistle,tomato,turquoise,violet,wheat,whiteSmoke,
	 yellowGreen;
	 */
	return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void drawCurve()
{
	ofPoint pt1(0, 0);
	ofPoint pt2(0, 100);
	ofPoint pt3(100, 100);
	ofPoint pt4(100, 0);
	

	ofPushStyle();
		ofNoFill();
		ofSetColor(ofColor::orange);
		ofCurve(pt1.x, pt1.y,
				pt2.x, pt2.y,
				pt3.x, pt3.y,
				pt4.x, pt4.y
				);
		
		//ofSetColor(getRandomColor());
		ofSetColor(ofColor::yellow);
		ofCircle(pt1, 5);
		ofCircle(pt2, 5);
		ofCircle(pt3, 5);
		ofCircle(pt4, 5);
	ofPopStyle();
}

void drawShapeFromPoints()
{
	ofPoint pt1(0, 0);
	ofPoint pt2(0, 100);
	ofPoint pt3(100, 100);
	ofPoint pt4(100, 0);
	
	
	ofPushStyle();
		ofNoFill();
		ofSetLineWidth(5);
		ofSetColor(ofColor::yellow);
		ofBeginShape();
			ofVertex(pt1);
			ofVertex(pt2);
			ofVertex(pt3);
			ofVertex(pt4);
			bool doCloseShape = (ofGetFrameNum()%100==0);
		ofEndShape(doCloseShape);//bool is option to close shape
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(10, 10, 10);
	int labelY = -20; //
	
	//Curves
	ofPushMatrix();
		ofTranslate(100, 50);
			ofDrawBitmapString("ofCurve", 0, labelY);
			drawCurve();
	ofPopMatrix();
	
	//Shapes from Points
	ofPushMatrix();
		ofTranslate(300, 50);
			ofDrawBitmapString("ofBeginShape\nofEndShape", 0, labelY);
			drawShapeFromPoints();
	ofPopMatrix();
	
	//ofRect
	ofPushMatrix();
		ofTranslate(500, 50);
			ofDrawBitmapString("ofRect", 0, labelY);
			ofRectangle rectangle(0, 0, 100, 100);
			ofRect(rectangle);
	ofPopMatrix();
	
	//ofRectRounded
	ofPushMatrix();
	ofTranslate(700, 50);
		//% (modulus) is a cool way of keeping a number within range
		float cornerRadius = (float) (ofGetFrameNum()%40);
		ofDrawBitmapString("ofRectRounded", 0, labelY);
		ofRectRounded(rectangle, cornerRadius);
	ofPopMatrix();
	
	//ofCircle
	ofPushMatrix();
		ofTranslate(900, 50);
		
		stringstream circleInfo;
		int circleResolution = ofGetFrameNum()%48;
		ofSetCircleResolution(circleResolution);
		circleInfo << "ofCircle" << "\n" << "Circle Resolution: " << circleResolution;
		ofDrawBitmapString(circleInfo.str(), 0, labelY);
	
		ofCircle(50, 50, 50);
	ofPopMatrix();
	
	//ofEllipse
	ofPushMatrix();
		ofTranslate(1100, 50);
		ofDrawBitmapString("ofEllipse", 0, labelY);
		ofEllipse(50, 50, 50, 100);
	ofPopMatrix();
	
	//ofDrawBox
	ofPushMatrix();
		ofTranslate(300, 250);
		ofDrawBitmapString("ofDrawBox", 50, labelY);
		ofNoFill();
		ofRotateY(ofGetFrameNum()%360);
		ofDrawBox(0, 0, 0, 50, 50, 50);
	ofPopMatrix();
	
	
	//ofDrawSphere
	ofPushMatrix();
		ofTranslate(300, 350);
		stringstream info;
		info << "ofDrawSphere" << "\n" << "ofGetSphereResolution: " << ofGetSphereResolution();
		ofDrawBitmapString(info.str(), 70, labelY);
		ofNoFill();
		ofRotateY(ofGetFrameNum()%360);
		//Sphere Resolution default is 20
		ofSetSphereResolution(ofGetFrameNum()%40);
		ofDrawSphere(0, 0, 0, 50);
	ofPopMatrix();
	
	//ofDrawCone
	ofPushMatrix();
		ofTranslate(300, 450);
		ofDrawBitmapString("ofDrawCone", 70, labelY);
		ofNoFill();
		ofRotateY(ofGetFrameNum()%360);
		//Cone Resolution default is 9, 3, 2
		//ofSetConeResolution(ofGetFrameNum()%18, 3, 2);
		ofDrawCone(0, 0, 0, 50, 50);
	ofPopMatrix();
	
	//ofDrawCylinder
	ofPushMatrix();
		ofTranslate(300, 550);
		ofDrawBitmapString("ofDrawCylinder", 70, labelY);
		ofNoFill();
		ofRotateY(ofGetFrameNum()%360);
		//Cylinder Resolution default is 8, 4, 2
		//ofSetCylinderResolution(ofGetFrameNum()%16, 4, 2);
		ofDrawCylinder(0, 0, 0, 20, 50);
	ofPopMatrix();
	
	//ofDrawIcoSphere
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, 0);
		ofTranslate(100, 520); //center is 0, 0 so we increment from there
		ofDrawBitmapString("ofDrawIcoSphere", 70, labelY);
		ofNoFill();
		ofRotateY(ofGetFrameNum()%360);
		//http://blender.stackexchange.com/questions/72/what-is-the-difference-between-a-uv-sphere-and-an-icosphere
		ofDrawIcoSphere(0, 0, 0, 50);
	ofPopMatrix();
	
	
	//ofDrawPlane
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, 0);	//start at center
		ofTranslate(100, 250); //center is 0, 0 so we increment from there
			ofDrawBitmapString("ofDrawPlane", 70, labelY);
			ofFill();
			ofRotateY(ofGetFrameNum()%360);
			ofDrawPlane(0, 0, 50, 50);
	ofPopMatrix();
	
	
	//ofDrawGrid
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, 0);	//start at center	
		ofTranslate(100, 350); //center is 0, 0 so we increment from there
		ofDrawBitmapString("ofDrawGrid", 70, labelY);
		//void ofDrawGrid(float scale = 10.0f, float ticks = 8.0f, bool labels = false, bool x = true, bool y = true, bool z = true)
		ofRotateY(ofGetFrameNum()%360);
		ofDrawGrid(50, 8.0f, false, true, true, true);
		
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