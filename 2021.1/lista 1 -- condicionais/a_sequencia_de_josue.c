#include <stdio.h>

int main () {
char n1, n2, n3;
    scanf("%c", &n1);
    scanf(" %c", &n2);
    scanf(" %c", &n3);
        if (n1 != 'A' && n1 != 'B' && n1 != 'C' && n1 != 'D' && n1 != 'E' && n1 != 'F' && n1 != 'G' && n1 != 'H' && n1 != 'I' && n1 != 'J' && n1 != 'K' && n1 != 'L' && n1 != 'M' && n1 != 'N' && n1 != 'O' && n1 != 'P' && n1 != 'Q' && n1 != 'R' && n1 != 'S' && n1 != 'T' && n1 != 'U' && n1 != 'V' && n1 != 'W' && n1 != 'X' && n1 != 'Y' && n1 != 'Z' || n2 != 'A' && n2 != 'B' && n2 != 'C' && n2 != 'D' && n2 != 'E'&& n2 != 'F' && n2 != 'G' && n2 != 'H' && n2 != 'I' && n2 != 'J' && n2 != 'K' && n2 != 'L' && n2 != 'M' && n2 != 'N' && n2 != 'O' && n2 != 'P' && n2 != 'Q' && n2 != 'R' && n2 != 'S' && n2 != 'T' && n2 != 'U' && n2 != 'V' && n2 != 'W' && n2 != 'X' && n2 != 'Y' && n2 != 'Z' || n3 != 'A' && n3 != 'B' && n3 != 'C' && n3 != 'D' && n3 != 'E'&& n3 != 'F' && n3 != 'G' && n3 != 'H' && n3 != 'I' && n3 != 'J' && n3 != 'K' && n3 != 'L' && n3 != 'M' && n3 != 'N' && n3 != 'O' && n3 != 'P' && n3 != 'Q' && n3 != 'R' && n3 != 'S' && n3 != 'T' && n3 != 'U' && n3 != 'V' && n3 != 'W' && n3 != 'X' && n3 != 'Y' && n3 != 'Z') {
            printf("Etiquetas erradas!\n");
        }
        else if (((n3 == n2+1) && (n2 == n1+1)) || ((n3 == n1+1) && (n1 == n2+1)) || ((n2 == n1+1) && (n1 == n3+1)) || ((n2 == n3+1) && (n3 == n1+1)) || ((n1 == n2+1) && (n2 == n3+1)) || ((n1 == n3+1) && (n3 == n2+1))) {
            if (n1=='A' || n1=='E' || n1=='I' || n1=='O' || n1=='U' || n2=='A' || n2=='E' || n2=='I' || n2=='O' || n2=='U' || n3=='A' || n3=='E' || n3=='I' || n3 == 'O' || n3 == 'U') {
                printf("Sequência quase perfeita.\n");
            }
            else printf ("Sequência perfeita.\n");
        }
        else if (((n3 == n2+2) && (n2 == n1+2)) || ((n3 == n1+2) && (n1 == n2+2)) || ((n2 == n1+2) && (n1 == n3+2)) || ((n2 == n3+2) && (n3 == n1+2)) || ((n1 == n2+2) && (n2 == n3+2)) || ((n1 == n3+2) && (n3 == n2+2))) {
            if (n1=='A' || n1=='E' || n1=='I' || n1=='O' || n1=='U' || n2=='A' || n2=='E' || n2=='I' || n2=='O' || n2=='U' || n3=='A' || n3=='E' || n3=='I' || n3 == 'O' || n3 == 'U') {
                printf("Bissequência quase perfeita.\n");
            }
            else printf ("Bissequência perfeita.\n");
        } 
        else if (((n3 == n2+3) && (n2 == n1+3)) || ((n3 == n1+3) && (n1 == n2+3)) || ((n2 == n1+3) && (n1 == n3+3)) || ((n2 == n3+3) && (n3 == n1+3)) || ((n1 == n2+3) && (n2 == n3+3)) || ((n1 == n3+3) && (n3 == n2+3))) {
            if (n1=='A' || n1=='E' || n1=='I' || n1=='O' || n1=='U' || n2=='A' || n2=='E' || n2=='I' || n2=='O' || n2=='U' || n3=='A' || n3=='E' || n3=='I' || n3 == 'O' || n3 == 'U') {
                printf("Trissequência quase perfeita.\n");
            }
            else printf ("Trissequência perfeita.\n");
        }
        else printf ("Só umas letras ai...\n");
    return 0;
        }