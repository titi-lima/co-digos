//scanear, ordenar. depois, analisar em um loop countas vezes o primeiro elemento vai ser igual a nmaisum (se vdd, ++nmaisum). ao fim disso, printf o elemento e sua frequencia. para voltar ao loop para o proximo caracter, diga que elemento = elemento+frequencia(+1?) e nmaisum = elemento+1.
#include <stdio.h>
int main () {
    char text[1000];
    int count = 0; 
    while(scanf("%c", &text[count]) != EOF){
        count++;
    }
    int i = count, guarda, countmaisum = (count+1), frequencia = 1, flag = 0;
    for(count=0; count<i; ++count) {
        scanf("%c", &text[count]);
    }
    for(count=0; count<i; ++count) {
        countmaisum=(count+1);
        while (countmaisum<i) {
            if (text[count]<text[countmaisum]) {
            guarda = text[count];
            text[count] = text[countmaisum];
            text[countmaisum] = guarda;
            ++countmaisum;
            }
            else countmaisum++;
        }
    }
    for(count=0; count<i; ++count) {
        countmaisum = (count+1);
        if (text[count] == text[countmaisum]) {
            ++frequencia;
            flag = 1;
            continue;
        }
        else {
            flag = 0;
            printf("%c %d\n", text[count], frequencia);
            frequencia = 1;
        }
    }
    if (flag==1){
        printf("%c %d\n", text[count], frequencia);
    }
    return 0;
}