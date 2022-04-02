#include <stdio.h>

int main() {
    int q, cont=0, flag=0, j=0, k, m, fl=0;
    scanf("%d", &q);
    int vet[q][q], mod[q];
    for(k=0; k<q; ++k) {
        for(m=0; m<q; ++m) {
            scanf("%d", &vet[k][m]);
            if(vet[k][m] != 0 && fl==0) {
                if(vet[k][m] == 1) {
                    mod[j] = m;
                    ++j;
                    fl=1;
                }
                else {
                    flag=1;
                }
            }
            else if(vet[k][m] != 0 && fl==1) {
                flag=1;
            }
            ++cont;
        }
        fl=0;
    }
    for(k=0; k<q; ++k) { // ver se algum eh igual, indicando q ta na mesma coluna
        for(m=k+1; m<q; ++m) {
            if(mod[k] == mod[m]) {
                flag = 1;
            }
        }
    }
    if(j!=q) {
        flag=1;
    }
    for(k=0; k<q; ++k) {
        for(m=0; m<q; ++m) {
            printf("%d ", vet[k][m]);
        }
        printf("\n");
    }
    if (flag==0) {
        printf("True\n");
    }
    else printf("False\n");

    return 0;
}