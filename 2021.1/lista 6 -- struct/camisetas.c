#include <stdio.h>
#include <string.h>
//crescente, decrescente, crescente
//se for branco, checa se p; se p, checa se tem algm maior. faz isso infinitamente e zera isso toda vez p evitar dar merda dps
typedef struct {
    char nome[1000];
    char cor[9];
    char tam;
} alunos[100];
int main() {
    int s, i = 0, k = 0, km1 = k + 1;
    char temp[100], tt;
    scanf("%d", &s);
    while (s != 0) {
        printf("\n");
        alunos alunos;
        for (k = 0; k < s; ++k) {
            scanf("\n %[^\n]", alunos[k].nome);
            scanf("%s", alunos[k].cor);
            scanf(" %c", &alunos[k].tam);
        }
        //printf("probleminha: %s\n", alunos[0].nome);
        for (k = 0; k < s; ++k) { //ordena alfabeticamente antes
                                  //printf("aqui entrou\n");
            for (km1 = k + 1; km1 < s; ++km1) {
                //printf("aqui entrou'\n");
                if (strcmp(alunos[k].nome, alunos[km1].nome) > 0) {
                    //printf("aqui entrou''\n");
                    strcpy(temp, alunos[k].nome);
                    strcpy(alunos[k].nome, alunos[km1].nome);
                    strcpy(alunos[km1].nome, temp);
                    strcpy(temp, alunos[k].cor);
                    strcpy(alunos[k].cor, alunos[km1].cor);
                    strcpy(alunos[km1].cor, temp);
                    tt = alunos[k].tam;
                    alunos[k].tam = alunos[km1].tam;
                    alunos[km1].tam = tt;
                }
            }
        }
        for (k = 0; k < s; ++k) {
            if (strcmp(alunos[k].cor, "branco") == 0) {
                if (alunos[k].tam == 'P') {
                    printf("%s %c %s\n", alunos[k].cor, alunos[k].tam, alunos[k].nome);
                }
            }
        }
        for (k = 0; k < s; ++k) {
            if (strcmp(alunos[k].cor, "branco") == 0) {
                if (alunos[k].tam == 'M') {
                    printf("%s %c %s\n", alunos[k].cor, alunos[k].tam, alunos[k].nome);
                }
            }
        }
        for (k = 0; k < s; ++k) {
            if (strcmp(alunos[k].cor, "branco") == 0) {
                if (alunos[k].tam == 'G') {
                    printf("%s %c %s\n", alunos[k].cor, alunos[k].tam, alunos[k].nome);
                }
            }
        }
        for (k = 0; k < s; ++k) {
            if (strcmp(alunos[k].cor, "vermelho") == 0) {
                if (alunos[k].tam == 'P') {
                    printf("%s %c %s\n", alunos[k].cor, alunos[k].tam, alunos[k].nome);
                }
            }
        }
        for (k = 0; k < s; ++k) {
            if (strcmp(alunos[k].cor, "vermelho") == 0) {
                if (alunos[k].tam == 'M') {
                    printf("%s %c %s\n", alunos[k].cor, alunos[k].tam, alunos[k].nome);
                }
            }
        }
        for (k = 0; k < s; ++k) {
            if (strcmp(alunos[k].cor, "vermelho") == 0) {
                if (alunos[k].tam == 'G') {
                    printf("%s %c %s\n", alunos[k].cor, alunos[k].tam, alunos[k].nome);
                }
            }
        }
        scanf("%d", &s);
    }

    return 0;
}