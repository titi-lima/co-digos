#include <stdio.h>
#include <stdlib.h>
int main() {
    int *vet = (int*) malloc(sizeof(int));
    free(vet);
    return 0;
}