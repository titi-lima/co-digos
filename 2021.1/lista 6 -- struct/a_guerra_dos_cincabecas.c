#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int idade;
    int id;
    char nome[21];
    int pontos;
} competidor[100];

int main() {
    int i = 0, flag = 0, x = 2;
    competidor competidor;
    while (scanf("%d", &competidor[i].idade) != EOF) {
        competidor[i].pontos = 0;
        scanf("%d", &competidor[i].id);
        scanf(" %[^\n]", competidor[i].nome);
        while (x <= competidor[i].idade / 2 && flag != 1) { // checa se eh primo
            if (competidor[i].idade % x == 0) {
                flag = 1;
                x = 2;
            } else
                ++x;
        }
        x = 2;           //resetando
        if (flag == 0) { // eh primo
            competidor[i].pontos += 4;
            //printf("\n%d eh primo\n", competidor[i].idade);
        }
        flag = 0; //resetando
        float q = pow(competidor[i].id, 0.5);
        int comp = q;
        if (comp == q) {
            competidor[i].pontos += 3;
            //printf("%d eh QP\n", competidor[i].id);
        }
        ++i;
    }
    if (strcmp(competidor[0].nome, competidor[1].nome) > 0) {
        competidor[0].pontos += 2;
        //printf("teste\n");
    } else
        competidor[1].pontos += 2;
    if (competidor[0].pontos > competidor[1].pontos) {
        printf("%s WINS\n", competidor[0].nome);
    } else if (competidor[0].pontos < competidor[1].pontos) {
        printf("%s WINS\n", competidor[1].nome);
    } else
        printf("CInCABECAS EMPATADOS\n");

    return 0;
}