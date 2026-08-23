/*
Fråga 1: Ränta på ränta (6 p)

Skriv ett program som beräknar och skriver ut framtida värde på pengar
insatta på ett konto.

Programmet ska fråga efter:
- Insatt belopp
- Antagen ränta i procent

Om räntan är 5 %, ökar beloppet på kontot med en faktor 1.05 varje år.
Det innebär att beloppet multipliceras med 1.05 i slutet av varje år.

a) Gör en version som skriver ut värdet för år 1 till 10. (4 p)

Exempel med en insättning på 100 kr och 3 % ränta:

Amount: 100
Interest [%]: 3
Year  1: 103.00
Year  2: 106.09
Year  3: 109.27
Year  4: 112.55
Year  5: 115.93
Year  6: 119.41
Year  7: 122.99
Year  8: 126.68
Year  9: 130.48
Year 10: 134.39

För att skriva ut tecknet % med printf används %%.
Beloppet ska skrivas ut med två decimaler.
Årtalen ska formateras så att ':' hamnar i samma kolumn på alla rader,
utan att använda if för formateringen.

b) Ange vad som behöver ändras för att även inkludera år 20, 30, 40 och 50. (2 p)

Du behöver inte skriva om hela programmet.
Det räcker att ange vilka ändringar som behövs.

Lösningar som uttryckligen innehåller talen 20, 30 och 40 ger avdrag.
Lösningen ska alltså vara generell och enkel att utöka till exempelvis
år 60, 70 och så vidare.

För samma belopp och ränta som ovan ska utskriften bli:

Amount: 100
Interest [%]: 3
Year  1: 103.00
Year  2: 106.09
Year  3: 109.27
Year  4: 112.55
Year  5: 115.93
Year  6: 119.41
Year  7: 122.99
Year  8: 126.68
Year  9: 130.48
Year 10: 134.39
Year 20: 180.61
Year 30: 242.73
Year 40: 326.20
Year 50: 438.39
*/


#include <stdio.h>

int main(){


    double amount;
    double interest;

    printf("Amount: \n");
    scanf("%lf",&amount);
    printf("Interest [%%]: \n");
    scanf("%lf",&interest);
    int i=0;
    
    for(;i<10;i++){
        printf("Year %d: ",i+1);
        amount = amount * ((interest/100)+1);
        printf("%.2f\n",amount);
    }
    
    for(;i<50;i++){
        amount = amount *((interest/100)+1);
        if((i+1)%10 == 0){
            printf("Year %d: ", i+1);
            printf("%.2f\n",amount);
        }
    }
    

    



    return 0;
}
