#pragma once

#include "ofMain.h"
#include "ConsoleListener.h"

class ofApp : public ofBaseApp, public SSHKeyListener{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	ofTexture texture;
	
	ofSpherePrimitive sphere;
    ofIcoSpherePrimitive icoSphere;
    ofPlanePrimitive plane;
    ofCylinderPrimitive cylinder;
    ofConePrimitive cone;
    ofBoxPrimitive box;
	
	vector<of3dPrimitive> primitives;
	std::size_t counter;
	
	void onCharacterReceived(SSHKeyListenerEventData& e);
	ConsoleListener consoleListener;
	
	bool wireframeMode;
	bool enableTexture;
	vector<ofMeshFace> triangles;
	
	bool doBreakApart;
	bool doResetIco;
};
