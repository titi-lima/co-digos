#include <stdio.h>

int main() {
    float h, m, mult, resultado;
    mult = h * 60;
    resultado = mult + m;

    printf("Digite as horas: "); // (linha removida no thehuxley)
    scanf("%f", &h);

    printf("Digite os minutos: "); // (linha removida no thehuxley)
    scanf("%f", &m);

    printf("%.0f minutos.\n", resultado);    

    return 0;
}
