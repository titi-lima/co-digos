#include <stdio.h>
#include <stdlib.h>

void somaUm(int x) {
    ++x;
    printf("\nNa funcao somaUm, o valor de x eh %d", x);
    //printf(" e seu endereco de memoria eh %p", &x);
    printf("\n");
}

/*void somaUmComPonteiro(int *x) {
    ++(*x);
    printf("\nNa funcao somaUmComPonteiro, o valor de x eh %d", *x);
    printf(" e seu endereco de memoria eh %p", x);
    printf("\n");
}*/

/*void alocaVet(int *vet) {
    vet = (int*)realloc(vet, sizeof(int));
    vet[0] = 5;
    printf("\nNa funcao alocaVet, vet[0]: %d\n", vet[0]);
}*/

/*int* alocaVetInt(int *vet) {
    vet = (int*)realloc(vet, sizeof(int));
    vet[0] = 5;
    printf("\nNa funcao alocaVetInt, vet[0]: %d\n", vet[0]);
    return vet;
}*/

/*void alocaVetDuplo(int **vet) {
    *vet = (int*)realloc(*vet, sizeof(int));
    *vet[0] = 6;
    printf("\nNa funcao alocaVetDuplo, vet[0]: %d\n", *vet[0]);
}*/

int main() {
    int x = 5;
    somaUm(x);
    printf("Na main, apos a funcao somaUm, o valor de x eh %d", x);
    //printf(" e seu endereco de memoria eh %p", &x);
    printf("\n\n");

    /*somaUmComPonteiro(&x);
    printf("Na main, apos a funcao somaUmComPonteiro, o valor de x eh %d", x);
    printf(" e seu endereco de memoria eh %p", &x);
    printf("\n\n");*/

    //int *vet = NULL;

    //alocaVet(vet);
    //printf("Na main, apos a funcao alocaVet, vet[0]: %d\n\n", vet[0]);


    //vet = alocaVetInt(vet);
    //printf("Na main, apos a funcao alocaVetInt, vet[0]: %d\n\n", vet[0]);

    //alocaVetDuplo(&vet);
    //printf("Na main, apos a funcao alocaVetDuplo vet[0]: %d\n\n", vet[0]);

    //free(vet);
    return 0;
}