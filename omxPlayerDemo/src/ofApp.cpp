#include "ofApp.h"


void ofApp::onVideoEnd(ofxOMXPlayerListenerEventData& e)
{
	ofLogVerbose(__func__) << " RECEIVED";
	if (files.size() ==0) 
	{
		//We have only the one file so it will just loop
		return;
	}
	if(videoCounter+1<files.size())
	{
		videoCounter++;
	}else
	{
		videoCounter = 0;
	}
	omxPlayer.loadMovie(files[videoCounter].path());
}

void ofApp::onVideoLoop(ofxOMXPlayerListenerEventData& e)
{
	ofLogVerbose(__func__) << " RECEIVED";
}


//--------------------------------------------------------------
void ofApp::setup()
{
	consoleListener.setup(this);
	ofHideCursor();
	videoCounter = 0;
	
	string videoPath = ofToDataPath("../../../videos/big_buck_bunny_MpegStreamclip_720p_h264_50Quality_48K_256k_AAC.mov", true);
	
	//this will let us just grab a video without recompiling
	ofDirectory currentVideoDirectory(ofToDataPath("../../../videos/current", true));
	bool doRandomSelect		= true;
	if (currentVideoDirectory.exists()) 
	{
		//option to put multiple videos in folder to test
		currentVideoDirectory.listDir();
		files = currentVideoDirectory.getFiles();
		if (files.size()>0) 
		{
			if (doRandomSelect && files.size()>1) {
				videoPath = files[ofRandom(files.size())].path();
			}else 
			{
				videoPath = files[0].path();
			}
		}		
	}
	
	ofLogVerbose() << "using videoPath : " << videoPath;
	settings.videoPath = videoPath;
	settings.useHDMIForAudio = true;		//default true
	
	//settings.enableTexture = false;		//default true, uncomment for direct-to-screen mode
	if (files.size()>0)
	{
		//we don't want to loop if we are switching files
		settings.enableLooping = false;		//default true
	}
	settings.enableAudio = true;
	settings.listener = this; //this app extends ofxOMXPlayerListener so it will receive events ;
	omxPlayer.setup(settings);
	
	doPixels = false;
	doDrawInfo = true;
	doShader = true;
	if (settings.enableTexture && doShader) 
	{
		shader.load("shaderExample");
		fbo.allocate(ofGetWidth(), ofGetHeight());
		fbo.begin();
			ofClear(0, 0, 0, 0);
		fbo.end();
		//turn off until s key hit
		doShader = false;
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){

	if (settings.enableTexture && doShader) 
	{
		fbo.begin();
			shader.begin();
				shader.setUniformTexture("tex0", omxPlayer.getTextureReference(), omxPlayer.getTextureID());
				shader.setUniform1f("time", ofGetElapsedTimef());
				shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
				omxPlayer.draw(0, 0, ofGetWidth(), ofGetHeight());
			shader.end();
		fbo.end();
	}
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (!settings.enableTexture) return; //direct to screen - nothing else draws so returning
	
	if (doShader) 
	{
		fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	}else 
	{
		omxPlayer.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
	if (doPixels) 
	{
		//must be done in draw()
		omxPlayer.updatePixels();
		image.setFromPixels(GlobalEGLContainer::getInstance().pixels);
		image.draw(800, 0, 400, 300);
	}
	if (doDrawInfo) 
	{
		stringstream info;
		info <<"\n" <<  "APP FPS: "+ ofToString(ofGetFrameRate());
		
		
		info <<"\n" <<	"MEDIA TIME: "			<< omxPlayer.getMediaTime();
		info <<"\n" <<	"OF DIMENSIONS: "		<< ofGetWidth()<<"x"<<ofGetHeight();
		info <<"\n" <<	"DIMENSIONS: "			<< omxPlayer.getWidth()<<"x"<<omxPlayer.getHeight();
		info <<"\n" <<	"DURATION: "			<< omxPlayer.getDuration();
		info <<"\n" <<	"TOTAL FRAMES: "		<< omxPlayer.getTotalNumFrames();
		info <<"\n" <<	"CURRENT FRAME: "		<< omxPlayer.getCurrentFrame();
		info <<"\n" <<	"REMAINING FRAMES: "	<< omxPlayer.getTotalNumFrames() - omxPlayer.getCurrentFrame();
		
		info <<"\n" <<	"CURRENT VOLUME: "		<< omxPlayer.getVolume();
		
		info <<"\n" <<	"KEYS:";
		info <<"\n" <<	"t to Toggle Info Display";
		info <<"\n" <<	"p to Toggle Pause";
		info <<"\n" <<	"b to Step frame forward";
		info <<"\n" <<	"s to Toggle Shader";
		info <<"\n" <<	"1 to Decrease Volume";
		info <<"\n" <<	"2 to Increase Volume";
		info <<"\n" <<	"x to Toggle Pixel Access";
		ofDrawBitmapStringHighlight(info.str(), 60, 60, ofColor(0, 0, 0, 90), ofColor::yellow);
	}
	
}



void ofApp::onCharacterReceived(SSHKeyListenerEventData& e)
{
	//ConsoleListener* thread = (ConsoleListener*) e.listener;
	keyPressed((int)e.character);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLogVerbose() << "key received!";
	switch (key) 
	{
		case 'p':
		{
			ofLogVerbose() << "pause: " << !omxPlayer.isPaused();
			omxPlayer.setPaused(!omxPlayer.isPaused());
			break;
			
		}
		
		case '1':
		{
			
			ofLogVerbose() << "decreaseVolume";
			omxPlayer.decreaseVolume();
			break;
		}
		case '2':
		{
			ofLogVerbose() << "increaseVolume";
			omxPlayer.increaseVolume();
			break;
		}
			
		case 'b':
		{
			ofLogVerbose() << "stepFrameForward";
			omxPlayer.stepFrameForward();
			break;
		}
		case 'x':
		{
			ofLogVerbose() << "doPixels";
			doPixels = !doPixels;
			break;
		}
		case 't':
		{
			doDrawInfo = !doDrawInfo;
			break;
		}
		case 's':
		{
			doShader = !doShader;
			break;
		}
			
		default:
		{
			break;
		}
	}
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

