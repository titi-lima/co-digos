#include <stdio.h>

int main() {
    int vet[5] = {1, 2, 3, 4, 5};
    int *p[5] = {&vet[0], &vet[1], &vet[2], &vet[3], &vet[4]};
    int aux;
    printf("a) %p e %p\n", &vet, &p);
    printf("b) ");
    for (aux = 0; aux < 5; ++aux) {
        printf("%d ", *p[aux]);
    }
    printf("\n");
    printf("c) ");
    for (aux = 0; aux < 5; ++aux) {
        printf("%d ", *(p[0] + aux));
    }
    printf("\n");
    printf("d) ");
    for (aux = 0; aux < 5; ++aux) {
        printf("%d ", vet[aux]);
    }
    printf("\n   ");
    for (aux = 0; aux < 5; ++aux) {
        printf("%d ", *&vet[aux]);
    }
    printf("\n");

    return 0;
}