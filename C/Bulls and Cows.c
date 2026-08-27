/*
Fråga 5: "Bulls and Cows" med fält (6 p)

I denna uppgift ska du göra några funktioner för spelet Bulls and Cows.
Reglerna för spelet är precis som i inlämningsuppgiften:

- Endast siffrorna 1 till 9 är tillåtna.
- En siffra får bara förekomma en gång i det hemliga talet.
- En "bull" betyder en rätt siffra på rätt plats i gissningen.
- En "cow" betyder en rätt siffra men på fel plats i gissningen.

Till skillnad från inlämningsuppgiften används här fält av heltal,
och spelet är designat för att kunna hantera tal med annan längd än fyra.

Variabeln för det hemliga talet är deklarerad så här:

int secret[ndigits];

där ndigits är antalet siffror som talet innehåller.

a) Skriv en funktion som avgör hur många "bulls" en gissning innehåller. (1.5 p)

b) Skriv en funktion som avgör hur många "bulls" eller "cows"
   en gissning innehåller. (2 p)

c) Skriv en funktion som kontrollerar om ett fält innehåller en korrekt
   kombination av heltal för Bulls and Cows, enligt de två första
   punkterna ovan. (2.5 p)
*/
#include <stdbool.h>

int bulls_nr(int secret_word[],int guessed_word[],int ndigits){
int bulls=0;

for(int i=0;i<ndigits;i++){
if(secret_word[i]==guessed_word[i]){bulls++;}
}
return bulls;
}

void nr_bulls_cows(int secret_w[], int guessed_w[], int ndigits) {
    int bulls = bulls_nr(secret_w, guessed_w, ndigits);
    int cows = 0;

    for (int i = 0; i < ndigits; i++) {
        for (int j = 0; j < ndigits; j++) {
            if (i == j) {
                continue;
            }

            if (secret_w[i] == guessed_w[j]) {
                cows++;
            }
        }
    }

    printf("Number of cows: %d, Number of bulls: %d", cows, bulls);
}


bool is_ligit(int guessing[], int ndigits) {
    for (int i = 0; i < ndigits; i++) {

        if (guessing[i] <= 0 || guessing[i] > 9) {
            return false;
        }

        for (int j = 0; j < ndigits; j++) {
            if (i == j) {
                continue;
            }

            if (guessing[i] == guessing[j]) {
                return false;
            }
        }
    }

    return true;
}
