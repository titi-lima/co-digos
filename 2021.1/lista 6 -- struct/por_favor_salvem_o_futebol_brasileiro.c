#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[100];
    int dinheiro;
    char foco;
    int num;
    char player[100];
} time[26];
typedef struct {
    char nombre[100];
    char pais[100];
    int ataque;
    int defesa;
    int custo;
    char foko;
} jogador[51];

int main() {
    int w, z, x, clubes = 0, k = 0, kk = 0, Z = 0, j = 0;
    unsigned int y;
    scanf("%d", &w);
    time time;
    for (z = 0; z < w; ++z) {
        scanf(" %s", time[z].nome);
        if (strcmp(time[z].nome, "Vasco") == 0) {
            printf("Vasco nao tem salvacao, tomou 3 pro vitoria em casa\n");
            continue;
        }
        scanf("%d", &time[z].dinheiro);
        scanf(" %c", &time[z].foco);
        time[z].num = 0;
        time[z].player[0] = '\0';
    }
    scanf("%d", &y);
    jogador jogador;
    for (x = 0; x < y; ++x) {
        scanf("%s", jogador[x].nombre);
        scanf(" %[^\n]", jogador[x].pais);
        scanf("%d %d", &jogador[x].ataque, &jogador[x].defesa);
        if (jogador[x].defesa > jogador[x].ataque) {
            jogador[x].foko = 'D';
        } else
            jogador[x].foko = 'A';
        scanf("%d", &jogador[x].custo);
        for (z = 0; z < w; ++z) {
            if (time[z].dinheiro >= jogador[x].custo) {
                ++clubes;
                kk = z;
            }
            if (clubes == 1 && z == w - 1) {
                printf("%s eh do %s\n", jogador[x].nombre, time[kk].nome);
                time[kk].dinheiro -= jogador[x].custo;
                time[kk].num += 1;
                strcat(time[kk].player, jogador[x].nombre);
                strcat(time[kk].player, " ");
                strcat(time[kk].player, jogador[x].pais);
                strcat(time[kk].player, "\n");
            } else if (clubes == 0 && (z == w - 1)) {
                printf("%s ta muito caro\n", jogador[x].nombre);
            }
        }
        if (clubes > 1) {
            clubes = 0;
            for (z = 0; z < w; ++z) {
                if (time[z].dinheiro >= jogador[x].custo && jogador[x].foko == time[z].foco) {
                    ++clubes;
                    kk = z;
                }
            }
            if (clubes == 1) {
                printf("%s eh do %s\n", jogador[x].nombre, time[kk].nome);
                time[kk].dinheiro -= jogador[x].custo;
                time[kk].num += 1;
                strcat(time[kk].player, jogador[x].nombre);
                strcat(time[kk].player, " ");
                strcat(time[kk].player, jogador[x].pais);
                strcat(time[kk].player, "\n");
            } else if (clubes == 0) { // verificar aqui
                for (z = 0; z < w; ++z) {
                    if (time[z].dinheiro >= jogador[x].custo && time[z].dinheiro > k) {
                        k = time[z].dinheiro;
                        kk = z;
                    }
                }
                k = 0;
                printf("%s eh do %s\n", jogador[x].nombre, time[kk].nome);
                time[kk].dinheiro -= jogador[x].custo;
                time[kk].num += 1;
                strcat(time[kk].player, jogador[x].nombre);
                strcat(time[kk].player, " ");
                strcat(time[kk].player, jogador[x].pais);
                strcat(time[kk].player, "\n");
            }
        }
        if (clubes > 1) {
            clubes = 0;
            for (z = 0; z < w; ++z) {
                if (time[z].dinheiro >= jogador[x].custo && jogador[x].foko == time[z].foco && time[z].dinheiro > k) {
                    k = time[z].dinheiro;
                    kk = z;
                }
            }
            k = 0;
            printf("%s eh do %s\n", jogador[x].nombre, time[kk].nome);
            time[kk].dinheiro -= jogador[x].custo;
            time[kk].num += 1;
            strcat(time[kk].player, jogador[x].nombre);
            strcat(time[kk].player, " ");
            strcat(time[kk].player, jogador[x].pais);
            strcat(time[kk].player, "\n");
        }
        k = 0;
        z = 0;
        clubes = 0;
    }
    for (z = 0; z < w; ++z) {
        if (strcmp(time[z].nome, "Vasco") != 0) {
            printf("\nSituacao %s\n", time[z].nome);
            printf("Dinheiro restante = %d\n", time[z].dinheiro);
            printf("Num de Jogadores = %d\n", time[z].num);
            printf("%s", time[z].player);
        }
    }
    if (w == 0) {
        for (x = 0; x < y; ++x) {
            printf("%s ta muito caro\n", jogador[x].nombre);
        }
    }

    return 0;
}