#include "ofApp.h"

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::setup()
{
	isServer = false;
	
	fontSmall.loadFont("Fonts/DIN.otf", 8 );
		
	ofSeedRandom();
	int uniqueID = ofRandom( 999999999 ); // Yeah this is bogus I know. Good enough for our purposes.
    server = NULL;
	client = NULL;
	
    if( ofFile( ofToDataPath("Settings/IsServer.txt")).exists() )
	{
		server = new ServerOscManager();
		server->init( "Settings/ServerSettings.xml" );
        
		isServer = server->isInitialised();
        cout<<"Starting Server"<<endl;
	}
	else
	{
		client = new ClientOSCManager();
		client->init( uniqueID );
		
		commonTimeOsc = client->getCommonTimeOscObj();
		commonTimeOsc->setEaseOffset( true );
		
		ofAddListener( client->newDataEvent, this, &ofApp::newData );
        
        cout<<"Starting Client"<<endl;
	}
    
    // Read the screen index from a file
	ofxXmlSettings XML;
	bool loadedFile = XML.loadFile( "Settings/ClientSettings.xml" );
	if( loadedFile )
	{
		        
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::update()
{
     currTime = 0.0f;
    if( isServer ) { currTime = ofGetElapsedTimef(); } else { currTime = commonTimeOsc->getTimeSecs(); }
    
	
    
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::draw()
{

	// Set a color that pulsates based on the time we get
	ofColor bgColor;
	bgColor.setHsb( ((cosf(currTime/10.0f)+1.0f)/2.0f) * 255, 180, ((cosf(currTime*1.4f)+1.0f)/2.0f) * 255 );
	ofSetColor(bgColor);
	ofRect(0,0,ofGetWidth(), ofGetHeight() );

	// Rotate a circle
	ofColor circleColor = bgColor.getInverted();
	ofSetColor(circleColor);	
	ofPushMatrix();
		ofTranslate(ofGetWidth() * 0.5f, ofGetHeight() * 0.5f );
		ofRotate( currTime * 50.0f );
		ofTranslate( ofGetHeight() * 0.45f, 0 );
		ofCircle( 0, 0, 40 );
	ofPopMatrix();
	
	ofSetColor(255);
	
    if( isServer )
    {
        fontSmall.drawString( "Server", 300, 85 );
    }
    else
    {
        fontSmall.drawString( "Offset: " + ofToString(commonTimeOsc->offsetMillis) + " OffsetTarget: " + ofToString(commonTimeOsc->offsetMillisTarget), 300, 80 );
    }
	
}

void ofApp::newData( DataPacket& _packet  )
    {
        if(!isServer){
            string foo = _packet.valuesString[0];
        }
    }

    
    
// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::keyPressed(int key)
{
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::keyReleased(int key)
{
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::mouseMoved(int x, int y )
{
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::mouseDragged(int x, int y, int button)
{
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::mousePressed(int x, int y, int button)
{
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
void ofApp::mouseReleased(int x, int y, int button)
{
}
