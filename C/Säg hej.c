/*
Fråga 5: Säg hej! (3 p)

Uppgiften är att skapa en fil och skriva "Hej" i den.

Filen ska heta hej.txt.

Du behöver inte lägga in någon typ av felhantering.
*/


int main(){
  FILE *f = fopen("hej.txt","w");
  fputs("Hej",f);
  fclose(f);
  return 0;
}
