

int noteOn = 144;
int piezo = A0;
int threshold = 50;//anything over fifty means we've hit the piezo

void setup(){
  Serial.begin(9600);
}

void loop(){
  int piezoVal = analogRead(piezo);
  if (piezoVal>threshold){
    MIDImessage(noteOn, 60, 127);
    delay(300);
    MIDImessage(noteOn, 60, 0);
  }
}

//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
