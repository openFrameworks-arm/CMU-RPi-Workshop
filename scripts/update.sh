#!/bin/bash

#git clone https://github.com/bakercp/ofxMediaType.git /home/pi/openFrameworks/addons/ofxMediaType 2> /dev/null
git clone https://github.com/bakercp/ofxSMTP.git /home/pi/openFrameworks/addons/ofxSMTP 2> /dev/null
git clone https://github.com/bakercp/ofxHTTP.git /home/pi/openFrameworks/addons/ofxHTTP 2> /dev/null
git clone https://github.com/bakercp/ofxJSON.git /home/pi/openFrameworks/addons/ofxJSON 2> /dev/null
git clone https://github.com/bakercp/ofxIpVideoGrabber.git /home/pi/openFrameworks/addons/ofxIpVideoGrabber 2> /dev/null
git clone https://github.com/bakercp/ofxZeroconf.git /home/pi/openFrameworks/addons/ofxZeroconf 2> /dev/null
git clone https://github.com/bakercp/ofxSerial.git /home/pi/openFrameworks/addons/ofxSerial 2> /dev/null
git clone https://github.com/bakercp/ofxESCPOSPrinter.git /home/pi/openFrameworks/addons/ofxESCPOSPrinter 2> /dev/null
git clone https://github.com/bakercp/ofxIO.git /home/pi/openFrameworks/addons/ofxIO 2> /dev/null
git clone https://github.com/bakercp/ofxLibmagic.git /home/pi/openFrameworks/addons/ofxLibmagic 2> /dev/null

git clone https://github.com/bakercp/ofSketch.git /home/pi/openFrameworks/apps/ofSketch 2> /dev/null
git clone https://github.com/openFrameworks-arm/CMU-RPi-Workshop.git /home/pi/openFrameworks/apps/CMU-RPi-Workshop 2> /dev/null

#cd /home/pi/openFrameworks/addons/ofxMediaType && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxSMTP && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxHTTP && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxJSON && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxIpVideoGrabber && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxZeroconf && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxSerial && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxESCPOSPrinter && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxIO && git pull && cd -
cd /home/pi/openFrameworks/addons/ofxLibmagic && git pull && cd -

cd /home/pi/openFrameworks/apps/ofSketch && git pull && cd -
cd /home/pi/openFrameworks/apps/CMU-RPi-Workshop && git pull && cd -

cd /home/pi/openFrameworks/apps/CMU-RPi-Workshop/scripts && ./buildAddons.sh  && cd -