#include <stdio.h>

typedef struct {
    int npassagem;
    char data[11];
    char de[1000];
    char para[1000];
    char horas[6];
    int poltrona;
    int idade;
    char nome[1000];
} passageiro[1000];

int main() {
    int i = 0, k = 0, soma = 0;

    passageiro passageiro;
    scanf("%d", &passageiro[i].npassagem);
    while (passageiro[i].npassagem != -1) {
        scanf(" %[^\n]", passageiro[i].data);
        scanf(" %[^\n]", passageiro[i].de);
        scanf(" %[^\n]", passageiro[i].para);
        scanf(" %[^\n]", passageiro[i].horas);
        scanf("%d", &passageiro[i].poltrona);
        scanf("%d", &passageiro[i].idade);
        scanf(" %[^\n]", passageiro[i].nome);
        scanf("%d", &passageiro[i + 1].npassagem);
        ++i;
    }
    for (k = 0; k < i; ++k) {
        soma += passageiro[k].idade;
    }
    soma /= i;
    for (k = 0; k < i; ++k) {
        if (soma < passageiro[k].idade && passageiro[k].poltrona % 2 == 0) {
            printf("%s\n", passageiro[k].nome);
        }
    }
    return 0;
}