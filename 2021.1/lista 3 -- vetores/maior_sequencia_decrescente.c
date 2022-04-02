#include <stdio.h>
int main() {
    int qcasos;
    scanf("%d", &qcasos);
    int casos[qcasos], i=qcasos, qnumeros, frequencia2 = 1, frequencia1 = 1, flag = 0;
    for(qcasos=0; qcasos<i; ++qcasos) {
        scanf("%d", &qnumeros);
        int sequencia[qnumeros], k=qnumeros, tamanho=0, maiorsequencia[frequencia2];
        for(qnumeros=0; qnumeros<k; ++qnumeros) {
            scanf("%d", &sequencia[qnumeros]);
        }
        int qnumerosmaisum = (qnumeros+1);
        qnumeros=0;
        qnumerosmaisum=1;
        while(qnumerosmaisum<k) {
            while(sequencia[qnumeros]-sequencia[qnumerosmaisum]>0 && qnumerosmaisum<k) {
                ++frequencia2;
                ++qnumerosmaisum;
                ++qnumeros;
                flag = 1;
            }
            if (frequencia2>frequencia1) {
                    frequencia1=frequencia2;
                    for(frequencia2=0; frequencia2<frequencia1; ++frequencia2) {
                        maiorsequencia[frequencia2] = sequencia[qnumeros-(frequencia1-1)];
                        ++qnumeros;
                    }
                    qnumeros=(qnumeros-frequencia2+1);
                    qnumerosmaisum = (qnumeros+1);
            }
            else {
                ++qnumeros;
                ++qnumerosmaisum;
            }
        }
        if (flag==1) {
            printf("\n%d\n", frequencia2);
            frequencia1=frequencia2;
            for(frequencia2=0; frequencia2<frequencia1; ++frequencia2) {
                printf("%d ", maiorsequencia[frequencia2]);
            }
        }
        else {
            printf("%d\n", 0);
        }
        frequencia2 = 1;
        frequencia1 = 1;
        flag = 0;
    }

    return 0;
}