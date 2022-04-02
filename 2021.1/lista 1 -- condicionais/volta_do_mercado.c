#include <stdio.h>

int main () {
float h;
    scanf("%f", &h);
        if (h<0) {
            printf("Meme man quebrou o tempo! De volta ao transito :(\n");
        }
        else if (h>=0 && h<62) {
            printf("...Ainda no transito...\n");
        }
        else if (h>=3720 && h<3744) {
            printf("Stonks has been born!\n");
        }
        else printf("Lar doce lar\n");

    return 0;
}