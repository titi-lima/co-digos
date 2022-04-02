#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int pontuacao;
    int tentativas;
} Competidor;

int **realocarMatriz(int **matriz, int n) {
    int aux, aux2;
    matriz = (int **)realloc(matriz, n * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocacao.\n");
        exit(1);
    }
    for (aux = 0; aux < n; ++aux) {
        matriz[aux] = (int *)realloc(matriz[aux], n * sizeof(int));
        if (matriz[aux] == NULL) {
            printf("Erro na alocacao.\n");
            exit(1);
        }
        for (aux2 = 0; aux2 < n; ++aux2) {
            matriz[aux][aux2] = 0;
        }
    }
    return matriz;
}

Competidor* leCompetidores(Competidor *competidores,int qtdAtual,int qtdTotal){
     int i;
     printf("\n*********LEITURA DE COMPETIDORES**********\n");
     competidores=(Competidor*)realloc(competidores,qtdTotal*sizeof(Competidor));
     if(competidores==NULL){ // por favor facam isso
        printf("falha na alocacao de competidores");
        exit(1);
     }
     for(i=qtdTotal-qtdAtual;i<qtdTotal;i++) {
        printf("Insira o nome do competidor %d: ", i+1); 
        scanf(" %s", competidores[i].nome);
        printf("quantas tentativas tem o competidor %d: ", i+1);
        scanf("%d", &competidores[i].tentativas);
        competidores[i].pontuacao=0;
     }
     return competidores;
}

int **colocarTesouros(int **matriz, int n, int *numTesouros) {
    int aux, aux2;
    *numTesouros = 0;
    for (aux = 0; aux < n; ++aux) { // o ovo sera identificado por ter valor 1
        for (aux2 = 0; aux2 < n; ++aux2) {
            if ((4 * aux * aux + 3 * aux2) % 11 == 0) {
                matriz[aux][aux2] = 1;
                (*numTesouros)++;
            }
        }
    }
    return matriz;
}
void acharVencedor(Competidor* competidores, int qtdTotal){
     int i;
     Competidor vencedor;
     vencedor=competidores[0];
     for(i=0;i<qtdTotal;i++){
        if(competidores[i].pontuacao>vencedor.pontuacao){
            vencedor = competidores[i];
        }
     }
     printf("o vencedor eh: %s\n", vencedor.nome);
     printf("sua pontuacao: %d\n", vencedor.pontuacao);
     printf("quantidade de tentativas: %d\n", vencedor.tentativas);
}

void liberarMatriz(int **matriz, int n) {
    int aux;
    for (aux = 0; aux < n; ++aux) {
        free(matriz[aux]);
    }
    free(matriz);
}

int main() {
    Competidor *competidores = NULL;
    int qtdAtual, qtdTotal=0, **matriz = NULL, numTesouros, n, cont;
    int aux, aux2;
    int x,y;
    printf("Digite o tamanho da matriz nxn para a primeira rodada: ");
    scanf("%d", &n);
    while(n != 0) {
      matriz = realocarMatriz(matriz, n);
      matriz = colocarTesouros(matriz, n, &numTesouros);
      printf("Digite o numero de participantes da rodada: ");
      scanf("%d", &qtdAtual);
      qtdTotal += qtdAtual;
      competidores = leCompetidores(competidores, qtdAtual, qtdTotal);
      for(aux = qtdTotal-qtdAtual; aux<qtdTotal; ++aux) {
        for(aux2 = 0; aux2<competidores[aux].tentativas; ++aux2) {
          if(numTesouros!=0) {
            printf("\nCompetidor %s, digite sua jogada no formato x y: ", competidores[aux].nome);
            scanf("%d %d", &x, &y);
            if(matriz[x][y] == 1) {
              competidores[aux].pontuacao++;
              matriz[x][y] = 0;
              --numTesouros;
            }
          }
        }
      }
        printf("\nDigite o tamanho n para a matriz quadrada nxn: ");
        scanf("%d", &n);
    }
    acharVencedor(competidores, qtdTotal);
    liberarMatriz(matriz, n);
    //free(matriz); terminal acusa "pointer being freed was not allocated"
    free(competidores);
    printf("OBRIGADO POR JOGAR !!!! ");
    return 0;
}