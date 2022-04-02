#include <stdio.h>
int main() {
    int operacao;
    float valor;
        scanf("%i %f", &operacao, &valor);
    float creditos, debitos;
    while (operacao != -1) {
        if(operacao == 1) {
            creditos += valor;
        }
        else if(operacao == 0) {
            debitos += valor;
        }

        scanf("%i", &operacao);
        scanf("%f", &valor);
    }
    float saldo = creditos-debitos;
    printf("Creditos: R$ %.2f\n", creditos);
    printf("Debitos: R$ %.2f\n", debitos);
    printf("Saldo: R$ %.2f\n", saldo);
    
    return 0;
}