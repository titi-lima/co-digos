#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int l, int r) {
    int temp[r], j, m, i1, i2, curr;
    for(j=l; j<=r; ++j) temp[j] = array[j]; //copia os membros do array para um temporario
    m = (l+r)/2;
    i1=l;
    i2=m+1;
    for(curr=l; curr<=r; ++curr) {
        if(i1 == m+1) array[curr] = temp[i2++];
        else if(i2>r) array[curr] = temp[i1++];
        else if(temp[i1] <= temp[i2]) array[curr] = temp[i1++];
        else array[curr] = temp[i2++];
    }

}

void mergeSort(int *array, int l, int r) {
    int m;
    if (l<r) {
        m = (l+r)/2;
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        merge(array, l, r);
    }
}

int main() {
    int *array = NULL, ncasos, size, j;
    scanf("%d", &ncasos);
    while(ncasos--) {
        scanf("%d", &size);
        array = (int*) realloc(array, size*sizeof(int));
        for(j=0; j<size; ++j) {
            scanf("%d", &array[j]);
        }
        mergeSort(array, 0, size-1);
        for(j=0; j<size; ++j) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }
    free(array);
    return 0;
}