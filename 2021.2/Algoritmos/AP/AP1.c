#include <stdio.h>
#include <stdlib.h>

int *insert(int *array, int num, int i, int tam) {
    int aux;
    array = (int*)realloc(array, tam*sizeof(int));
    for(aux = tam-1; aux>=i; --aux) { // reorganiza o array, joga todo mundo p frente
        if(aux>i) {
            array[aux] = array[aux-1];
        }
        else array[aux] = num;
    }
    return array;
}

int *remove2(int *array, int i, int tam) {
    int aux;
    for(aux = i; aux<tam+1; ++aux) { // reorganiza o array, puxa todo mundo da frente pra liberar o ultimo
        if(aux < tam) {
            array[aux] = array[aux+1];
        }
        else array = (int*)realloc(array, tam*sizeof(int)); 
    }
    return array;
}

void count(int *array, int num, int tam) {
    int aux, cont = 0;
    for(aux = 0; aux<tam; ++aux) {
        if(num == array[aux]) ++cont;
    }
    printf("%d\n", cont);
}

int main() {
    int *array = NULL, c, n, aux, aux2, num, i=0, tam=0;
    char str[7];

    scanf("%d", &c);

    for(aux = 0; aux < c; ++aux) {
        scanf("%d", &n);
        printf("Caso %d:\n", aux+1);
        for(aux2 = 0; aux2 < n; ++aux2) {
            scanf(" %s", str);
            switch(str[0]) {
                case 'i': {
                    scanf("%d", &num);
                    ++tam;
                    array = insert(array, num, i, tam);
                    break;
                }
                case 'r': {
                    --tam;
                    array = remove2(array, i, tam);
                    break;
                }
                case 'c': {
                    scanf("%d", &num);
                    count(array, num, tam);
                    break;
                }
                case 'p': {
                    if(i>tam) --i;
                    break;
                }
                case 'n': {
                    if(i<tam) ++i;
                    break;
                }
            }
        }
        free(array);
        tam=0;
        i=0;
    }

    return 0;
}