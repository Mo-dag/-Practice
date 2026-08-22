/*
**Fråga 4: Skriv ut fil (6 p)**

Skriv en funktion som visar innehållet i en fil på skärmen.

Funktionen får filnamnet som en sträng och deklareras så här:

```c
void file2screen(char filename[]);
```

Funktionen ska:

* öppna filen för läsning
* läsa texten i filen
* skriva ut innehållet på skärmen
* stänga filen när allt är klart
* skriva ut ett kort felmeddelande om filen inte kunde öppnas

*/

void file2screen(char filename[]){

// Först skulle jag skapa filen, data typ : FILE. Den kommer vara en pekare.
  // - - öppna filen för läsning
  FILE *f = fopen(filename,"r");
  //- - Skriva ut ett kort felmeddelande om filen inte kunde öppnas
  if(f==NULL){printf("Error 404");return;}
  //- - skriva ut innehållet på skärmen
// FÖr att skriva ut innehållet kommer jag att skapa c variable som kommer att ta
// emot värdet från funktion fgetc. Den funktionen kommer läsa av en char i taget.
// Jag kommer att använda data typen int för att i End Of File kan jag få EOF som -1.
//OBS : Om c vore char kan EOF redan ha blivit felaktigt omvandlat när värdet sparades.
  int c;
  while((c=fgetc(f))!=EOF){
    putchar(c);
  }
  //- - stänga filen när allt är klart
  fclose(f);
}
