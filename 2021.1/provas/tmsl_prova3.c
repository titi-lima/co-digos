#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char **criaMatriz(char **tab) {
    int aux, aux2;
    tab = (char**) realloc(tab, 8*sizeof(char *));
    if (tab == NULL) {
        printf("Erro na alocacao.\n");
        exit(1);
    }
    for (aux = 0; aux < 8; ++aux) {
        tab[aux] = (char *)realloc(tab[aux], 8 * sizeof(char));
        if (tab[aux] == NULL) {
            printf("Erro na alocacao.\n");
            exit(1);
        }
        for (aux2 = 0; aux2 < 8; ++aux2) { // zera a matriz, util depois para verificar se o movimento eh valido.
            tab[aux][aux2] = '0';
        }
    }
    for (aux2 = 0; aux2 < 8; ++aux2) {
        tab[1][aux2] = 'P'; // peoes brancos. n precisa por dentro de if porque a linha toda eh de peoes e nada muda
        tab[6][aux2] = 'P'; // peoes pretos
        if(aux2 == 0 || aux2 == 7) { // torres
            tab[0][aux2] = 'T';
            tab[7][aux2] = 'T';
        }
        if(aux2 == 1 || aux2 == 6) { //cavalos
            tab[0][aux2] = 'C';
            tab[7][aux2] = 'C';
        }
        if(aux2 == 2 || aux2 == 5) { // bispos
            tab[0][aux2] = 'B';
            tab[7][aux2] = 'B';
        }
        if(aux2 == 3) { //rainha
            tab[0][aux2] = 'D';
            tab[7][aux2] = 'D';
        }
        if(aux2==4) { //rei
            tab[0][aux2] = 'R';
            tab[7][aux2] = 'R';
        }
    }
    return tab;
}

int movePeao(char **tab, char jogada[7]) {
    int ky = (jogada[1]-97), jy=jogada[4]-97; // pega uma letra minuscula e transforma em numero, tal que a=0 e z=25. util p/ verificar na matriz
    int kx = (jogada[2]-49), jx=(jogada[5]-49); // similarmente, transforma o caracter do numero em numero p/ checagem na matriz.
    if(tab[kx][ky] == 'P') { // de fato, tem um peao de onde o jogador quer mover
        printf("entrouu\n");
        if(jx == kx+2 && jy == ky+2) { // movemento diagonal do peao
            if (tab[jx+1][jy+1] != '0') { // tem uma peca no caminho, condicao necessaria para esse movimento
                if(tab[jx][jy] == '0' || tab[jx][jy] == 'R') { // nao tem peca para onde o jogador quer jogar, e podemos mover, ou eh xeque-mate.
                    if(tab[jx][jy] == 'R') { //xeque-mate
                        return 2;
                    }
                    tab[jx][jy] = 'P';
                    tab[kx][ky] = '0';
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        else if(jx == kx-2 && jy == ky+2) { // movemento diagonal do peao pt.2
            if (tab[jx-1][jy+1] != '0') { // tem uma peca no caminho, condicao necessaria para esse movimento
                if(tab[jx][jy] == '0' || tab[jx][jy] == 'R') { // nao tem peca para onde o jogador quer jogar, e podemos mover, ou eh xeque-mate.
                    if(tab[jx][jy] == 'R') {
                        return 2;
                    }
                    tab[jx][jy] = 'P';
                    tab[kx][ky] = '0';
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        else if(jx == kx+1 && jy == ky) { // movimento de uma casa pra frente
            printf("entrou\n");
            if(tab[jx][jy] == '0' || tab[jx][jy] == 'R') { // nao tem peca para onde o jogador quer jogar, e podemos mover, ou eh xeque-mate.
                if(tab[jx][jy] == 'R') {
                    return 2;
                }
                tab[jx][jy] = 'P';
                tab[kx][ky] = '0';
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

int moveTorre(char **tab, char jogada[7]) {
    int ky = (jogada[1]-97), jy=jogada[4]-97; // pega uma letra minuscula e transforma em numero, tal que a=0 e z=25. util p/ verificar na matriz
    int kx = (jogada[2]-49), jx=(jogada[5]-49); // similarmente, transforma o caracter do numero em numero p/ checagem na matriz.
    int aux, aux2;
    if(tab[kx][ky] == 'T') {
        if(kx == jx || ky == jy) { // movimento vertical ou horizontal
            for(aux=0; aux<=sqrt(pow((kx-jx), 2)); ++aux) { // percorre o caminho da torre atras de um oponente no meio do caminho que invalida a jogada. sqrt e pow usados para calcular o modulo.
                for(aux2=0; aux2<=sqrt(pow((ky-jy), 2)); ++aux2) {
                    if (tab[aux][aux2] != '0' && tab[aux][aux2] != 'R') { // 
                        return 0;
                    }
                }
            }
            if(tab[jx][jy] == 'R') { // vimos que nao tem ninguem no meio do caminho, entao se houver um rei na casa destinada, ele morre 
                return 2;
            }
            tab[jx][jy] = 'P';
            tab[kx][ky] = '0';
            return 1;
        }
        else return 0;
    }
    else return 0;
}

int moveBispo(char **tab, char jogada[7]) {
    int ky = (jogada[1]-97), jy=jogada[4]-97; // pega uma letra minuscula e transforma em numero, tal que a=0 e z=25. util p/ verificar na matriz
    int kx = (jogada[2]-49), jx=(jogada[5]-49); // similarmente, transforma o caracter do numero em numero p/ checagem na matriz.
    int aux, aux2, s=0, flag;
    if(tab[kx][ky] == 'B') {
        for(s = -7; s<8 && flag!=1; ++s) { // inicializar s como -7 poupa a necessidade de checar se vai pra cima ou pra baixo em diferentes for
            if(kx+s>=0 && kx+s < 8 && ky+s >= 0 && ky+s<8) { // previne de procurar fora das dimensoes da matriz
                if(kx + s == jx && ky + s == jy) { // checa se o movimento eh diagonal p/ a direita
                    flag = 1; // flag da diagonal p/direita
                }
            }
        }
        for(s = -7; s<8 && flag!=1; ++s) {
            if(kx-s>=0 && kx-s < 8 && ky+s >= 0 && ky+s<8) { // previne de procurar fora das dimensoes da matriz
                if(kx - s == jx && ky + s == jy) { // checa se o movimento eh diagonal p/ a esquerda
                    flag = 2; //flag da diagonal p/esquerda
                }
            }
        }
        if (flag == 0) { // n eh diagonal. 
            return 0;
        }
        for(s = -7; s<8 && flag==1; ++s) { //diagonal p/direita
            if(kx+s>=0 && kx+s < 8 && ky+s >= 0 && ky+s<8) { // previne de procurar fora das dimensoes da matriz
                if(tab[kx+s][ky+s] != '0' && tab[kx+s][ky+s] != 'R') { // checa se tem alguem no caminho ou se um xeque-mate eh possivel
                    return 0;
                }
            }
        }
        for(s = -7; s<8 && flag==2; ++s) { //diagonal p/esquerda
            if(kx+s>=0 && kx+s < 8 && ky+s >= 0 && ky+s<8) {
                if(tab[kx+s][ky+s] != '0' && tab[kx+s][ky+s] != 'R') { // checa se tem alguem no caminho ou se um xeque-mate eh possivel
                    return 0;
                }
            }
        }
        if(tab[jx][jy] == 'R') {
            return 2;
        }
        tab[jx][jy] = 'P';
        tab[kx][ky] = '0';
        return 1;

    }
    else return 0;
}

int moveCavalo(char **tab, char jogada[7]) {
    int ky = (jogada[1]-97), jy=jogada[4]-97; // pega uma letra minuscula e transforma em numero, tal que a=0 e z=25. util p/ verificar na matriz
    int kx = (jogada[2]-49), jx=(jogada[5]-49); // similarmente, transforma o caracter do numero em numero p/ checagem na matriz.
    if(tab[kx][ky] == 'C') {
        if(tab[jx][jy] == tab[kx+1][ky+2] || tab[jx][jy] == tab[kx-1][ky+2] || tab[jx][jy] == tab[kx+1][ky-2] || tab[jx][jy] == tab[kx-1][ky-2]) { // movimentos possiveis do cavalo
            if(tab[jx][jy] == '0') { //n tem ngm la, prossiga
                tab[jx][jy] = 'P';
                tab[kx][ky] = '0';
                return 1;
            }
            if(tab[jx][jy] == 'R') { // tem um rei no destino, xeque-mate
                return 2;
            }
            else return 0; // ja tem peca la
        }
        else return 0;
    }
    else return 0;
}

int moveRainha(char **tab, char jogada[7]) {
    int ky = (jogada[1]-97), jy=jogada[4]-97; // pega uma letra minuscula e transforma em numero, tal que a=0 e z=25. util p/ verificar na matriz
    int kx = (jogada[2]-49), jx=(jogada[5]-49); // similarmente, transforma o caracter do numero em numero p/ checagem na matriz.
    int aux, aux2, s=0, flag=0; 
    if(tab[kx][ky] == 'D') {
        if(kx == jx || ky == jy) { // movimento vertical ou horizontal, estilo torre
            for(aux=0; aux<=sqrt(pow((kx-jx), 2)); ++aux) { // percorre o caminho da torre atras de um oponente no meio do caminho que invalida a jogada. sqrt e pow usados para calcular o modulo.
                for(aux2=0; aux2<=sqrt(pow((ky-jy), 2)); ++aux2) {
                    if (tab[aux][aux2] != '0' && tab[aux][aux2] != 'R') { // 
                        return 0;
                    }
                }
            }
            if(tab[jx][jy] == 'R') { // vimos que nao tem ninguem no meio do caminho, entao se houver um rei na casa destinada, ele morre 
                return 2;
            }
            tab[jx][jy] = 'P';
            tab[kx][ky] = '0';
            return 1;
        } // nao retorna 0 aqui pq ainda falta checar o movimento de bispo
        else for(s = -7; s<8 && flag!=1; ++s) { // inicializar s como -7 poupa a necessidade de checar se vai pra cima ou pra baixo em diferentes for. sim, a identacao ta errada, nao deu tempo :()
            if(kx+s>=0 && kx+s < 8 && ky+s >= 0 && ky+s<8) { // previne de procurar fora das dimensoes da matriz
                if(kx + s == jx && ky + s == jy) { // checa se o movimento eh diagonal p/ a direita
                    flag = 1; // flag da diagonal p/direita
                }
            }
        }
        for(s = -7; s<8 && flag!=1; ++s) {
            if(kx-s>=0 && kx-s < 8 && ky+s >= 0 && ky+s<8) { // previne de procurar fora das dimensoes da matriz
                if(kx - s == jx && ky + s == jy) { // checa se o movimento eh diagonal p/ a esquerda
                    flag = 2; //flag da diagonal p/esquerda
                }
            }
        }
        if (flag == 0) { // n eh diagonal. 
            return 0;
        }
        for(s = -7; s<8 && flag==1; ++s) { //diagonal p/direita
            if(kx+s>=0 && kx+s < 8 && ky+s >= 0 && ky+s<8) { // previne de procurar fora das dimensoes da matriz
                if(tab[kx+s][ky+s] != '0' && tab[kx+s][ky+s] != 'R') { // checa se tem alguem no caminho ou se um xeque-mate eh possivel
                    return 0;
                }
            }
        }
        for(s = -7; s<8 && flag==2; ++s) { //diagonal p/esquerda
            if(kx+s>=0 && kx+s < 8 && ky+s >= 0 && ky+s<8) {
                if(tab[kx+s][ky+s] != '0' && tab[kx+s][ky+s] != 'R') { // checa se tem alguem no caminho ou se um xeque-mate eh possivel
                    return 0;
                }
            }
        }
        if(tab[jx][jy] == 'R') {
            return 2;
        }
        tab[jx][jy] = 'P';
        tab[kx][ky] = '0';
        return 1;

    }
    else return 0;
}
int moveRei(char **tab, char jogada[7]) {
    int ky = (jogada[1]-97), jy=jogada[4]-97; // pega uma letra minuscula e transforma em numero, tal que a=0 e z=25. util p/ verificar na matriz
    int kx = (jogada[2]-49), jx=(jogada[5]-49); // similarmente, transforma o caracter do numero em numero p/ checagem na matriz.
    if(tab[kx][ky] == 'R') {
        if(jx <= kx+1 && jy <= ky+1 || jx <= kx+1 && jy <= ky-1 || jx <= kx-1 && jy <= ky+1 || jx <= kx-1 && jy <= ky-1) { // movimentos possiveis do rei. "<="" usado porque é valido q jx == jy
            if(tab[jx][jy] == '0') { //n tem ngm la, prossiga
                tab[jx][jy] = 'P';
                tab[kx][ky] = '0';
                return 1;
            }
            if(tab[jx][jy] == 'R') { // tem um rei no destino, xeque-mate
                return 2;
            }
            else return 0; // ja tem peca la
        }
        else return 0; // movimento impossivel
    }
    else return 0; // n tem rei
}

void liberarTab(char **tab) {
    int aux;
    for (aux = 0; aux < 8; ++aux) {
        free(tab[aux]);
    }
    free(tab);
}

int main() {
    FILE *fp = fopen("xadrez.bin", "wb");
    char **tab = NULL;
    tab = criaMatriz(tab);
    int cont = 0, i = 0, j=0;
    while(j != 2) { // j == 2 indica xeque-mate 
        char jogada[7]; 
        //char p[2][8] = {"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"}, c[2][2] = {"b1", "g1"}, t[2][2] = {"a1", "h1"}, d[2] = {"d1"}, r[2] = {"e1"}, b[2][2]={"c1", "f1"};
        //char P[2][8] = {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"}, C[2][2] = {"b8", "g8"}, T[2][2] = {"a8", "h8"}, D[2] = {"d8"}, R[2] = {"e8"}, B[2][2]={"c8", "f8"};
        if(cont%2==0) { //alterna as jogadas. vez do branco
            printf("Branco, faca sua jogada: ");
            scanf(" %6[^\n]", jogada);
            switch(jogada[0]) {
                case 'P': {
                    j = movePeao(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Peao para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do branco!\n");
                    break;
                }
                case 'T': {
                    j = moveTorre(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Torre para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp);
                    }
                    else printf("Xeque-mate. Vitoria do branco!\n");
                    break;
                }
                case 'C': {
                    j = moveCavalo(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Cavalo para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do branco!\n");
                    break;
                }
                case 'B': {
                    j = moveBispo(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Bispo para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do branco!\n");
                    break;
                }
                case 'R': {
                    j = moveRei(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Rei para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do branco!\n");
                    break;
                }
                case 'D': {
                    j = moveRainha(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Rainha para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do branco!\n");
                    break;
                }
            }
        }
        else { // vez do preto
            printf("Preto, faca sua jogada: ");
            scanf(" %6[^\n]", jogada);
            switch(jogada[0]) {
                case 'P': {
                    j = movePeao(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Peao para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do preto!\n");
                    break;
                }
                case 'T': {
                    j = moveTorre(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Torre para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do preto!\n");
                    break;
                }
                case 'B': {
                    j = moveBispo(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Bispo para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do preto!\n");
                    break;
                }
                case 'R': {
                    j = moveRei(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Rei para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do preto!\n");
                    break;
                }
                case 'D': {
                    j = moveRainha(tab, jogada);
                    if(j==0) {
                        printf("Movimento invalido\n");
                    }
                    else if (j==1) {
                        printf("Rainha para a casa %c%c\n", jogada[4], jogada[5]);
                        fwrite(jogada, 8, sizeof(char), fp );
                    }
                    else printf("Xeque-mate. Vitoria do preto!\n");
                    break;
                }
            }
        }
        ++cont;
    }
    liberarTab(tab); // free!
    fclose(fp);
    remove("xadrez.bin"); // fecha e deleta o arquivo

    return 0;
}
//lembrar o fclose e o free