#include <stdio.h>
int main () {
int input, frequente1=0, frequente2=0, frequencia1=0, frequencia2=0, divisor=2;
    scanf("%i", &input);

    while (input != 1) {
        if (input % divisor == 0) {
            frequente1 = divisor;
            input /= divisor;
            ++frequencia1;

        }
        else {
            if (frequencia1>frequencia2) {
                frequente2 = frequente1;
                frequencia2 = frequencia1;
                frequencia1 = 0;
                frequente1 = 0;
            }
            else {
                frequencia1 = 0;
                frequente1 = 0;
            }
            ++divisor;
        }
    
    }
    if (frequencia1>frequencia2) {
                frequente2 = frequente1;
                frequencia2 = frequencia1;
                frequencia1 = 0;
                frequente1 = 0;
            }
    printf("mostFrequent: %i, frequency: %i\n", frequente2, frequencia2);

    return 0;
}