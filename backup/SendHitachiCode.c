byte start_conditioner[]   = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,};
byte speedup_conditioner[] = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,};
byte stop_conditioner[]    = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,};
const int CON_START_PULSE = 3400;
const int CON_START_PAUSE = 1700;
const int CON_PULSE_LEN = 450;
const int CON_PAUSE_HIGH = 1200; 
const int CON_PAUSE_LOW = 500;

byte full_light[]  = {1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,1,};
byte sleep_light[] = {1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,};
byte off_light[]   = {1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,1,1,0,};
const int LIGHT_START_PULSE = 10260;
const int LIGHT_START_PAUSE = 5100;
const int LIGHT_PULSE_LEN = 650;
const int LIGHT_PAUSE_HIGH = 1900;
const int LIGHT_PAUSE_LOW = 620;

const int LIGHT_STOP_PAUSE1 = 45356;
const int LIGHT_STOP_PULSE1 = 10240;
const int LIGHT_STOP_PAUSE2 = 2532;
const int LIGHT_STOP_PULSE2 = 676;

const int IRPIN = 9;
long startMicros;

void setup(){
  // IR input
  pinMode(IRPIN, OUTPUT);

  // serial communication
  Serial.begin(115200);
}

void loop(){
  if (Serial.available()) {
    switch(Serial.read() - '0') {
      case 0: // Start Conditioner
        sendconditioner(start_conditioner, sizeof(start_conditioner));
        break;
      case 1: // speedup conditioner
        sendconditioner(speedup_conditioner, sizeof(speedup_conditioner));
        break;
      case 2: // stop conditioner
        sendconditioner(stop_conditioner, sizeof(stop_conditioner));
        break;
      case 3: // full light
        sendlight(full_light, sizeof(full_light));
        break;
      case 4: // sleep light
        sendlight(sleep_light, sizeof(sleep_light));
        break;
      case 5: // off light
        sendlight(off_light, sizeof(off_light));
        break;
    }
  }

  // repeat code every 5 seconds for demonstration
  delay(10000);
}

void sendconditioner(byte *bits, int len){
  // send control pulses

  // long start pulse
  sendPulse(CON_START_PULSE);

  // long start delay
  delayMicroseconds(CON_START_PAUSE);

  // regular pulse before data
  sendPulse(CON_PULSE_LEN);

  // send data
  for (int i=0; i < len; i++){
    
    //send bit (pause)
    byte bit = bits[i];
    if (bit == 0){
      delayMicroseconds(CON_PAUSE_LOW);
    }
    if (bit == 1){
      delayMicroseconds(CON_PAUSE_HIGH);
    }    
    
    //send pulse after bit
    sendPulse(CON_PULSE_LEN);
 }
}

void sendlight(byte *bits, int len) {
  // send control pulses

  // long start pulse
  sendPulse(LIGHT_START_PULSE);

  // long start delay
  delayMicroseconds(LIGHT_START_PAUSE);

  // regular pulse before data
  sendPulse(LIGHT_PULSE_LEN);

  // send data
  for (int i=0; i < len; i++){
    
    //send bit (pause)
    byte bit = bits[i];
    if (bit == 0){
      delayMicroseconds(LIGHT_PAUSE_LOW);
    }
    if (bit == 1){
      delayMicroseconds(LIGHT_PAUSE_HIGH);
    }    
    
    //send pulse after bit
    sendPulse(LIGHT_PULSE_LEN);
  }

  // long stop delay 1 (45356)
  delay(40);
  delayMicroseconds(5356);
  
  // long stop pulse 1
  sendPulse(LIGHT_STOP_PULSE1);

  // long stop delay 2
  delayMicroseconds(LIGHT_STOP_PAUSE2);

  // long stop pulse 2
  sendPulse(LIGHT_STOP_PULSE2);
}

void sendPulse(int pulseLength){
  int IR_on = 0;
  long startMicros;
  startMicros = micros();
  while (micros() < (startMicros + pulseLength)){
    // toggle pin and wait 26 us to make it a pulse
    if (IR_on == 0) {
      IR_on = 1;
    }
    else {
      IR_on = 0;
    }
    digitalWrite(IRPIN, IR_on);
    delayMicroseconds(26); // 1000000(us)/38000(hz) = 26(us)
  }
  
  // turn off IR after pulse is complete
  digitalWrite(IRPIN, LOW);
}
