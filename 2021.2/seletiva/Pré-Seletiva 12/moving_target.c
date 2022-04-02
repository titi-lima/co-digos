#include <stdio.h>

int main() {
    int size, amount, aux;
    scanf("%d", &size);
    amount = (size+2)/2;
    printf("%d\n", amount);
    if(size%2==0) {
        for(aux=1; aux<size; aux+=2) {
            printf("%d ", aux);
        }
        printf("%d\n", size);
    }
    else {
        for(aux=1; aux<size; aux+=2) {
            printf("%d ", aux);
        }
        printf("%d\n", size);
    }
    return 0;
}