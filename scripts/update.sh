#!/bin/bash

git clone https://github.com/bakercp/ofxMediaType.git /home/pi/openFrameworks/addons/ofxMediaType 2> /dev/null
git clone https://github.com/bakercp/ofxSMTP.git /home/pi/openFrameworks/addons/ofxSMTP 2> /dev/null
git clone https://github.com/bakercp/ofxHTTP.git /home/pi/openFrameworks/addons/ofxHTTP 2> /dev/null
git clone https://github.com/bakercp/ofxJSON.git /home/pi/openFrameworks/addons/ofxJSON 2> /dev/null
git clone https://github.com/bakercp/ofxIpVideoGrabber.git /home/pi/openFrameworks/addons/ofxIpVideoGrabber 2> /dev/null

git clone https://github.com/bakercp/ofSketch.git /home/pi/openFrameworks/apps/ofSketch 2> /dev/null
git clone https://github.com/openFrameworks-arm/CMU-RPi-Workshop.git /home/pi/openFrameworks/apps/CMU-RPi-Workshop 2> /dev/null

cd /home/pi/openFrameworks/addons/ofxMediaType && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxSMTP && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxHTTP && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxJSON && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxIpVideoGrabber && git pull && cd -

cd /home/pi/openFrameworks/apps/ofSketch && git pull && cd -
cd /home/pi/openFrameworks/apps/CMU-RPi-Workshop && git pull && cd -

