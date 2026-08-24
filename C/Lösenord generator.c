/*
Fråga 3: Lösenord (4.5 p)

Gör ett program som genererar ett lösenord som består av 9 bokstäver
från det engelska alfabetet (a till z, ej å, ä, ö).

Varje bokstav ska slumpvis vara liten eller stor. Sannolikheten för
liten eller stor bokstav ska vara 50 % vardera.

Programmet ska skriva ut lösenordet i terminalen, till exempel:

Random password: XLklaFpjv

Antalet bokstäver i det engelska alfabetet är 26, men för full poäng
krävs det att programmet själv räknar ut hur många bokstäver det finns
från a till z. Siffran 26 ska alltså inte vara hårdkodad i programmet.
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
int main(){
  int letter;
  int n_letter = 'z'-'a'+1; //122-97 = 25 
  srand((unsigned int)time(NULL));
  printf("Random pass : \n");
  for(int i=0;i<9;i++){
    letter = rand()%n_letter;
    if(rand()%2){
      putchar(letter+'a');
    }
    else{putchar(letter+'A');}
  }
  putchar('\n');
  return 0;
}
*/

// Newer ver:
int main(){

  srand((unsigned int)time(NULL));
  int cnt=0;
  while(cnt<9){
    int alpha = rand()% ('z'-'a' +1); // Om jag sätta +1 utanför parantes, kommer jag att få från 0 till 25 + 1 >> kommer missa a/A.
    if(rand()%2){
      putchar(alpha +'a');
    }
    else{putchar(alpha+'A');}

    cnt++;
  }
  return 0;

}
