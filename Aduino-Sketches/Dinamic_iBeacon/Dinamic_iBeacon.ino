/*
 *  Copyright (C) 2018 - Handiko Gesang - www.github.com/handiko
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <SoftwareSerial.h>

#define SET     true
#define CLEAR   false

SoftwareSerial BT(8,9);

void BT_flush(SoftwareSerial &ser, int interval);
void BT_sendcmd(SoftwareSerial &ser, String s);
void BT_readback(SoftwareSerial &ser);

void BT_initBT(SoftwareSerial &ser);

void BT_renew(SoftwareSerial &ser);
void BT_reset(SoftwareSerial &ser);
void BT_setname(SoftwareSerial &ser, String s);
void BT_setmaj(SoftwareSerial &ser, int n);
void BT_setmin(SoftwareSerial &ser, int n);
void BT_setibe0(SoftwareSerial &ser, String s);
void BT_setibe1(SoftwareSerial &ser, String s);
void BT_setibe2(SoftwareSerial &ser, String s);
void BT_setibe3(SoftwareSerial &ser, String s);
void BT_setIBeaUUID(SoftwareSerial &ser, String s0, String s1, String s2, String s3);
void BT_setadvIBea(SoftwareSerial &ser);
void BT_setadvint(SoftwareSerial &ser, int n);
void BT_setpower(SoftwareSerial &ser, int n);
void BT_setpwrm(SoftwareSerial &ser, bool c);
void BT_setIBea(SoftwareSerial &ser, bool c);

void BT_randomizeparam(SoftwareSerial &ser);

unsigned long ms=0;

void BT_flush(SoftwareSerial &ser, int interval)
{
  BT_readback(ser);
  BT_readback(ser);
  delay(interval);
  BT_readback(ser);
}

void BT_sendcmd(SoftwareSerial &ser, String s)
{
  Serial.print("\r\n> sending command :");
  Serial.println(s);
  ser.print(s);
}

void BT_readback(SoftwareSerial &ser)
{
  char s;
  while(ser.available() > 0)
  {
    s = ser.read();
    Serial.print(s);
  }
}

void BT_initBT(SoftwareSerial &ser)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT \r\n");
  ser.print("AT");

  BT_flush(BT, 100);
}

void BT_reset(SoftwareSerial &ser)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+RESET \r\n");
  ser.print("AT+RESET");
  
  BT_flush(BT, 1000);
}

void BT_setname(SoftwareSerial &ser, String s)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+NAME");
  Serial.println(s);
  ser.print("AT+NAME");
  ser.print(s);
  
  BT_flush(BT, 100);
}

void BT_setmaj(SoftwareSerial &ser, int n)
{
  char s[16];

  sprintf(s,"0x%04X",n);
  
  Serial.flush();
  Serial.print("\r\n> sending command : AT+MARJ");
  Serial.println(s);
  ser.print("AT+MARJ");
  ser.print(s);
  
  BT_flush(BT, 100);
}

void BT_setmin(SoftwareSerial &ser, int n)
{
  char s[16];

  sprintf(s,"0x%04X",n);
  
  Serial.flush();
  Serial.print("\r\n> sending command : AT+MINO");
  Serial.println(s);
  ser.print("AT+MINO");
  ser.print(s);
  
  BT_flush(BT, 500);
}

void BT_setibe0(SoftwareSerial &ser, String s)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+IBE0");
  Serial.println(s);
  ser.print("AT+IBE0");
  ser.print(s);
  
  BT_flush(BT, 100);
}

void BT_setibe1(SoftwareSerial &ser, String s)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+IBE1");
  Serial.println(s);
  ser.print("AT+IBE1");
  ser.print(s);
  
  BT_flush(BT, 100);
}

void BT_setibe2(SoftwareSerial &ser, String s)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+IBE2");
  Serial.println(s);
  ser.print("AT+IBE2");
  ser.print(s);
  
  BT_flush(BT, 100);
}

void BT_setibe3(SoftwareSerial &ser, String s)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+IBE3");
  Serial.println(s);
  ser.print("AT+IBE3");
  ser.print(s);
  
  BT_flush(BT, 100);
}

void BT_setIBeaUUID(SoftwareSerial &ser, String s0, String s1, String s2, String s3)
{
  BT_setibe0(BT, s0);
  BT_setibe1(BT, s1);
  BT_setibe2(BT, s2);
  BT_setibe3(BT, s3);
}

void BT_setadvIBea(SoftwareSerial &ser)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+ADTY");
  Serial.println(3);
  ser.print("AT+ADTY");
  ser.print(3);
  
  BT_flush(BT, 100);
}

void BT_setadvint(SoftwareSerial &ser, int n)
{
  if(n > 9)
    n = 9;

  else if(n < 0)
    n = 0;
    
  Serial.flush();
  Serial.print("\r\n> sending command : AT+ADVI");
  Serial.println(n);
  ser.print("AT+ADVI");
  ser.print(n);
  
  BT_flush(BT, 100);
}

void BT_setpower(SoftwareSerial &ser, int n)
{
  if(n > 3)
    n = 3;

  else if(n < 0)
    n = 0;

  Serial.flush();
  Serial.print("\r\n> sending command : AT+POWE");
  Serial.println(n);
  ser.print("AT+POWE");
  ser.print(n);
  
  BT_flush(BT, 100);
}

void BT_setpwrm(SoftwareSerial &ser, bool c)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+PWRM");
  Serial.println(c);
  ser.print("AT+PWRM");
  ser.print(c);
  
  BT_flush(BT, 100);
}

void BT_setIBea(SoftwareSerial &ser, bool c)
{
  Serial.flush();
  Serial.print("\r\n> sending command : AT+IBEA");
  Serial.println(c);
  ser.print("AT+IBEA");
  ser.print(c);
  
  BT_flush(BT, 100);
}

void BT_randomizeparam(SoftwareSerial &ser)
{
  char uuid[4][9];

  sprintf(uuid[0],"%04lX%04lX",random(0xffff),random(0xfffe));
  sprintf(uuid[1],"%04lX%04lX",random(0xffff),random(0xfffe));
  sprintf(uuid[2],"%04lX%04lX",random(0xffff),random(0xfffe));
  sprintf(uuid[3],"%04lX%04lX",random(0xffff),random(0xfffe));
  
  Serial.println("\r\n");
  Serial.println("\r\n.................. Randomizing parameters .................. \r\n");
  
  BT_initBT(ser);

  BT_setmaj(ser, random(0xfffe));
  BT_setmin(ser, random(0xfffe));
  BT_setIBeaUUID(ser, uuid[0], uuid[1], uuid[2], uuid[3]);
  BT_setadvint(BT, random(9));
  BT_setIBea(ser, true);         
  BT_reset(ser);

  Serial.println("\r\n");
  Serial.println("\r\n.......................... Stanby .......................... \r\n");
}
 
void setup() 
{
  Serial.begin(115200);
  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println(" ");
  
  BT.begin(9600);
  Serial.print("BTserial started at ");
  Serial.println(9600);

  Serial.println("\r\n");
  Serial.println("\r\n.................. Initializing parameters .................. \r\n");

  BT.print("AT");
  
  BT_initBT(BT);
  BT_reset(BT);
  
  BT_initBT(BT);
  BT_setname(BT, "handiko");
  BT_setmaj(BT, 0xFFF0);
  BT_setmin(BT, 0XFFE1);
  BT_setIBeaUUID (BT,
                  "74278BDA",
                  "B6444520",
                  "8F0C720E",
                  "AF059935");
  BT_setadvIBea(BT);
  BT_setadvint(BT, 5);
  BT_setpower(BT, 2);
  BT_setpwrm(BT, true);
  BT_setIBea(BT, true);         
  BT_reset(BT);

  ms = millis();

  Serial.println("\r\n");
  Serial.println("\r\n.......................... Stanby .......................... \r\n");

  randomSeed(analogRead(0));
}
 
void loop()
{
  BT_readback(BT);

  if((millis() - ms) > 10000)
  {
    BT_randomizeparam(BT);
    ms = millis();
  }
  else if((millis() - ms) < 0)
  {
    ms = millis();
  }
}
