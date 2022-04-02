#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void Quicksort(int *vet, int l, int r) {
    if(l<r) {
        int s = HoarePartition(vet, l, r);
        Quicksort(vet, l, s-1);
        Quicksort(vet, s+1, r);
    }
}

int main() {
    srand(time(0));
    FILE *fp = fopen("test_cases.txt", "w");
    int c = 25, vet[c+1];
    fprintf(fp, "%d\n", c*2);
    for(int k=0; k<c; ++k) {
        vet[k] = rand();
        fprintf(fp, "1 %d\n", vet[k]);
    }
    Quicksort(vet, 0, c-1);
    for(int k=0; k<c; ++k) {
        fprintf(fp, "2 %d\n", vet[k]);
    }
    fclose(fp);
    return 0;
}