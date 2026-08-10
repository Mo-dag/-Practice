/*
Fråga 2: Mönster (3.5 p)

Gör en funktion som skriver ut tecken enligt detta mönster:

*****
****.
***..
**...
*....

Antalet rader ska vara en funktionsparameter.
Exemplet ovan är för fem rader.

För två rader ska resultatet vara:

**
*.
*/

#include <stdio.h>

typedef struct{
    char star;
    char point;
}paint_t;

void painter(paint_t paint, int loops);

int main(){

    paint_t paint = {'*','.'};

    printf("Nr of rounds : \n");
    int rows;
    scanf("%d",&rows);
    
    painter(paint,rows);


    return 0;
}


void painter(paint_t paint, int loops){
    int cnt=0;
    while(loops>0){
        for(int i=0;i<loops;i++){
            putchar(paint.star);
        }
        loops--;
        for(int j=0;j<cnt;j++){
            putchar(paint.point);
        }
        cnt++;
        putchar('\n');
    }
}
