#include <stdio.h>

typedef struct {
    int preco;
    int velocidade;
    float peso;
} yoshi;

int main() {
    yoshi verde;
    yoshi vermelho;
    yoshi azul;
    yoshi amarelo;

    int dinheiro, k;

    scanf("%d", &dinheiro);
    scanf("%d", &verde.preco);
    scanf("%d", &verde.velocidade);
    scanf("%d", &vermelho.preco);
    scanf("%d", &vermelho.velocidade);
    scanf("%d", &azul.preco);
    scanf("%d", &azul.velocidade);
    scanf("%d", &amarelo.preco);
    scanf("%d", &amarelo.velocidade);

    verde.peso=verde.velocidade*1.0/verde.preco;
    vermelho.peso=vermelho.velocidade*1.0/vermelho.preco;
    azul.peso=azul.velocidade*1.0/azul.preco;
    amarelo.peso=amarelo.velocidade*1.0/amarelo.preco;

    if(verde.peso>=vermelho.peso-1 && verde.peso>=azul.peso-1 && verde.peso >= amarelo.peso-1 && verde.preco<=dinheiro) {
        printf("Verde\n");
    }
    else if(vermelho.peso>=azul.peso && vermelho.peso >= amarelo.peso && vermelho.preco<=dinheiro) {
        printf("Vermelho\n");
    }
    else if(azul.peso >= amarelo.peso && azul.preco<=dinheiro) {
        printf("Azul\n");
    }
    else if(amarelo.preco<=dinheiro) {
        printf("Amarelo\n");
    }
    else printf("Acho que vou a pe :(\n");
    return 0;
}