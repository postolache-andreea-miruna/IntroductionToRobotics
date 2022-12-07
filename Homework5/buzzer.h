const int buzzerPin = A2;
const int buzzerDuration = 2000;
const int scrollDuration = 100;
bool sound = true;
#define NOTE_FS2 93
#define NOTE_C8 4186
void openSound() {
  if (sound == true) {
    tone(buzzerPin, NOTE_FS2, buzzerDuration);
  } 
  else {
    noTone(buzzerPin);
  }
}

void scroll() {
  if (sound == true) {
    tone(buzzerPin, NOTE_C8, scrollDuration);
  } 
  else {
    noTone(buzzerPin);
  }
}