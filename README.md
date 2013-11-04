Project files for the Creative Coding on the RaspberryPi workshop held at the Frank-Ratchye STUDIO for Creative Inquiry at Carnegie Mellon University 
http://studioforcreativeinquiry.org/events/creative-coding-on-the-raspberry-pi-with-openframeworks

Requires openFrameworks 0.8.0 or higher: http://www.openframeworks.cc/setup/raspberrypi/

Clone or download into openframeworks/apps/

### If you attended the workshop and used one of the non HDMI monitors you need to do these steps to use an HDMI monitor


`$ sudo nano /boot/config.txt`

use arrows to scroll down to the lines

`````
hdmi_group=1
hdmi_mode=7
````
and add `#` to each line so it looks like
````
#hdmi_group=1
#hdmi_mode=7
````

press Ctrl+X to exit and press Y to confirm the save

run

````
$ sudo reboot
````

### You will also need to disconnect from the distcc server that we used ###

log into the RPi

````
$ cd ~
$ nano .profile
````


scroll with the arrows down to the line

`export MAKEFLAGS="-j 64 CXX=/usr/lib/distcc/g++ CC=/usr/lib/distcc/gcc"`

and add a `#`

so it looks like

`#export MAKEFLAGS="-j 64 CXX=/usr/lib/distcc/g++ CC=/usr/lib/distcc/gcc"`

press Ctrl+X to exit and press Y to confirm the save


### Disk image
The user/password for the image is pi/pi   

The image file is currently located at
http://www.jvcref.com/files/PI/CMU_OF_RPI_MASTER.img

MIRROR (Google Drive)
https://docs.google.com/uc?id=0BwE_LuEnOqp3aVlFc0lRTXI0SGc&export=download





