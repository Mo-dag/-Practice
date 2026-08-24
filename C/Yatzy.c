

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand((unsigned int)time(NULL));
  int throws[5];
  int no_match = 0;
  for(int i=0;i<5;i++){      
    throws[i]=rand()%6 +1;
    printf("Dice %d: %d\n",i+1, throws[i]);
  }
  for(int j=1;j<5;j++){
    if(throws[j-1]!=throws[j]){
      no_match =1;
    }
  }
  if(no_match==0){printf("Yatzy!!!");}
  
  return 0; 
}
