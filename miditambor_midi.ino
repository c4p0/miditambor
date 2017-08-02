#include "MIDIUSB.h"

int piezo = A0;           // Pin de entrada de piezoeléctrico
int threshold = 50;       // Umbral de piezoeléctrico

const int buttonPin = 2;  // Pin de entrada de botón
int buttonState = 0;      // Estado del botón

int note = 144;           // Nota a enviar
int onTime = 200;         // Tiempo en milisegundos hasta enviar el noteOff
uint8_t intensity = 64;   // Intensidad de nota
signed char channel = 0;  // Canal de envío MIDI

/*
 *      SETUP
 */
void setup(){
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
}

/*
 *      LOOP
 */
void loop(){
  sensePiezo();
}

// Sensamos piezo. Si supera umbral, enviamos la nota
void sensePiezo(){
  int piezoVal = analogRead(piezo);
  if (piezoVal > threshold){
    playNote();
  }
}

// Envía el noteOn y checkea estado del botón
void playNote(){
  noteOn(channel, note, intensity);
  MidiUSB.flush();
  checkButton();
}

// Si el botón está en alto, se llama recursivamente, sino envía noteOff
void checkButton(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    delay(onTime);
    checkButton();
  } else {
    delay(onTime);
    noteOff(channel, note, 0);
    MidiUSB.flush();
  }
}

// Envío de señal midi noteOn
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

// Envío de señal midi noteOff
void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
