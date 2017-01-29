int Sym1 = 1;

#include "pitches.h"

int bpm = 120;

typedef struct {
  int f;
  float l;
} NoteStruct;

#include "auclairdelalune.h"
#include "frerejacques.h"
#include "Gengenliebe.h"
#include "partition2A.h"
#include "partition2B.h"
    
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  Serial.begin (9600);
}

void play(NoteStruct notes[]){
  NoteStruct *p = notes;
  while (p->f != -1) {
    float lon = p->l * 60.0 / bpm * 1000;
    Serial.println (p->f);
    tone(8, p->f, lon-15);
    delay(lon);
    p++;
  }
}

NoteStruct *toPlay = notes_1;

void loop() {
  if (digitalRead(3) == LOW){
    Sym1 = notes_4;
  }
  else if (digitalRead(4) == LOW){
    Sym1 = notes_5;
  }
  if (digitalRead(2) == LOW) {
    play (toPlay);
    delay(1000);
    if (toPlay == notes_1){
      toPlay = notes_2;
    }
    else {
      if (toPlay == notes_2){
      toPlay = notes_3;
      }
      else{
        if (toPlay == notes_3){
        toPlay = Sym1;
        }
        else{
        toPlay = notes_1;
        }
      }
    }
  }
}
