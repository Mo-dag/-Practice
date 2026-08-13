/*
Fråga 4: Trafikljus (8 p)

Som en del i en simulering av trafiken i Göteborg ska du definiera en struktur
och en enumeration för att representera trafikljus i en fyrvägskorsning.

a) Definiera en enumeration som du döper till trafficlight_t via typedef med
uppräkningsvärdena RED, GREEN, YELLOW (OBS i den ordningen). (1 p)

b) Trafikljusen i den här korsningen går alltid från rött till grönt, från grönt
till gult eller från gult till rött. Gör en funktion som ändrar en variabel av
typen trafficlight_t enligt denna logik. Funktionen ska alltså ej returnera något
utan modifiera en variabel via en pekare. (2 p)

c) Trafikljusen i fyrvägskorsningen representeras med en struktur där medlemmarna
i strukturen är light1 och light2, som representerar trafikljusen för väg 1
respektive väg 2 och är av typen trafficlight_t. Definiera strukturen och döp
den till intersection_t. (1 p)

d) Gör en funktion, display_lights, som visar trafikljusen i korsningen.
Funktionen ska ta en pekare till en intersection_t som argument och skriva ut
vilken färg trafikljusen har (inget returvärde). (2 p)

Du kan använda dig av strängarna i strängfältet COLORS som kan antas vara
definierat globalt enligt:

const char *COLORS[] = {"red", "green", "yellow"};

Man kommer åt elementen i ett strängfält precis som vanliga fält, d.v.s.
strängen på index i fås enligt:

COLORS[i]

Ett exempel på utskrift vid anrop av funktionen är:

Light for road 1: green
Light for road 2: red

e) Gör en main-funktion som skapar en variabel av typen intersection_t, ger
dess medlemmar värden och anropar display_lights. För full poäng ska du göra
en initiering av variabeln, d.v.s. deklarera och sätta värden på samma gång.
(2 p)
*/
#include <stdio.h>
#include <unistd.h>   // Unix standard header !  

const char *colors[] = {"red","green","yellow"};

typedef enum{RED,GREEN,YELLOW}trafficlight_t;

typedef struct{
  trafficlight_t light1;
  trafficlight_t light2;
}intersection_t;
void change_signal(trafficlight_t *traffic);
void display_lights(intersection_t *light);

int main(){
  intersection_t light = {RED,GREEN};

  while(1){
    display_lights(&light);
    sleep(7);
    change_signal(&light.light1);
    change_signal(&light.light2);
  }
  return 0;
}

void change_signal(trafficlight_t *traffic){
  if(*traffic == RED){*traffic=GREEN;}
  else if(*traffic == GREEN){*traffic = YELLOW;}
  else{*traffic=RED;}
}
void display_lights(intersection_t *light){
  printf("Light for road 1 : %s\n",colors[light->light1]);
  printf("Light for road 2 : %s\n",colors[light->light2]);
  putchar('\n');
}
