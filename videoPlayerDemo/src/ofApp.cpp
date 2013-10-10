#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	font.loadFont( "DIN.otf", 8 );
	
	//ofSetVerticalSync(false);
	videoPlayer.loadMovie("fingers.mp4");
	videoPlayer.setLoopState(OF_LOOP_NORMAL); //must set this after loadMovie on the RPI
	
	videoWidth	= videoPlayer.getWidth();
	videoHeight = videoPlayer.getHeight();
	videoPlayer.play();
	
    colorImage.allocate(videoWidth, videoHeight);
	grayImage.allocate(videoWidth, videoHeight);
	backgroundImage.allocate(videoWidth, videoHeight);
	differenceImage.allocate(videoWidth, videoHeight);

	doLearnBackground = true;
	thresholdAmount = 80;
	
	consoleListener.setup(this);
	
	doDrawInfo = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(100,100,100);


	videoPlayer.update();
	if (videoPlayer.isFrameNew())
	{

		colorImage.setFromPixels(videoPlayer.getPixels(), videoWidth,videoHeight);
		
		//convert the video to grayscale used in later thresholding
        grayImage = colorImage;
		if (doLearnBackground)
		{
			//copy the pixels from grayImage into backgroundImage
			backgroundImage = grayImage; 
			doLearnBackground = false;
		}

		// take the abs value of the difference between 
		// the static background captured and grayscale version of the video source
		differenceImage.absDiff(backgroundImage, grayImage);
		
		//and then threshold:
		differenceImage.threshold(thresholdAmount);
		
		int minArea = 20;							//smallest blob size to consider (in pixels)
		int maxArea = (videoWidth*videoHeight)/3;	//largest blob size to consider (in pixels)
		int numBlobsConsidered = 10;				//max number of blobs to look for
		bool doFindHoles = true;					//look for interior contours
		
		/*
		 * doApproximation:
		 * don't do points for all points of the contour. 
		 * For example, if the contour runs along a straight line
		 */
		bool doApproximation = true;
		
		contourFinder.findContours(differenceImage,
								   minArea,
								   maxArea,
								   numBlobsConsidered,
								   doFindHoles,
								   doApproximation);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	int padding = 40; //this may vary on the RPi depending on your monitor
	int textMargin = 20;
	ofPushMatrix();
		ofTranslate(padding, padding);
		//Draw video source
		ofPushMatrix();
			colorImage.draw(0, 0);
			if(doDrawInfo) font.drawString("colorImage", textMargin, textMargin);
		ofPopMatrix();
		
		//Draw Grayscale video
		ofPushMatrix();
			ofTranslate(videoWidth, 0);
			grayImage.draw(0, 0);
			if(doDrawInfo) font.drawString("grayImage", textMargin, textMargin);
		ofPopMatrix();
		
		//Draw Background
		ofPushMatrix();
			ofTranslate(0, videoHeight);
			backgroundImage.draw(0, 0);
			if(doDrawInfo) font.drawString("backgroundImage", textMargin, textMargin);
		ofPopMatrix();
		
		//Draw Difference Image
		ofPushMatrix();
			ofTranslate(videoWidth, videoHeight);
			differenceImage.draw(0, 0);
			if(doDrawInfo) font.drawString("differenceImage", textMargin, textMargin);
		ofPopMatrix();
		
		//Draw Contours
		ofPushMatrix();
			ofTranslate(videoWidth, videoHeight);
			ofPushStyle();
				contourFinder.draw(0, 0);
			ofPopStyle();
		ofPopMatrix();
		
		//Draw each Blob
		ofPushMatrix();
			ofPushStyle();
			ofTranslate(videoWidth, videoHeight);
			for (int i = 0; i < contourFinder.blobs.size(); i++)
			{
				contourFinder.blobs[i].draw(0, 0);
				// Draw over the centroid if the blob is a hole
				if(contourFinder.blobs[i].hole)
				{
					//font.drawString("hole", contourFinder.blobs[i].boundingRect.getCenter().x, contourFinder.blobs[i].boundingRect.getCenter().y);
				}
			}
			ofPopStyle();
		ofPopMatrix();
		
		ofPushMatrix();
			ofTranslate(0, videoHeight*2);
			stringstream info;
			info << "Press 't' to toggle labels (fps increase)"						<< "\n";
			info << "Press 'b' to capture background"								<< "\n";
			info << "Press e/r to increase/decrease threshold " << thresholdAmount	<< "\n";
			info << "Blobs found: " << contourFinder.blobs.size()					<< "\n";
			info << "FPS: " << ofGetFrameRate();
			font.drawString( info.str(), 2, textMargin);
		ofPopMatrix();
	
	ofPopMatrix();
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key){
		case 't':
			doDrawInfo = !doDrawInfo;
			break;
		case 'b':
			doLearnBackground = true;
			break;
		case 'r':
			thresholdAmount +=10;
			if (thresholdAmount > 255) thresholdAmount = 255;
			break;
		case 'e':
			thresholdAmount -=10;
			if (thresholdAmount < 0) thresholdAmount = 0;
			break;
		case 'd':
			thresholdAmount =80;
			break;
	}
}

void ofApp::onCharacterReceived(SSHKeyListenerEventData& e)
{
	keyPressed((int)e.character);
}