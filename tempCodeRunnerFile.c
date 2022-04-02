#include <stdio.h>

int main() {
    int n=0;
    char vet[2];
    vet[0] = 't';
    vet[1] = 'r';

    while(++n) {
        printf("%s\n", &vet[n]);
    }
    return 0;
}