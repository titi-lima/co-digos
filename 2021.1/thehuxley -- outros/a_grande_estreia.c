#include <stdio.h>
//int errada. fazer um comparador de diferencas
// soma os numeros dos dois arrays. o que for maior vai definitivamente terminar ou comecar. compara o inicio e o fim dos dois arrays (ate achar 0 no array "menor") e ve qual deles vale mais a pena. nao existe a possibilidade do array menor ter um pedaco do "meio", ja que so pode atravessar uma vez.
//outra possibilidade: olhar o ponto maximo de diferenca na metade inicial e na metade final

int main() {
    int n, k, cont=0, flag=0, saux1=0, saux2=0, dif1=0, dif2=0, sum1=0, sum2=0, pdif1, pdif2;
    scanf("%d", &n);
    int vet[n], vet2[n];
    for(k=0; k<n; ++k) {
        scanf(" %d", &vet[k]);
        sum1+=vet[k];
        /*if(vet[k] == 0) {
            flag=1;
        }*/
    }
    /*if(flag==0) {
        printf("0\n");
        return 0;
    }
    flag=0;
    */
    for(k=0; k<n; ++k) {
        scanf(" %d", &vet2[k]);
        sum2+=vet2[k];
    }
    if(sum1>sum2) {
        for(k=0; k<n; ++k) { // calcula a soma indo da esquerda para a direita e pega a diferenca maxima do menor para o maior. possivelmente fazivel no segundo for do scan
            if(vet[k] == 1) {
                ++saux1;
            }
            if(vet2[k] == 1) {
                ++saux2;
            }
            if(saux1-saux2>dif1) {
                dif1=saux1-saux2;
                pdif1=k;
            }
        }
        saux1=0;
        saux2=0;
        for(k=n-1; k>-1; --k) { // calcula a soma da direita para a esquerda e pega a diferenca maxima do menor para o maior.
            if(vet[k] == 1) {
                ++saux1;
            }
            if(vet2[k] == 1) {
                ++saux2;
            }
            if(saux1-saux2>dif2) {
                dif2=saux1-saux2;
                pdif2=k;
            }
        }
        //printf("%d, %d\n%d, %d\n", dif1, pdif1, dif2, pdif2);
        if(dif1>dif2 && dif1>1) {
            for(k=0; k<n; ++k) {
                if(pdif1>=k) {
                    cont += vet[k];
                }
                else cont += vet2[k];
            }
        }
        else if(dif2>=dif1 && dif2>1) {
            //printf("t\n");
            for(k=n-1; k>-1; --k) {
                if(pdif2<=k) {
                    cont += vet[k];
                }
                else cont += vet2[k];
            }
        }
        else {
            for(k=n-1; k>-1; --k) {
                cont += vet[k];
            }
            flag=1;
        }
    }
    else {
        for(k=0; k<n; ++k) { // calcula a soma indo da esquerda para a direita e pega a diferenca maxima do menor para o maior. possivelmente fazivel no segundo for do scan
            if(vet[k] == 1) {
                ++saux1;
            }
            if(vet2[k] == 1) {
                ++saux2;
            }
            if(saux1-saux2>dif1) {
                dif1=saux1-saux2;
                pdif1=k;
            }
        }
        saux1=0;
        saux2=0;
        for(k=n-1; k>-1; --k) { // calcula a soma da direita para a esquerda e pega a diferenca maxima do menor para o maior.
            if(vet[k] == 1) {
                ++saux1;
            }
            if(vet2[k] == 1) {
                ++saux2;
            }
            if(saux1-saux2>dif2) {
                dif2=saux1-saux2;
                pdif2=k;
            }
        }
        if(dif1>dif2 && dif1>1) {
            for(k=0; k<n; ++k) {
                if(pdif1>=k) {
                    cont += vet[k];
                }
                else cont += vet2[k];
            }
        }
        else if(dif2>=dif1 && dif2>1) {
            for(k=n-1; k>-1; --k) {
                if(pdif2<=k) {
                    cont += vet[k];
                }
                else cont += vet2[k];
            }
        }
        else {
            for(k=n-1; k>-1; --k) {
                cont += vet2[k];
            }
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("%d\n", n-cont+1);
    }
    else printf("%d\n", n-cont);

    return 0;

}