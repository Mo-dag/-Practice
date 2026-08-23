/*
Fråga 4: Hantera tider (9 p)

I den här uppgiften ska du påbörja ett system för att hantera klockslag,
dvs. tider som kan skrivas i formatet:

HH:MM:SS

Där:
- HH är timme, från 0 till 23
- MM är minut, från 0 till 59
- SS är sekund, från 0 till 59


a) Skapa en struktur med medlemmar som representerar antal timmar,
   minuter och sekunder i ett klockslag. (1.5 p)

Medlemmarna ska heta:

hour
minute
second

Typen ska heta:

time_t


b) Skriv en funktion som omvandlar en time_t till antal sekunder,
   räknat från 00:00:00, och returnerar detta värde. (1 p)

En timme motsvarar 3600 sekunder.
En minut motsvarar 60 sekunder.

Funktionen ska heta:

time2seconds


c) Skriv en funktion som omvandlar ett antal sekunder till time_t. (1.5 p)

Antalet sekunder ska vara funktionsparameter och en time_t ska returneras.

Funktionen ska heta:

seconds2time


d) Skriv en funktion som returnerar skillnaden i tid mellan två time_t,
   uttryckt i sekunder. (1 p)


e) Skriv en funktion som tar två time_t och returnerar medelvärdet
   av tiderna, dvs. tiden mitt emellan dem. (1.5 p)

Funktionen ska heta:

meantime


f) Skriv en funktion som skriver ut en time_t med printf
   i formatet:

HH:MM:SS

Funktionen ska heta:

print_time


g) Skriv en main-funktion som:

- anropar meantime med två olika tider
- skriver ut resultatet med hjälp av print_time

(1.5 p)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int hour;
  int minute;
  int second;
}time_t;

void print_time(time_t *time);
time_t seconds2time(int seconds);
int skillnad2times(time_t *time1, time_t *time2);
time_t meantime(time_t *time1, time_t *time2);


int main(){
  time_t time1 = {7,90,33};
  time_t time2 = {8,124,23};
  
  time_t t = meantime(&time1,&time2);

  print_time(&t);
    
  
  
  
  return 0;}



// kom ihåg : time_t *time      Använder jag ->     time->hour   (pekare, ändrar värde)
// time_t time                  Använder jag .      time.hour    (kopia, ingen ändring i själva obj)

/*
int time2seconds(time_t *time){
  int total=0;
  total = time->hour *3600;
  total = total + (time->minute * 60);
  total = total + time->second;
  return total;
}
*/

int time2seconds(time_t *time){
return time->hour*3600 + time->minute * 60 + time->second;
}


/*
int time2second(time_t time){
int total;
total = (time.hour *3600);
totla += (time.minute *60);
total += time.second;
return total;
}
*/
// mvandlar antal sekunder till time_t : : : : De menar med detta att jag skulle skapa en obj av typen time_t och returnera den.
time_t seconds2time(int seconds){
  time_t time;
  if(seconds >=3600){time.hour = seconds / 3600;seconds%=3600;}
  else{time.hour = 0;}
  if(seconds >=60){time.minute = seconds / 60;  seconds%=60;}
  else{time.minute = 00;}
  time.second = seconds;
  return time;
}

int skillnad2times(time_t *time1, time_t *time2){
  int time_1= time2seconds(time1);
  int time_2= time2seconds(time2);
  int skillnad = abs(time_1 - time_2);
  return skillnad;
}
// De vill en funk som tar två time_t obj och returnerar deras medelvärde. 
// Det betyder att de vill ha time_t datatyp tillbaka
// Jag kommer att använda second to time to wrap up the func.
time_t meantime(time_t *time1, time_t *time2){
  int sec = time2seconds(time1) + time2seconds(time2);
  return seconds2time(sec/2);
}

void print_time(time_t *time){
  printf("%.2d:%.2d:%.2d",time->hour,time->minute,time->second);
}


// Programmet kan få problem pga: time_t.
// time_t finns redan som en standardtyp i C på många system.


// Den nedre version kan kopileras : 
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int hour;
  int minute;
  int second;
}my_time_t;

void print_time(my_time_t *time);
my_time_t seconds2time(int seconds);
int skillnad2times(my_time_t *time1, my_time_t *time2);
my_time_t meantime(my_time_t *time1, my_time_t *time2);


int main(){
  my_time_t time1 = {3,90,33};
  my_time_t time2 = {4,124,23};
  
  my_time_t t = meantime(&time1,&time2);

  print_time(&t);
    
  
  
  
  return 0;}
  int time2seconds(my_time_t *time){
  return time->hour*3600 + time->minute * 60 + time->second;
  }

  my_time_t seconds2time(int seconds){
  my_time_t time;
  if(seconds >=3600){time.hour = seconds / 3600;seconds%=3600;}
  else{time.hour = 0;}
  if(seconds >=60){time.minute = seconds / 60;  seconds%=60;}
  else{time.minute = 00;}
  time.second = seconds;
  return time;
  }

  int skillnad2times(my_time_t *time1, my_time_t *time2){
  int time_1= time2seconds(time1);
  int time_2= time2seconds(time2);
  int skillnad = abs(time_1 - time_2);
  return skillnad;
  }
  my_time_t meantime(my_time_t *time1, my_time_t *time2){
  int sec = time2seconds(time1) + time2seconds(time2);
  return seconds2time(sec/2);
  }
  void print_time(my_time_t *time){
  printf("%.2d:%.2d:%.2d",time->hour,time->minute,time->second);
  }
*/
