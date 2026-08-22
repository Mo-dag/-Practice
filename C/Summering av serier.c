/*
Fråaga 3: Summering av serier (6 p)
a Skriv en funktion series1 som beräknar summan:
1
1 + 1
2 + 1
3 + 1
4 + . . .
Funktionen ska räakna med double och ha en parameter limit. Det är absol-
utbeloppet av den senast tillagda termen som ska jämföras med limit, för att
avgöra när summeringen ska avbrytas. (3 p)
b Skriv en funktion series2 som fungerar som ovan men beräknar summan:
1
1 − 1
2 + 1
3 − 1
4 + . . .
Obs, det är absolutbeloppet av tillagda termer som här ska jämföras med
limit. (3 p)
*/
#include <math.h> //för absolut belopp. f innan abs för double.
double series1(double limit){
  double x=1;
  double sum=0;
  double term =1; //Jag vill börja med 1 för att jämföra med limit. 
  while(fabs(term)>=limit){
    term = 1/x;
    x++;
    sum += term;
  }
  return sum;
}

double series2(double limit){
  double x=1;
  double sum=0;
  double term=1;
  while(fabs(term)>=limit){
    term = 1/x;
    if(x>0){x++;}
    else{x--;}
    x*=-1;
    sum+=term;
  }
  return sum;
}
