#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofHideCursor();
	
	/*
		The player has a lot of options so we use ofxOMXPlayerSettings
		to pass them in on initialization
		These are the defaults:
    */

	//settings.useHDMIForAudio	= true; //audio plays through HDMI
	//settings.enableTexture	= false; //gives you a texture you can resize/manipulate with shaders
	//settings.enableLooping	= true; //looping option
	//settings.listener			= NULL; //enables onVideoEnd, onVideoLoop, callbacks in your ofApp
	//settings.enableAudio		= true; //disable audio to use fewer resources
	
	settings.videoPath = ofToDataPath("../../../videos/big_buck_bunny_MpegStreamclip_720p_h264_50Quality_48K_256k_AAC.mov", true);
	settings.listener = this;
	
	//if textures are enabled (default) we can use shaders
	if (settings.enableTexture) 
	{
		shader.load("PostProcessing");
		doShader = true;
		//due to some EGL quirkiness we currently need to use an ofFbo with shaders
		//otherwise the image is flipped
		fbo.allocate(ofGetWidth(), ofGetHeight());
		fbo.begin();
			ofClear(0, 0, 0, 0);
		fbo.end();
		//let's disable the shader until we hit the s key
		doShader = false;
		doDrawInfo = true;
	}else
	{
		doShader = false;
	}
	
	
	omxPlayer.setup(settings);
	
	
	//Allows us to receive a-z,0-9 keys through ssh/terminal
	consoleListener.setup(this);
	
	
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
				omxPlayer.draw(0, 0);
			shader.end();
		fbo.end();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	/*
	 If textures are NOT enabled you won't see any of this as
	 OpenMax will be rendering directly to the screen at full screen
	 bypassing any OF drawing functions
	*/
	if (!settings.enableTexture) return;
	
	if (doShader) 
	{
		fbo.draw(0, 0);
	}else 
	{
		omxPlayer.draw(0, 0);
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
		info <<"\n" <<	"t to Toggle Info";
		info <<"\n" <<	"p to Toggle Pause";
		info <<"\n" <<	"b to Step frame forward";
		info <<"\n" <<	"s to Toggle Shader";
		info <<"\n" <<	"1 to Decrease Volume";
		info <<"\n" <<	"2 to Increase Volume";
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
		case 's':
		{
			doShader = !doShader;
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
		case 't':
		{
			doDrawInfo = !doDrawInfo;
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

