/*
Fråga 2: Ett fält som kö (7 p)

I ett program använder vi ett fält för att beskriva en kö av heltal.

Det betyder att vi behöver hålla reda på en serie heltal där:

- Det heltal som har varit längst i kön finns på position 0.
- Det näst äldsta värdet finns på position 1.
- Nya värden läggs sist i kön.

Kön kan variera i längd och längden hålls i en separat variabel.

Fältets storlek är 999 och kan antas alltid vara tillräckligt stor.


a) Implementera en funktion som lägger till ett värde sist i kön. (2 p)

Funktionen ska deklareras:

void queue_append(int queue[], int *l, int value);

Där:

- queue är kön.
- l är längden på kön.
- value är värdet som ska läggas till.

Funktionen ska även uppdatera l till den nya längden.


b) Förklara vad *l i deklarationen betyder. (1.5 p)

Förklara varför parametern måste vara en pekare och varför man inte bara
kan deklarera den som:

int l;


c) Implementera en funktion som plockar ut det främsta värdet i kön. (2 p)

Funktionen ska deklareras:

int queue_get_next(int queue[], int *l);

Funktionen ska:

- Returnera det första värdet i kön.
- Uppdatera kön så att resterande värden flyttas fram.
- Uppdatera längden l.


d) Skriv en main-funktion som gör följande: (1.5 p)

- Initierar en kö som innehåller värdena 1, 2 och 3.
- Lägger till värdet 9 genom att anropa queue_append().
- Läser av det främsta värdet genom att anropa queue_get_next().
- Skriver ut det returnerade värdet.
*/
void queue_append(int queue[],int *l,int vlaue);
int queue_get_next(int queue[],int *l);

int main(){
  int queue[999]={1,2,3};
  int l=0;
  l=3;
  queue_append(queue,&l,9);
  int nr = queue_get_next(queue,&l);
  printf("%d\n",nr);
  return 0;
}

void queue_append(int queue[],int *l,int value){
  queue[*l]=value;
  *l = *l +1;
  }

//l är en pekare som innehåller adressen till den ursprungliga längdvariabeln.
// *l ger tillgång till värdet på den adressen.
//Om parametern istället deklareras som int l, får funktionen bara en kopia av värdet.
// Ändringar av kopian påverkar då inte originalvariabeln.

int queue_get_next(int queue[], int *l){
int value = queue[0];
for(int i= 0;i<*l -1;i++){
queue[i]=queue[i+1];
}
*l= *l -1;
return value;
}
