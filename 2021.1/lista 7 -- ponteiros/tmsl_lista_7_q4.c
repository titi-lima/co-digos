#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *vet = (int *)calloc(n, sizeof(int));
    while (n > 0) {
        if (vet != NULL) {
            vet = (int *)realloc(vet, n * sizeof(int));
            scanf("%d", &n);
        }
    }
    free(vet);

    return 0;
}