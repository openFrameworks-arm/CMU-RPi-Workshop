#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	doDrawInfo	= true;
	doShader	= false;
	shader.load("PostProcessing.vert", "PostProcessing.frag", "");
	
	consoleListener.setup(this);
	videoGrabber.setup(1280, 720, 60);
	
}

//--------------------------------------------------------------
void testApp::update()
{
	//
}


//--------------------------------------------------------------
void testApp::draw(){

	if (doShader) 
	{
		shader.begin();
			shader.setUniformTexture("tex0", videoGrabber.getTextureReference(), videoGrabber.getTextureID());
			shader.setUniform1f("time", ofGetElapsedTimef());
			shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight()); 
			videoGrabber.draw();
		shader.end();
		
	}else 
	{
		videoGrabber.draw();
	}
	if (doDrawInfo && !doShader) 
	{
		stringstream info;
		info << "App FPS: " << ofGetFrameRate() << "\n";
		info << "Camera Resolution: " << videoGrabber.getWidth() << "x" << videoGrabber.getHeight()	<< " @ "<< videoGrabber.getFrameRate() <<"FPS"<< "\n";
		info << "CURRENT FILTER: " << filterCollection.currentFilter.name << "\n";
		info <<	filterCollection.filterList << "\n";
		
		info << "KEYS \n";
		info << "s to enable Shader ENABLED: " << doShader << "\n";
		info << "e to increment filter" << "\n";
		info << "r for Random filter" << "\n";
		info << "t to Toggle info" << "\n";
		ofDrawBitmapStringHighlight(info.str(), 100, 100, ofColor::black, ofColor::yellow);
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key)
{
	ofLogVerbose(__func__) << key;
	if (key == 's') 
	{
		doShader = !doShader;
		
	}
	if (key == 'r')
	{
		videoGrabber.applyImageFilter(filterCollection.getRandomFilter().type);
	}
	
	if (key == 'e')
	{
		videoGrabber.applyImageFilter(filterCollection.getNextFilter().type);
	}
	
	if (key == 't')
	{
		doDrawInfo = !doDrawInfo;
	}
}

void testApp::onCharacterReceived(SSHKeyListenerEventData& e)
{
	keyPressed((int)e.character);
}

