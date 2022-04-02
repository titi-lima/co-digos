#include <stdio.h>
int main () {
    int id1, p1, total1, id2, p2, total2, id3, p3, total3, id4, p4, total4, id5, p5, total5, soma_inicial, soma_final;
    scanf("%d", &id1);
    scanf("%d", &p1);
    scanf("%d", &id2);
    scanf("%d", &p2);
    scanf("%d", &id3);
    scanf("%d", &p3);
    scanf("%d", &id4);
    scanf("%d", &p4);
    scanf("%d", &id5);
    scanf("%d", &p5);
    scanf("%d", &soma_inicial);
        if ((id1 %6 == 0) || (id1 %10 == 0) || (id1 %14 == 0)) {
            total1 = (id1*p1*2);
        }
        else if (((p1*id1) %2 != 0) && ((id1*p1) %11 == 0) || ((p1*id1) %2 != 0) && ((id1*p1) %13 == 0) || ((p1*id1) %2 != 0) && ((id1*p1) %17 == 0) || ((p1*id1) %2 != 0) && ((id1*p1) %19 == 0)) {
            total1 = (id1*p1/2);
        }
        else if ((id1 %34 == 0)) {
            total1 = 0;
        }
        else total1 = id1*p1; {
        }
        if ((id2 %6 == 0) || (id2 %10 == 0) || (id2 %14 == 0)) {
            total2 = (id2*p2*2);
        }
        else if (((p2*id2) %2 != 0) && ((id2*p2) %11 == 0) || ((p2*id2) %2 != 0) && ((id2*p2) %13 == 0) || ((p2*id2) %2 != 0) && ((id2*p2) %17 == 0) || ((p2*id2) %2 != 0) && ((id2*p2) %19 == 0)) {
            total2 = (id2*p2/2);
        }
        else if ((id2 %34 == 0)) {
            total2 = 0;
        }
        else total2 = id2*p2; {
        }
        if ((id3 %6 == 0) || (id3 %10 == 0) || (id3 %14 == 0)) {
            total3 = (id3*p3*2);
        }
        else if (((p3*id3) %2 != 0) && ((id3*p3) %11 == 0) || ((p3*id3) %2 != 0) && ((id3*p3) %13 == 0) || ((p3*id3) %2 != 0) && ((id3*p3) %17 == 0) || ((p3*id3) %2 != 0) && ((id3*p3) %19 == 0)) {
            total3 = (id3*p3/2);
        }
        else if ((id3 %34 == 0)) {
            total3 = 0;
        }
        else total3 = id3*p3; {
        }
        if ((id4 %6 == 0) || (id4 %10 == 0) || (id4 %14 == 0)) {
            total4 = (id4*p4*2);
        }
        else if (((p4*id4) %2 != 0) && ((id4*p4) %11 == 0) || ((p4*id4) %2 != 0) && ((id4*p4) %13 == 0) || ((p4*id4) %2 != 0) && ((id4*p4) %17 == 0) || ((p4*id4) %2 != 0) && ((id4*p4) %19 == 0)) {
            total4 = (id4*p4/2);
        }
        else if ((id4 %34 == 0)) {
            total4 = 0;
        }
        else total4 = id4*p4; {
        }
        if ((id5 %6 == 0) || (id5 %10 == 0) || (id5 %14 == 0)) {
            total5 = (id5*p5*2);
        }
        else if (((p5*id5) %2 != 0) && ((id5*p5) %11 == 0) || ((p5*id5) %2 != 0) && ((id5*p5) %13 == 0) || ((p5*id5) %2 != 0) && ((id5*p5) %17 == 0) || ((p5*id5) %2 != 0) && ((id5*p5) %19 == 0)) {
            total5 = (id5*p5/2);
        }
        else if ((id5 %34 == 0)) {
            total5 = 0;
        }
        else total5 = id5*p5; {
        }
        soma_final = (total1 + total2 + total3 + total4 + total5);
        if (soma_final == soma_inicial) {
            printf("barra limpa, khan\n");
        }
        else printf("UEPAAA TEMOS UM RATINHO\n");
    return 0;
}