#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* vet;
} Array;

Array* scanArray(Array* a) {
    int k;
    scanf("%d", &a->size);
    a->vet = (int*)realloc(a->vet, a->size*sizeof(int));
    for(k=0; k<a->size; ++k) {
        scanf("%d", &a->vet[k]);
    }
    return a;
}

void printArray(int *vet, int size) {
    int k;
    for(k=0; k<size; ++k) printf("%d ", vet[k]);
    printf("\n"); // caso isso caia em lista, se ligar aqui pq pode dar um espaco a mais
}

void swap(int *vet, int i, int j) {
    if(vet[i] == vet[j]) return;
    vet[i]^=vet[j];
    vet[j]^=vet[i];
    vet[i]^=vet[j];
}

int HoarePartition(int *vet, int l, int r) {
    int p = vet[l];
    int i = l;
    int j = r+1;
    do {
        do {
            ++i;
        } while(p > vet[i] && r > i);
        do {
            --j;
        } while(p < vet[j]);
        swap(vet, i, j);
    } while(i<j);
    swap(vet, i, j);
    swap(vet, l, j);
    return j;
}

void Quicksort(Array *a, int l, int r) {
    if(l<r) {
        int s = HoarePartition(a->vet, l, r);
        //printArray(a->vet, a->size);
        Quicksort(a, l, s-1);
        Quicksort(a, s+1, r);
    }
}

int main() {
    Array *a = NULL;
    a = (Array*) malloc(sizeof(Array));
    int ncasos;
    scanf("%d", &ncasos);
    while(ncasos--) {
        a = scanArray(a);
        Quicksort(a, 0, a->size-1);
        printArray(a->vet, a->size);
    }
    free(a->vet);
    free(a);
    return 0;
}