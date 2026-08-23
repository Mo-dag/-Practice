/*
Fråga 3: Alfabetet baklänges (3 p)

Uppgiften är att skriva ett program som skriver ut det engelska alfabetet
i bakvänd ordning.

Använd små bokstäver.

Den första och sista bokstaven i det engelska alfabetet är 'a' och 'z'.

För full poäng krävs en lösning som inte innehåller någon if-sats.
*/


#include <stdio.h>

int main(){

  for(int i='z';i>='a';i--){
    putchar(i);
  }

  return 0;
}
