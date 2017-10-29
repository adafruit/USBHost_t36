// Simple test of USB Host
//
// This example is in the public domain

#include "USBHost_t36.h"

USBHost myusb;
GenericUSB usbdev(myusb);

void setup()
{
	while (!Serial) ; // wait for Arduino Serial Monitor
	Serial.println("USB Host Testing");
	myusb.begin();
}


void loop()
{
	myusb.Task();
 //Serial.print('.');
 if (usbdev.device) {
  Serial.println(usbdev.device->idVendor, HEX);
  Serial.println(usbdev.device->idProduct, HEX);
  delay(100);
 }
}


void OnPress(int key)
{
	Serial.print("key '");
	Serial.print((char)key);
	Serial.print("'  ");
	Serial.println(key);
	//Serial.print("key ");
	//Serial.print((char)keyboard1.getKey());
	//Serial.print("  ");
	//Serial.print((char)keyboard2.getKey());
	//Serial.println();
}

void OnNoteOn(byte channel, byte note, byte velocity)
{
	Serial.print("Note On, ch=");
	Serial.print(channel);
	Serial.print(", note=");
	Serial.print(note);
	Serial.print(", velocity=");
	Serial.print(velocity);
	Serial.println();
}

void OnNoteOff(byte channel, byte note, byte velocity)
{
	Serial.print("Note Off, ch=");
	Serial.print(channel);
	Serial.print(", note=");
	Serial.print(note);
	//Serial.print(", velocity=");
	//Serial.print(velocity);
	Serial.println();
}

void OnControlChange(byte channel, byte control, byte value)
{
	Serial.print("Control Change, ch=");
	Serial.print(channel);
	Serial.print(", control=");
	Serial.print(control);
	Serial.print(", value=");
	Serial.print(value);
	Serial.println();
}

