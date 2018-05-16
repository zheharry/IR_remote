**Raspberry Pi 3B+ home project.**

![result](storage/downloads/python/result.bmp)

Hardware:
- RPi 3B+
- Arduino Uno
- Waveshare 2.7 inch e-Paper
- RPi 3B+ chassis
- IR receiver/tranmitter, blue wires, breadboard, and resistors.
- IR controller (any spare TV or home theater controller will do)
- USB audio with audio output and mac input, any length of audio cable
- bluetooth audio speaker
- NFC reader/cards
- HDMI cable to TV or panel
- 5V/2A power adapter or power bank (official says it requires 5V/2.4A ?)
- Two 18650 battery with a box that powers Arduino Uno (around 7V that inputs to jack, not USB)
- Ethernet Cat 5 cable

Software:
- LibreElec 8.2.5 (need customization, that means downloading source codes are required)
- LibreELEC.USB-SD.Creator.Win32.exe (or Linux, Mac if you want)
- Python spidev module from https://github.com/doceme/py-spidev (why it doesn't include?)
- Waveshare libraries https://www.waveshare.com/wiki/2.7inch_e-Paper_HAT and https://github.com/soonuse/epd-library-python

Let's go
- LibreElec customization
  - add add-ons: Rasberry Pi Tools / System Tools / Adafruit Libraries
  - disable CEC
  - enable bluetooth
  - enable devices by appending lines to /flash/config.txt. need to follow the instructions to overwrite it on /flash folders. https://wiki.libreelec.tv/config.txt
  ```
  dtoverlay=gpio-ir
  dtparam=spi=on
  dtparam=i2c1=on
  ```
  - **GPIO tasks**
  - install /storage/.config/system.d/in.service
  ```
  [Unit]
  Description = GPIO monitor

  [Service]
  Type = idle
  ExecStart = /storage/downloads/python/in.py

  [Install]
  WantedBy = multi-user.target
  ```
  - /storage/downloads/python/in.py
  ```
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
  ```
  ```
  systemctl enable in
  systemctl start in
  ```
  - **IR tasks**
  - add your IR controller profile (e.g. pioneer) to /storage/.config/rc_keymaps/pioneer. remember to follow the link: https://wiki.libreelec.tv/infrared_remotes
  - /storage/.config/rc_maps.cfg:
  ```
  * * pioneer
  ```
  - /storage/.config/autostart.sh:  (remember to chmod 644 it!)
  ```
  ir-keytable -a /storage/.config/rc_maps.cfg
  ```
  - control lights, air conditioner
  - **e-paper tasks**
  - install spidev.so for python. prepare a development environment and package.mk to build it.
  ```
  harry@vm:~/src$ git clone https://github.com/LibreELEC/LibreELEC.tv.git
  harry@vm:~/src$ cd LibreELEC.tv
  harry@vm:~/src/LibreELEC.tv$ scripts/build spidev
  ```
  - partial refresh is not support, according to waveshare website.
  - make weather yahoo magic on e-paper
  - more key info on the screen
  - **audio tasks**
  - either Google Drive or Music should work
  - enable nfc reader (thru Arduino or do it by RPi 3b+ directly?)
  - USB audio to bluetooth direct streaming for FM tuner??
  - **Google Assistant/ Google Home / Alexa / Apple Home / Siri**
  - TBD
