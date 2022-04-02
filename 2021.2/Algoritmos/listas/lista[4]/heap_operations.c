#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int size;
    int *a;
    char **str;
} Heap;

Heap* create_heap() {
    Heap *h = (Heap*) malloc(sizeof(Heap));
    h->a = (int*)malloc(sizeof(int)); // a[0] n tem ngm
    h->size = 1;
    h->str = NULL;
    return h;
}

void printHeap(Heap *h) {
    for(int k=1; k<h->size; ++k) {
        printf("%d ", h->a[k]);
    }
    printf("\n");
}

void swap(int *vet, int i, int j) {
    if(vet[i] == vet[j]) return;
    vet[i]^=vet[j];
    vet[j]^=vet[i];
    vet[i]^=vet[j];
}

int min(int *vet, int i, int j) {
    if(vet[i]>vet[j]) return j;
    else return i;
}

void heapify(int *a, int i, Heap *h) {
    int j;
    if(i!=1 && a[i] < a[i/2]) { // se o pai for maior q o filho, troca e chama dnv o heapify ate q o pai seja menor
        swap(a, i, i/2);
        heapify(a, i/2, h);
    }
    else if(i*2<h->size) { // checar aqui em caso de segfault VER QUAL EH O MENOR PRA TROCAR
        j = min(h->a, i*2, (i*2)+1);
        if(i*2+1 < h->size && a[i] > a[j]) {
            swap(a, i, j);
            heapify(a, j, h);
        }
        else if(a[i] > a[2*i]) {
            swap(a, i, i*2);
            heapify(a, i*2, h);
        }
    }
}

char **updateMatrix(char **matrix, int *cont) {
    ++(*cont);
    //printf("cont: %d\n", *cont);
    matrix = (char**)realloc(matrix, *cont * sizeof(char*));
    matrix[*cont-1] = (char*)malloc(30*sizeof(char));
    //printf("cont: %d\n", *cont);
    return matrix;
}

void insert(Heap* h, int key, int *cont) {
    h->size++;
    h->a = (int*)realloc(h->a, (h->size)*sizeof(int));
    h->a[h->size-1] = key;
    heapify(h->a, h->size-1, h);
    //printf("nao eh 4? %d\n", h->a[1]);
    h->str = updateMatrix(h->str, cont);
    //printf("cont = %d\n", *cont);
    sprintf(h->str[*cont-1], "insert %d", key);
}

void removeMin(Heap *h, int *cont) { // e se ele pedir um removeMin logo no comeco?
    //printf("ta aqui ne %d\n", *cont);
    if(h->size==1) {
        insert(h, 0, cont);
        removeMin(h, cont);
        return;
    }
    h->size--;
    if(h->size>1){
        //printf("size: %d\n", h->size);
        swap(h->a, 1, h->size); // troca o ultimo pelo primeiro
        //printf("cont:%d\n", *cont);
        heapify(h->a, 1, h);
    }
    h->a = (int*)realloc(h->a, (h->size)*sizeof(int));
    h->str = updateMatrix(h->str, cont);
    strcpy(h->str[*cont-1], "removeMin");
}

void getMin(Heap *h, int key, int *cont) {
    //printf("cont na entrada:%d\n", *cont);
    ++(*cont);
    //printf("key:%d, root:%d\n", key, h->a[1]);
    if(h->size == 1 || key < h->a[1]) {
        //printf("blz da pra perdoar esse\n");
        --(*cont);
        insert(h, key, cont);
        getMin(h, key, cont);
        return;
    }
    else if(h->a[1] == key) {
        --(*cont);
        //printf("cont na saida:%d\n", *cont);
        h->str = updateMatrix(h->str, cont);
        sprintf(h->str[*cont-1], "getMin %d", key);
        return;
    }
    else {
        //printf("ta aqui ne %d\n", *cont);
        //printf("blz da pra perdoar esse tb\n");
        --(*cont);
        removeMin(h, cont);
        getMin(h, key, cont);
    }
}

void printMatrix(char **str, int size) {
    printf("%d\n", size);
    for(int k=0; k<size; ++k) printf("%s\n", str[k]);
}

void freeMatrix(char **matrix, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeHeap(Heap *h, int *cont) {
    free(h->a);
    freeMatrix(h->str, *cont);
    free(h);
}

//insert insere, removemin tira a raiz e reorganiza, getmin checa se a raiz eh o numero
//e se nao for, remove a raiz (e registra no printf) ate que a raiz seja a chave (prossegue) ou a exceda (registra o insert no printf)

int main() {
    int key, n, cont = 0;
    char com[10];
    Heap *h = create_heap();
    scanf("%d", &n);
    while(n--) {
        scanf(" %s", com);
        switch(com[0]) {
            case 'i': {
                scanf("%d", &key);
                insert(h, key, &cont);
                break;
            }
            case 'r': {
                removeMin(h, &cont);
                break;
            }
            case 'g': {
                scanf("%d", &key);
                getMin(h, key, &cont);
                break;
            }
        }
    }
    printMatrix(h->str, cont);
    freeHeap(h, &cont);
    return 0;
}