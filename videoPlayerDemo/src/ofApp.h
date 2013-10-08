#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ConsoleListener.h"


class ofApp : public ofBaseApp, public SSHKeyListener{

	public:
		void setup();
		void update();
		void draw();		
		void keyPressed(int key);

		ofVideoPlayer			videoPlayer;
		int						videoWidth;
		int						videoHeight;
	
        ofxCvColorImage			colorImage;
        ofxCvGrayscaleImage 	grayImage;
		ofxCvGrayscaleImage 	backgroundImage;
		ofxCvGrayscaleImage 	differenceImage;

        ofxCvContourFinder		contourFinder;
	
		int						thresholdAmount;
		bool					doLearnBackground;
		
		ofTrueTypeFont			font;
	
		void onCharacterReceived(SSHKeyListenerEventData& e);
		ConsoleListener consoleListener;
	
		bool doDrawInfo;
};

