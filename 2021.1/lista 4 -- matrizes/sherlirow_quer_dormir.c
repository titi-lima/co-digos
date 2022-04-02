#include <stdio.h>

int main() {
    int n, tamx, tamy, x, y, aux, maior=0;
    scanf("%d %d %d", &n, &tamx, &tamy);
    int tab[tamx][tamy], coord[n][2], p[4];
    for(x=0; x<n; ++x) {
        scanf("%d %d", &coord[x][0], &coord[x][1]);
    }
    for(x=0; x<tamx; ++x) {
        for(y=0; y<tamy; ++y) {
            scanf("%d", &tab[x][y]);
        }
    }
    for(x=0; x<4; ++x) {
        p[x]=0;
    }
    for(aux=0; aux<n; ++aux) {
        for(x=0; x<tamx; ++x) {
            switch (tab[x][coord[aux][1]]) {
                case 1: {
                    ++p[0];
                    tab[x][coord[aux][1]] = 11;
                    break;
                }
                case 2: {
                    ++p[1];
                    tab[x][coord[aux][1]] = 12;
                    break;
                }
                case 3: {
                    ++p[2];
                    tab[x][coord[aux][1]] = 13;
                    break;
                }
                case 4: {
                    ++p[3];
                    tab[x][coord[aux][1]] = 14;
                    break;
                }
                default: break;
            }
        }
        for(x=0; x<4; ++x) {
            if(p[x]>maior) {
                maior = p[x];
            }
        }
        for(x=0; x<tamy; ++x) {
            switch (tab[coord[aux][0]][x]) {
                case 1: {
                    ++p[0];
                    tab[coord[aux][0]][x] = 11;
                    break;
                }
                case 2: {
                    ++p[1];
                    tab[coord[aux][0]][x] = 12;
                    break;
                }
                case 3: {
                    ++p[2];
                    tab[coord[aux][0]][x] = 13;
                    break;
                }
                case 4: {
                    ++p[3];
                    tab[coord[aux][0]][x] = 14;
                    break;
                }
                default: break;
            }
        }
        for(x=0; x<4; ++x) {
            if(p[x]>maior) {
                maior = p[x];
                p[x]=0;
            }
            else p[x]=0;
        }
        for(x=0; x<tamx; ++x) {
            for(y=0; y<tamy; ++y) {
                if(tab[x][y] > 10) {
                    tab[x][y]-=10;
                }
            }
        }
    }
    printf("A pontuacao da equipe vencedora sera %d ponto(s)!\n", maior);
    /*for(x=0; x<n; ++x) {
        printf("%d %d", coord[x][0], coord[x][1]);
    }
    for(auxx=0; auxx<tamx; ++auxx) {
                        for(auxy=0; auxy<tamy; ++auxy) {
                            printf("%d ", tab[auxx][auxy]);
                        }
                        printf("\n");
                    }
                    printf("\n");*/
    return 0;
}