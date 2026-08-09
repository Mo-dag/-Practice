/*
Fråga 4: Binär sökning (4 p)

Uppgiften här är att implementera en algoritm för binär sökning,
som letar efter ett värde i ett sorterat fält.

"Pseudokod" för en lätt optimerad version av binär sökning är
(från Wikipedia, lätt modifierad):

procedure binary_search(arr: sorted array, n: size of A, t: target)
    l := 0
    r := n - 1

    repeat
        m := floor((l + r) / 2)

        if arr[m] < t then
            l := m + 1

        else if arr[m] > t then
            r := m - 1

        else:
            return m

    until l > r

    return -1
end procedure

Notera att ovanstående inte är C-kod, utan ett försök att beskriva
algoritmen på ett lättfattligt och generellt sätt.

a) I pseudokoden hänvisas till funktionen floor för avrundning nedåt
   till närmaste heltal. I C behövs inte en sådan funktion i detta fall.
   Varför? (1 p)

b) Implementera binär sökning som en funktion i C, så att följande
   kod fungerar: (3 p)

int main() {
    int a, b;
    int f[] = {1, 3, 5, 8, 9, 13, 14, 19, 22};
    const int n = sizeof(f) / sizeof(f[0]);

    a = binary_search(f, n, 5);
    printf("%d\n", a); // This shall print 2

    b = binary_search(f, n, 6);
    printf("%d\n", b); // This shall print -1

    return 0;
}
*/

#include <stdio.h>


int binary_search(int arr[],int size,int target);



int main() {
    int a, b;
    int f[] = {1, 3, 5, 8, 9, 13, 14, 19, 22};
    const int n = sizeof(f) / sizeof(f[0]);
    a = binary_search(f, n, 5);
    printf("%d\n", a); // This shall print 2
    b = binary_search(f, n, 6);
    printf("%d\n", b); // This shall print -1
    return(0);
}


int binary_search(int arr[],int size,int target){
    int l=0;
    int r=size-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]<target){
            l=m+1;
        }
        else if(arr[m]>target){
            r=m-1;
        }
        else{return m;}
    }
    return -1;
}

