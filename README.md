**Raspberry Pi 3B+ home project.**
![result](storage/downloads/python/result.jpg)

Hardware:
- RPi 3B+
- Arduino Uno
- Waveshare 2.7 inch e-Paper
- RPi 3B+ chassis
- IR receiver/tranmitter, blue wires, breadboard, and resistors.
- IR controller (any spare TV or home theater controller will do)
- USB audio with audio output and mac input
- bluetooth audio speaker
- NFC reader/cards
- HDMI cable to TV or panel
- 5V/2A power adapter (official says it requires 5V/2.4A ?)
- Two 18650 battery with a box that powers Arduino Uno (around 7V that inputs to jack, not USB)
- Ethernet Cat 5 cable

Software:
- LibreElec 8.2.5 (need customization, that means downloading source codes are required)
- LibreELEC.USB-SD.Creator.Win32.exe (or Linux, Mac if you want)
- Python spidev module from https://github.com/doceme/py-spidev (why it doesn't include?)
- Waveshare libraries https://www.waveshare.com/wiki/2.7inch_e-Paper_HAT and https://github.com/soonuse/epd-library-python

Let's go
- LibreElec customization
  - disable CEC
  - enable bluetooth
  - enable devices by appending lines to /flash/config.txt. need to follow the instructions to overwrite it on /flash folders. https://wiki.libreelec.tv/config.txt
  ```
  dtoverlay=gpio-ir
  dtparam=spi=on
  dtparam=i2c1=on
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
  - update python version to support partial refresh
  - make weather yahoo magic on e-paper
  - more key info on the screen
  - **audio tasks**
  - either Google Drive or Music should work
  - enable nfc reader (thru Arduino or do it by RPi 3b+ directly?)
  - USB audio to bluetooth direct streaming for FM tuner??
  - **Google Assistant/ Google Home / Alexa / Apple Home / Siri**
  - TBD
