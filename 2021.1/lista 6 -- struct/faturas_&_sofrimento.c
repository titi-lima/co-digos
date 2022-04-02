#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[32];
    long int cartao;
    int cvv;
    float valor;
} pessoa[7];
int main() {
    int w, y, conts = 0, contn = 0, soma = 0;
    char beneficiados[7][32], nbeneficiados[7][32];
    scanf("%d", &w);
    pessoa pessoa;
    for (y = 0; y < w; ++y) {
        scanf(" %[^\n]", pessoa[y].nome);
        scanf("%ld", &pessoa[y].cartao);
        scanf("%d", &pessoa[y].cvv);
        scanf("%f", &pessoa[y].valor);
    }
    for (y = 0; y < w; ++y) {
        while (pessoa[y].cartao != 0) {
            soma += (pessoa[y].cartao % 10);
            pessoa[y].cartao /= 10;
        }
        if (soma >= pessoa[y].cvv) {
            pessoa[y].valor = 0;
            strcpy(beneficiados[conts], pessoa[y].nome);
            ++conts;
        } else {
            pessoa[y].valor *= (pessoa[y].cvv - soma);
            strcpy(nbeneficiados[contn], pessoa[y].nome);
            ++contn;
        }
        soma = 0;
    }
    printf("Um total de %d clientes se beneficiaram da nova politica!\n", conts);
    for (y = 0; y < conts; ++y) {
        printf("%s 0.00\n", beneficiados[y]);
    }
    printf("No entanto, %d clientes nao se beneficiaram da nova politica.\n", contn);
    for (y = 0; y < contn; ++y) {
        printf("%s %.2f\n", nbeneficiados[y], pessoa[y].valor);
    }

    return 0;
}