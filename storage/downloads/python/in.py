#!/usr/bin/python
import os, sys
sys.path.append('/storage/.kodi/addons/virtual.rpi-tools/lib')
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup( 5, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup( 6, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(13, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(19, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def my_callback(channel):
    if channel == 5:
        os.system('shutdown now')
    #print "falling edge detected on %d" % channel
    
GPIO.add_event_detect( 5, GPIO.FALLING, callback=my_callback, bouncetime=300)
GPIO.add_event_detect( 6, GPIO.FALLING, callback=my_callback, bouncetime=300)
GPIO.add_event_detect(13, GPIO.FALLING, callback=my_callback, bouncetime=300)
GPIO.add_event_detect(19, GPIO.FALLING, callback=my_callback, bouncetime=300)

while True:  
    pass
