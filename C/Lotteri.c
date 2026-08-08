/*
Fråga 1: Lotteri (4.5 p)

Skriv ett program som simulerar ett lotteri. Lotterna har nummer mellan
100 och 999.

Programmet ska först fråga efter lottnummer, sedan dra fem slumpmässiga
vinstnummer och meddela om användaren vann eller inte.

En körning ska se ut så här (numren är endast exempel):

Ditt lottnummer: 728
Dragning 1: 345
Dragning 2: 712
Dragning 3: 196
Dragning 4: 390
Dragning 5: 201
Ledsen, du vann ej

Där 728 är input från användaren och 345 osv. är slumpade tal.
Sista raden ska se annorlunda ut vid vinst.

Det är okej om samma vinstnummer dras flera gånger.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int main(){
    srand((unsigned int)time(NULL));
    int loop=5;
    int inner_loop=0;
    int arr[5];
    while(loop>0){
        int match=0;
        int new_nr = 100 + rand()%900;

        if(inner_loop==0){arr[0]=new_nr;inner_loop++;loop--;continue;}
        for(int i=0;i<inner_loop;i++){
            if(arr[i]==new_nr){match++;}
        }
        if(match==0){arr[inner_loop]=new_nr;inner_loop++;loop--;}
    }
    printf("%d\n",arr[rand()%5]);
    int lott_nr;
    printf("Ditt lottnummer : ");
    scanf("%d",&lott_nr);

  
    bool is_win=false;
  
    for(int i=0;i<5;i++){
        printf("Dragning %d: %d\n",i+1,arr[i]);
        if(arr[i]==lott_nr){is_win=true;}
    }
    if(is_win){printf("Grattis, du vann ");}
    else{printf("Ledsen, du vann ej");}



    return 0;
}


