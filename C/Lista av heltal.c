/*
Fråga 5: Lista av heltal (9 p)

Skriv ett program där användaren skapar och analyserar en lista av heltal.
Användaren kan mata in heltal som ska lagras i listan, men kan också välja
olika funktioner enligt menyn nedan.

Exempel:

Choose an alternative:
1 Add a number to the list
2 Calculate the average of all numbers in the list
3 Find the maximum of the list
4 Exit
Your choice: 1

Enter a number: 5
The current list is [5 ]

Choose an alternative:
1 Add a number to the list
2 Calculate the average of all numbers in the list
3 Find the maximum of the list
4 Exit
Your choice: 1

Enter a number: 17
The current list is [5 17 ]

Choose an alternative:
1 Add a number to the list
2 Calculate the average of all numbers in the list
3 Find the maximum of the list
4 Exit
Your choice: 2

The average is: 11.0

Choose an alternative:
1 Add a number to the list
2 Calculate the average of all numbers in the list
3 Find the maximum of the list
4 Exit
Your choice: 4

Program exiting.

Listan sparas internt som ett fält av heltal.
Du kan anta att användaren maximalt lägger in 100 tal.
När programmet startar ska listan anses vara tom.

Uppgifter:

a) Skapa en funktion som beräknar och skriver ut
   medelvärdet av talen i listan. (2 p)

b) Lägg till en funktion som hittar och skriver ut
   det största talet i listan. (2 p)

c) Implementera programmet beskrivet ovan.
   Funktionerna från a och b ska användas.
   Övrig kod kan placeras helt i main. (5 p)

Om du vill kan följande strängvariabel definieras
på yttersta nivån av programmet:

char *alternatives =
    "Choose an alternative:\n"
    " 1 Add a number to the list\n"
    " 2 Calculate the average of all numbers in the list\n"
    " 3 Find the maximum of the list\n"
    " 4 Exit\n"
    "Your choice: ";
*/



#include <stdio.h>


char *alternatives =
    "Choose an alternative:\n"
    " 1 Add a number to the list\n"
    " 2 Calculate the average of all numbers in the list\n"
    " 3 Find the maximum of the list\n"
    " 4 Exit\n"
    "Your choice: ";


void print_list(int list[],int list_size);
void add_nr(int list[],int nr,int *list_size);
void calculate_average(int list[],int list_size);
void find_maximum(int list[],int list_size);

int main(){
  int choice=0;int nr,maximum;
  int list[100];
  double average;
  int cnt=0;
  while(1){
    printf("%s",alternatives);
    scanf("%d",&choice);
    if(choice ==1){
      printf("Your choice is: %d\n",choice);
      printf("Enter a number: \n");
      scanf("%d",&nr);
      add_nr(list,nr,&cnt);
      print_list(list,cnt);
    }
    else if(choice ==2){
      printf("Your choice is: %d\n",choice);
      calculate_average(list,cnt);
    }
    else if(choice ==3){
      printf("Your choice is: %d\n",choice);
      find_maximum(list,cnt);
    }
    else if(choice == 4){printf("Program exiting.\n");break;}
    else{printf("Wrong choice !");}
  }

    
  return 0;
}
void add_nr(int list[],int nr,int *list_size){
        list[*list_size]=nr;
        *list_size= *list_size +1;
  }

  
  void print_list(int list[],int list_size){
      printf("The current list is [");
      for(int i=0;i<list_size;i++){
        printf("%d ", list[i]);
      }
      printf("]\n");
  }
  void find_maximum(int list[],int list_size){
    int max=list[0];
    for(int i=1;i<list_size;i++){
      if(list[i]>max){max=list[i];}
    }
    printf("The maximum is %d\n",max);

  }

  void calculate_average(int list[],int list_size){
    double total=0;
    for(int i=0;i<list_size;i++){
      total+=list[i];
    }
    printf("The average is %.1f\n",total/list_size);
  }
