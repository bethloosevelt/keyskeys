void setupPins() {

  for(int i=1; i<=13; i++) {
     pinMode(i, INPUT);
  }
}

double notes[] = {261.6, 293.7, 329.6 , 349.2  , 392.0, 440.0, 493.9, 523.3, 587.3, 659.3, 698.5, 784.0};

void setup() {
  setupPins();
  pinMode(26, OUTPUT);

}

int whichPin() {
  for(int i=1; i<=13; i++) {
    if(digitalRead(i) == 1) {
      return i;
    }
  }
  return -1;
}

void loop() {
  int noteNum = whichPin();
  if(noteNum != -1)
    tone(26, notes[noteNum - 1], 2);
  else
    noTone(26);
}
