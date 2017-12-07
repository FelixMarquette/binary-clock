/*
An open-source binary clock for Arduino.
Based on the code from by Rob Faludi (http://www.faludi.com)
Code under (cc) by Lucas Berbesson
http://creativecommons.org/license/cc-gpl
*/

int second=0, minute=56, hour=9; //start the time on 00:00:00

int munit,hunit,valm=0,minuteTens,hourTens, valh=0,ledstats,i;
// LEDS positions matrix
int leds[4][4] = { 
 {17,1,17,0},
 {17,13,2,3},
 {10,9,7,4},
 {11,12,8,5}
};
void setup() {
  //set outputs
  for(int k=0;k<=13;k++) {
    pinMode(k, OUTPUT);
    digitalWrite(k, LOW);

  }
}

void loop() {

  static unsigned long lastTick = 0;
  // counting time here
  if (millis() - lastTick < 1000) {
    return;
  } else {
    lastTick = millis();
    second++;
  }

  // Add 1 minute every 60 seconds
  if (second >= 60) {
    minute++;
    second = 0; // reset seconds
  }

  // Add 1 hour every 60 minutes
  if (minute >=60) {
    hour++;
    minute = 0; // reset minutes
  }

  // Add 1 day every 24 hour
  if (hour >=24) {
    hour  = 0; // reset hours
    minute  = 0; // reset minutes
  }

  munit = minute%10; //sets the variable munit and hunit for the unit digits
  hunit = hour%10;
  minuteTens = (int)(minute/10);
  hourTens = (int)(hour/10);
  //minutes units
  if(munit & 1) {digitalWrite(leds[3][3], HIGH);} else {  digitalWrite(leds[3][3],LOW);}
  if(munit & 2) {digitalWrite(leds[2][3], HIGH);} else {digitalWrite(leds[2][3],LOW);}
  if(munit & 4) {digitalWrite(leds[1][3], HIGH);} else {digitalWrite(leds[1][3],LOW);}
  if(munit & 8) {digitalWrite(leds[0][3], HIGH);} else {digitalWrite(leds[0][3],LOW);}

  //minutes
  if(minuteTens & 1)  {digitalWrite(leds[3][2], HIGH);} else {digitalWrite(leds[3][2],LOW);}
  if(minuteTens & 2)  {digitalWrite(leds[2][2], HIGH);} else {digitalWrite(leds[2][2],LOW);}
  if(minuteTens & 4) {digitalWrite(leds[1][2], HIGH);} else {digitalWrite(leds[1][2],LOW);}

  //hour units
  if(hunit & 1) {digitalWrite(leds[3][1], HIGH);} else {digitalWrite(leds[3][1],LOW);}
  if(hunit & 2) {digitalWrite(leds[2][1], HIGH);} else {digitalWrite(leds[2][1],LOW);}
  if(hunit & 4) {digitalWrite(leds[1][1], HIGH);} else {digitalWrite(leds[1][1],LOW);}
  if(hunit & 8) {digitalWrite(leds[0][1], HIGH);} else {digitalWrite(leds[0][1],LOW);}

  //hour
  if(hourTens & 1)  {digitalWrite(leds[3][0], HIGH);} else {digitalWrite(leds[3][0],LOW);}
  if(hourTens & 2)  {digitalWrite(leds[2][0], HIGH);} else {digitalWrite(leds[2][0],LOW);}


}