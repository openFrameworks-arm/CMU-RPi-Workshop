#pragma once

#include <set>
#include "ofMain.h"
#include "ofxOsc.h"

#include "CommonTime/CommonTimeOsc.h"
#include "Server/ServerOscManager.h"
#include "Client/ClientOSCManager.h"


// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
class ofApp : public ofBaseApp
{
    
public:
    
    void				setup();
    void				update();
    void				draw();
    
    void				keyPressed(int key);
    void				keyReleased(int key);
    void				mouseMoved(int x, int y );
    void				mouseDragged(int x, int y, int button);
    void				mousePressed(int x, int y, int button);
    void				mouseReleased(int x, int y, int button);
    
    bool				isServer;
    void                newData( DataPacket& _packet  );
    
    CommonTimeOSC*		commonTimeOsc;
    ClientOSCManager*   client;
    ServerOscManager*   server;
	
    ofTrueTypeFont		fontSmall;
    float               currTime;
    
    int                 screenIndex;
    int                 displayWidth;
    int                 displayHeight;
    int                 viewWidth;
    int                 viewHeight;
    int                 screenOffsetX;
    int                 screenOffsetY;
    
};
