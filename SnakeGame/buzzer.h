const int buzzerPin = A2;
const int buzzerDuration = 2000;
bool sound = true;

#define NOTE_FS2 93


void openSound() {
  if (sound == true) {
    tone(buzzerPin, NOTE_FS2, buzzerDuration);
  } 
  else {
    noTone(buzzerPin);
  }
}