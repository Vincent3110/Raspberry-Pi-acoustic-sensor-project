My Gihub link : https://github.com/Vyod/Raspberry-Pi-acoustic-sensor-project

Raspberry Pi acoustic sensor project

This project will turn a raspberry Pi 3 into an acoustic sensor

I. Configuration

A) Hardware configuration

A raspberry Pi 3 is recommended

NOTE : If a older version of Pi is used, corresponding configuration might be changed. The Pi is mounted with a USB sound card, and plugged in a microphone. It is recommended to have Ethernet connection for your Pi.

B) Software configurations
The USB sound card has to be set as default audio device. To do so, you need to modify two files with following contents.

1 Use “lsusb” command to check if your USB sound card is mounted or not.

2 Use command: "sudo nano /etc/asound.conf"  and put following content to the file:
 pcm.!default { 
	type plug slave {
	 pcm "hw:1,0" 
} 
}
 ctl.!default { 
type hw 
card 1 
}

3 Use command nano .asoundrc and put the same content.

4  Run alsamixer and check USB sound card as the default audio device. 

NOTE : If you are using Raspian Jessie (version 1.0.28), you have to roll-back alsa-utils to an earlier version (1.0.25). You can read the instruction below. 

NOTE : If you get a notice like : fatal error: curl/curl.h: No such file or directory , you have to down libcurl. You can read the instruction below



Install libcurl
1. First use command “ls /usr/include/curl” to identify that /usr/include/curl/ folder exists or not.

2. If the folder doesn’t exist. Run “sudo apt-get update” to update the application list.

3. Run “sudo apt-get install libcurl3” to install the libcurl3.

4. Run “sudo apt-get install libcurl4-openssl-dev” to install the development API of libcurl4.


Install version 1.0.25

The newest version of Raspbian comes with a new version of alsa-utils (1.0.28), which has a bug while recording: it doesn't stop even a '-duration' switch is given, and generates lots of useless audio files. To fix this problem, we have to downgrade alsa-util to an earlier version (1.0.25).

1 Use "sudo nano /etc/apt/sources.list" command and add : "deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi".

2 Run "sudo apt-get update".

3 Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-util is availble.

4 Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade.

5 Reboot (if necessary).

6 Run “arecord -r44100 -c1 -f S16_LE -d5 test.wav” to test that your microphone is working. You should see a “test.wav” file in the current folder.

7 Put earphone on. Run “aplay test.wav” to check that your recording is okay.

By Vy , Do Xuan
vydx91@gmail.com
