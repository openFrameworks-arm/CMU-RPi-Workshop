#include "ofMain.h"
#include "ofApp.h"
//#include "ofGLProgrammableRenderer.h"

//========================================================================
int main( ){

	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	ofSetupOpenGL(1280, 720, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp( new ofApp());

}
