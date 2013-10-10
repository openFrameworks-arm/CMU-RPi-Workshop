#!/bin/bash

#git clone https://github.com/bakercp/ofxMediaType.git /homes/pi/openFrameworks/addons/ofxMediaType
#git clone https://github.com/bakercp/ofxSMTP.git /homes/pi/openFrameworks/addons/ofxSMTP
#git clone https://github.com/bakercp/ofxHTTP.git /homes/pi/openFrameworks/addons/ofxHTTP
#git clone https://github.com/bakercp/ofxJSON.git /homes/pi/openFrameworks/addons/ofxJSON
#git clone https://github.com/bakercp/ofxIpVideoGrabber.git /homes/pi/openFrameworks/addons/ofxIpVideoGrabber

#git clone https://github.com/bakercp/ofSketch.git /homes/pi/openFrameworks/apps/ofSketch
#git clone https://github.com/openFrameworks-arm/CMU-RPi-Workshop.git /homes/pi/openFrameworks/apps/CMU-RPi-Workshop

cd /homes/pi/openFrameworks/addons/ofxMediaType && git pull && cd -
cd /homes/pi/openFrameworks/addons/ofxSMTP && git pull && cd -
cd /homes/pi/openFrameworks/addons/ofxHTTP && git pull && cd -
cd /homes/pi/openFrameworks/addons/ofxJSON && git pull && cd -
cd /homes/pi/openFrameworks/addons/ofxIpVideoGrabber && git pull && cd -

cd /homes/pi/openFrameworks/apps/ofSketch && git pull && cd -
cd /homes/pi/openFrameworks/apps/CMU-RPi-Workshop && git pull && cd -

