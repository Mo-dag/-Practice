/*
Fråga 5: Palindromtal (8 p)

Datumet för denna tentamen är ett palindromdatum: 828, dvs. talet 828 läses
likadant från båda hållen. Andra exempel på palindromtal är 9 och 1331.
Notera att du kan göra del b) och c) utan att ha löst a).

a) Skapa funktionen bool check_palindrome(int num), vars uppgift är att testa
   om num är ett palindromtal eller ej. Du får inte använda strängar eller fält
   i din lösning. (3 p)

b) Skriv ett program som läser in ett heltal och använder sig av funktionen
   check_palindrome från a). Bara positiva heltal med maximalt 6 siffror ska
   accepteras. Alla utskrifter ska ske i main. (3 p)

   Några exempel på utskriften av programmet:

   Ange ett positivt heltal (max 6 siffror): 828
   828 är ett palindromtal.

   eller

   Ange ett positivt heltal (max 6 siffror): 123
   123 är inte ett palindromtal.

   eller

   Ange ett positivt heltal (max 6 siffror): -1
   Felaktig inmatning, försök igen.
   Ange ett positivt heltal (max 6 siffror): 1234567
   Felaktig inmatning, försök igen.
   Ange ett positivt heltal (max 6 siffror): 41296
   41296 är inte ett palindromtal.

c) Skapa funktionen int next_palindrome(int num) som hittar det minsta
   palindromtalet som är större än eller lika med num. Återigen får du inte
   använda strängar eller fält. (2 p)
*/

#include <stdio.h>
#include <stdbool.h>

bool check_palindrome(int num);

int next_palindrome(int num);

int main(){

    
    int n=-1;

    while(n<0){
        printf("Ange ett positiv heltal (Max 6 siffror): ");
        scanf("%d",&n);
        if(n<0 || n >999999){n=-1;printf("Felaktig inmatning, försök igen.\n");continue;}
        if(check_palindrome(n)){
            printf("%d är ett palindrome\n",n);
        }
        else{printf("%d är inte ett palindrome\n",n);}
    }

    int next_n = next_palindrome(n);
    printf("The next palindrome is : %d\n",next_n);
    
    
    return 0;
}

bool check_palindrome(int num){
    int copy = num;
    int reversed=0;
    while(copy>0){
        reversed *=10;
        reversed += copy%10;
        copy/=10;
    }
    if(num != reversed){return false;}
    return true;
}



int next_palindrome(int num){
    int next_n = num;

    while(1){
        if(check_palindrome(next_n)){break;}
        next_n++;
    }
    return next_n;
}
