/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */


#include <IRremote.h>

IRsend irsend;

int khz = 38; // 38kHz carrier frequency for the NEC protocol
int on = 0;

void mydelay(int delayed)
{
  int i;
  for (i=0; i<5; i++) {
    on = !on;
    digitalWrite(13, on ? HIGH : LOW);
    delay(delayed); //In this example, the signal will be repeated every 5 seconds, approximately.
  }
}

void setup()
{
  pinMode(13, OUTPUT);
}

void SendPower()
{
  // Power
  unsigned int  rawData1[47] = {650,1900, 600,1900, 1900,650, 1900,650, 600,1900, 600,1950, 1850,650, 1900,650, 600,1950, 600,1900, 1900,650, 1900,650, 1850,650, 650,1900, 1850,650, 650,1900, 600,1950, 600,1900, 1900,650, 1900,600, 1900,650, 600,1950, 1850,650, 650};  // UNKNOWN F18AEB1F

  irsend.sendRaw(rawData1, sizeof(rawData1) / sizeof(rawData1[0]), khz); //Note the approach used to automatically calculate the size of the array.

  mydelay(1000);
}

void SendTimer()
{
  // Timer 30 mins
  unsigned int  rawData2[47] = {600,1950, 600,1900, 1900,650, 1850,700, 600,1900, 600,1950, 1850,650, 1900,650, 600,1950, 1900,600, 1900,650, 600,1950, 600,1900, 650,1900, 1900,650, 600,1900, 650,1900, 1900,600, 1900,650, 650,1900, 600,1900, 650,1900, 1900,650, 600};  // UNKNOWN 62828C97

  irsend.sendRaw(rawData2, sizeof(rawData2) / sizeof(rawData2[0]), khz); //Note the approach used to automatically calculate the size of the array.

  mydelay(1000);
}

void SendIon()
{
  // ION
  unsigned int  rawData3[47] = {650,1900, 600,1900, 1900,650, 1900,600, 650,1900, 600,1900, 1900,650, 1900,650, 1900,600, 650,1900, 650,1900, 1900,600, 1900,650, 1900,650, 600,1900, 650,1900, 1900,600, 650,1900, 600,1950, 1900,600, 1950,600, 1900,650, 600,1900, 650};  // UNKNOWN 2E2B6C82

  irsend.sendRaw(rawData3, sizeof(rawData3) / sizeof(rawData3[0]), khz); //Note the approach used to automatically calculate the size of the array.

  mydelay(1000);
}

void SendSpeed() {
  // Speed level 1-4
  unsigned int  rawData4[47] = {650,1850, 650,1900, 1900,600, 1900,650, 600,1950, 600,1900, 1850,700, 1850,700, 550,1950, 1900,650, 600,1900, 1900,650, 1900,650, 550,1950, 600,1950, 600,1900, 650,1900, 1850,700, 600,1900, 1900,650, 1900,650, 600,1900, 650,1900, 600};  // UNKNOWN BBCD5C52

  irsend.sendRaw(rawData4, sizeof(rawData4) / sizeof(rawData4[0]), khz); //Note the approach used to automatically calculate the size of the array.

  mydelay(1000);
}

void loop()
{
  SendPower();

  SendTimer();
  SendTimer();
  SendTimer();
  SendTimer();

  SendIon();

  SendSpeed();
  SendSpeed();
  SendSpeed();

  mydelay(300);
}

