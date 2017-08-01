int piezo = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int piezoVal = analogRead(piezo);
  Serial.println(piezoVal);
}

