int octave = 1; //deklarerar en variabel för att hålla oktavvärdet


void setup() {
  for (int i = 1 ; i < 13 ; i++) { //for-loop som konfigurerar pin nr. 1 till nr. 12 som inputs
    pinMode(i, INPUT);
  }

}

void loop() {
  
  int potval = analogRead(A3); // läser av potentiometerns värde och gör d
  octave = map(potval, 0, 1023, 1, 5);
  
  for (int i = 0; i < 12 ; i++) {
    int frequency = 256 * pow(2, (i / 12.0)) / 2 * octave;
    if (digitalRead(i)) {
      tone(13, frequency);
    }
  }
}
