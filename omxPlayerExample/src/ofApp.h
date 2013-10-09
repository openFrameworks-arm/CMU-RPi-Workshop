#pragma once

#include "ofMain.h"
#include "ofxOMXPlayer.h"
#include "ConsoleListener.h"


class ofApp : public ofBaseApp, public SSHKeyListener, public ofxOMXPlayerListener{
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
	
	ofxOMXPlayerSettings settings;
	ofxOMXPlayer omxPlayer;
	ofShader shader;
	bool doShader;
	ofFbo fbo;
	
	//allows key commands via Shell
	void onCharacterReceived(SSHKeyListenerEventData& e);
	ConsoleListener consoleListener;
	
	//ofxOMXPlayerListener inheritance
	void onVideoEnd(ofxOMXPlayerListenerEventData& e){};
	void onVideoLoop(ofxOMXPlayerListenerEventData& e){};
	
	bool doDrawInfo;
};
