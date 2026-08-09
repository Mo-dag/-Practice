#include <stdio.h>
#include <stdbool.h>
const int SIZE = 10; // Size of field, number of rows & columns equal.
const int N2WIN = 5; // Numbers of markers without interruption to win.

typedef struct{
    char x;
    char o;
}visualizer_t;
typedef enum{
    CROSS,
    CIRCLE,
    EMPTY
}marker_t;
bool set_position(int F[SIZE][SIZE],marker_t n,int n_rows,int n_cols);
void set_field_empty(int F[SIZE][SIZE]);
int any_winning_row(int F[SIZE][SIZE],marker_t n);
void visualize(int F[SIZE][SIZE],visualizer_t visual);
int main() {
    visualizer_t visualizer = {'X','O'};
    //FILE *f = fopen("hej.txt","w");
    //fputs("Hej",f);
    //fclose(f);
    int row;
    int column; 
    marker_t marker;
    int F[SIZE][SIZE];
    set_field_empty(F);
    printf("Welcome to Luffarschack game.\n");
    printf("Luffarschack, eller fem-i-rad, kan spelas på ett vanligt rutat papper. De två spelarna\n");
    printf("turas om att sätta ut kryss (spelare 1) eller ring (spelare 2), och den spelare som\n");
    printf("först får fem i rad (längs rad, kolumn eller diagonal) av sin symbol vinner.\n");
    
    while(1){
        while(1){
            printf("Player 1 set position (0-9) : row =\n");
            scanf("%d",&row);
            if(row <0 || row >9){continue;}
            printf("Player 1 set position (0-9) : column =\n");
            scanf("%d",&column);
            if(column <0 || column >9){continue;}

            printf("Player 1 set Marker : Cross = 0, Circle = 1 :\n");
            scanf("%d",&marker);
            if(marker <0 || marker >1){continue;}

        
            if(!set_position(F,marker,row,column)){printf("Positionen är redan upptagen !\n");}
            else{if(any_winning_row(F, marker)>-1){
                    printf("Player 1 Vann !!!\n");visualize(F,visualizer);return 0;}
                    visualize(F,visualizer);
                    break;}
        }


        
        while(1){
            printf("Player 2 set position (0-9) : row =\n");
            scanf("%d",&row);
            if(row <0 || row >9){continue;}
            printf("Player 2 set position (0-9) : column =\n");
            scanf("%d",&column);
            if(column <0 || column >9){continue;}

            printf("Player 2 set Marker : Cross = 0, Circle = 1 :\n");
            scanf("%d",&marker);
            if(marker <0 || marker >1){continue;}

        
            if(!set_position(F,marker,row,column)){printf("Positionen är redan upptagen !\n");}
            else{if(any_winning_row(F,marker)>-1){
                printf("Player 2 Vann !!!\n");visualize(F,visualizer);return 0;}
                visualize(F,visualizer);
                break;}
        }




    }


    return 0;
}



void set_field_empty(int F[SIZE][SIZE]){
    for(int r=0;r<SIZE;r++){
        for(int c=0;c<SIZE;c++){
            F[r][c]=EMPTY;
        }
    }
}

bool set_position(int F[SIZE][SIZE],marker_t n,int n_rows,int n_cols){
    if((F[n_rows][n_cols])!=EMPTY){return false;}
    F[n_rows][n_cols]=n;
    return true;
}


int any_winning_row(int F[SIZE][SIZE],marker_t n){
    int loop = SIZE;
    int r=0;
    while(loop>0){
        int cnt=0;
        for(int i=0;i<SIZE;i++){
            if(F[r][i]==n){cnt++;}
            else{cnt=0;}
            if(cnt==5){return r;}
        }
        loop--;
        r++;
    }
    return -1;
}

void visualize(int F[SIZE][SIZE],visualizer_t visual){

    for(int r=0;r<SIZE;r++){
        for(int c=0;c<SIZE;c++){
            if(F[r][c]==CROSS){
                putchar(visual.x);
            }
            else if(F[r][c]==CIRCLE){
                putchar(visual.o);
            }
            else{printf("-");}
        }
        printf("\n");
    }



}
