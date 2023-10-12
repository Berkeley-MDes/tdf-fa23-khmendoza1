#include "application.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber(int minVal, int maxVal) {
  // Seed the random number generator with the current time
  //time_t current_time = time(NULL);
  //srand(current_time);

  // Generate a random number between minVal and maxVal
  int randomNum = rand() % (maxVal - minVal + 1) + minVal;

  return randomNum;
}

int speakerPin = D0;

// Notes defined in microseconds (Period/2) 
// from note C to B, Octaves 3 through 7
int notes[] = 
{0,
/* C,  C#,   D,  D#,   E,   F,  F#,   G,  G#,   A,  A#,   B */
3817,3597,3401,3205,3030,2857,2703,2551,2404,2273,2146,2024,   // 3 (1-12)
1908,1805,1701,1608,1515,1433,1351,1276,1205,1136,1073,1012,   // 4 (13-24)
 956, 903, 852, 804, 759, 716, 676, 638, 602, 568, 536, 506,   // 5 (25-37)
 478, 451, 426, 402, 379, 358, 338, 319, 301, 284, 268, 253,   // 6 (38-50)
 239, 226, 213, 201, 190, 179, 169, 159, 151, 142, 134, 127 }; // 7 (51-62)

#define NOTE_D3  3401
#define NOTE_E3  3030
#define NOTE_F3  2857
#define NOTE_A3  2273
#define NOTE_B3  2024
#define NOTE_D4  1608
#define RELEASE  20
#define BPM      100

// notes in the melody:
int tones[] = {NOTE_D3, NOTE_E3, NOTE_F3, NOTE_A3, NOTE_B3, NOTE_D4};

// note durations: 4 = quarter note, 2 = half note, etc.:
//int noteDurations[] = {4,4,4,4,4,4,4,4,4,2,4,4};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int index = generateRandomNumber(0,5);
  int ranDur = generateRandomNumber(1,8);
  int noteDuration = 60*1000/BPM/ranDur;

  tone(speakerPin, tones[index], noteDuration-RELEASE);
  Serial.println(tones[index]);
  delay(3000);

  // iterate over the notes of the melody:
  /*for (int thisNote = 0; thisNote < 12; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 60*1000/BPM/noteDurations[thisNote];
    tone(speakerPin, (tones[thisNote]!=0)?(500000/tones[thisNote]):0,noteDuration-RELEASE);
    Serial.println(tones[thisNote]);

    // blocking delay needed because tone() does not block
    delay(2000);
  }*/
}