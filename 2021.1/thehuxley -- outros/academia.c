#include <stdio.h>
#include <string.h>

int main() {
    char nome[101][50], estado[101], sair[5] = "SAIR";
    int senha[101], i = 0, m = 0, flag = 0;
    scanf("%[^\n]", &nome[i][m]);
    if (strcmp(&nome[i][m], sair) == 0) {
        flag = 1;
    }
    while (flag != 1) {
        scanf("%d", &senha[i]);
        scanf(" %c", &estado[i]);
        //printf("senha: %d\nestado: %c\n", senha[i], estado[i]);
        ++i;
        //printf("nome 0: %s\n", &nome[i][m]);
        scanf(" %[^\n]", &nome[i][m]);
        if (strcmp(&nome[i][m], sair) == 0) {
            flag = 1;
        }
    }
    //printf("nome4: %s\n", &nome[4]);
    int cadastradas[1000], k = 0;
    for (k = 0; (cadastradas[k] != -1); ++k) {
        scanf("%d", &cadastradas[k]);
        //printf("%d\n", cadastradas[k]);
        if (cadastradas[k] == -1) {
            break;
        }
    }
    flag = 0;
    for (k = 0; cadastradas[k] != -1; ++k) {
        for (i = 0; flag < 1; ++i) {
            //printf("cadastradas:%d senha: %d", cadastradas[k], senha[i]);
            if (cadastradas[k] == senha[i]) {
                //printf("eh sacangem man tem como n\n");
                flag = 2;
            } else if (strcmp(&nome[i][m], sair) == 0) {
                //printf("eh sacanagem man tem como n\n");
                flag = 1;
            }
        }
        --i;
        //printf("flag: %d\n", flag);
        if (flag == 2) {
            //printf("i:%d\n", i);
            if (estado[i] == 'P') {
                printf("%s, seja bem-vindo(a)!\n", &nome[i][m]);
            } else
                printf("Não está esquecendo de algo, %s? Procure a recepção!\n", &nome[i][m]);
        } else
            printf("Seja bem-vindo(a)! Procure a recepção!\n");
        flag = 0;
    }
}