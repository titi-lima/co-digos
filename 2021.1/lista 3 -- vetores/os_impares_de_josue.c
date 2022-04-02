#include <stdio.h>
int main () {
    int sequencia[10000];
    int count = 0;
    while(scanf("%d ", &sequencia[count]) != EOF){
    count++;
    }
    int countmaisum = (count+1), i=count, guarda, flag=0;
    for(count=0; count<i; ++count) {
        countmaisum=(count+1);
        while (countmaisum<i) {
         if (sequencia[count]>sequencia[countmaisum]) {
            guarda = sequencia[count];
            sequencia[count] = sequencia[countmaisum];
            sequencia[countmaisum] = guarda;
            ++countmaisum;
         }
         else countmaisum++;
        }
    }
    for(count=0; count<i; ++count) {
        printf("%d ", sequencia[count]);
    }
    countmaisum=1;
    count=0;
    while(countmaisum<=i && flag != 1) {
        if (((sequencia[count])^(sequencia[countmaisum])) == 0) {
            count=(count+2);
            countmaisum=(countmaisum+2);
        }
        else flag = 1;
    }
    if (flag == 1) {
        printf("\n%d\n", sequencia[count]);
    }
    else printf("\n%d\n", 0);

    return 0;
}