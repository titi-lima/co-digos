#include <stdio.h>
int main () {
int d1, m1, y1, d2, m2, y2, cont=0;
    scanf("%d/%d/%d", &d1, &m1, &y1);
    scanf("%d/%d/%d", &d2, &m2, &y2);

    if (y2<y1) {
        while (y2!=y1) {
            if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0)) && (m2<3) || (y2==(y1-1) && (m2>2) && ((y1 % 400 == 0) || (y1 % 4 == 0) && (y1 % 100 !=0)))) {
                cont=(cont-366);
                ++y2;
            }
            else {
                cont=(cont-365);
                ++y2;
            }
        }
        if (m2<m1) {
            while (m2!=m1) {
                if (m2==2) {
                    if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0))) {
                        cont=(cont-29);
                        ++m2;
                    }
                    else {
                        cont=(cont-28);
                        ++m2;
                    }
                }
                else if ((m2==1) || (m2==3) || (m2==5) || (m2==7) || (m2==8) || (m2==10) || (m2==12)) {
                    cont=(cont-31);
                    ++m2;
                }
                else {
                    cont=(cont-30);
                    ++m2;
                }
            }
            if (d2<d1) {
                while (d2!=d1) {
                    --cont;
                    ++d2;
                }
                printf("%d\n", cont);
            }
            else {
                while (d2!=d1) {
                ++cont;
                --d2;
                }
                printf("%d\n", cont);
            }
        }
        else {
            while (m2!=m1) {
                if (m2==2) {
                    if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0))) {
                        cont=(cont+29);
                        --m2;
                    }
                    else {
                        cont=(cont+28);
                        --m2;
                    }
                }
                else if ((m2==1) || (m2==3) || (m2==5) || (m2==7) || (m2==8) || (m2==10) || (m2==12)) {
                    cont=(cont+31);
                    --m2;
                }
                else {
                    cont=(cont+30);
                    --m2;
                }
            }
            if (d2<d1) {
                while (d2!=d1) {
                    --cont;
                    ++d2;
                }
                printf("%d\n", cont);
            }
            else {
                while (d2!=d1) {
                ++cont;
                --d2;
                }
                printf("%d\n", cont);
            }
        } 
    } 
    else {
        if (((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0))) && ((m2<3) && (y2-y1)<6) && (y1!=y2)) {
            --cont; 
        }
        if (((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 !=0))) && ((m2>3) && (y2-y1==5))) {
            ++cont;
        }
        while (y2!=y1) {
            if (((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0))) || (y2==(y1+1) && (m2<3) && ((y1 % 400 == 0) || (y1 % 4 == 0) && (y1 % 100 !=0)))) {
                cont=(cont+366);
                --y2;
            }
            else {
                cont=(cont+365);
                --y2;
            }
        }
        if (m2<m1) {
            while (m2!=m1) {
                if (m2==2) {
                    if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0))) {
                        cont=(cont-29);
                        ++m2;
                    }
                    else {
                        cont=(cont-28);
                        ++m2;
                    }
                }
                else if ((m2==1) || (m2==3) || (m2==5) || (m2==7) || (m2==8) || (m2==10) || (m2==12)) {
                    cont=(cont-31);
                    ++m2;
                }
                else {
                    cont=(cont-30);
                    ++m2;
                }
            }
            if (d2<d1) {
                while (d2!=d1) {
                    --cont;
                    ++d2;
                }
                printf("%d\n", cont);
            }
            else {
                while (d2!=d1) {
                ++cont;
                --d2;
                }
                printf("%d\n", cont);
            }
        }
        else {
            while (m2!=m1) {
                if (m2==3) {
                    if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 !=0))) {
                        cont=(cont+29);
                        --m2;
                    }
                    else {
                        cont=(cont+28);
                        --m2;
                    }
                }
                else if ((m2==2) || (m2==4) || (m2==6) || (m2==8) || (m2==9) || (m2==11) || (m2==1)) {
                    cont=(cont+31);
                    --m2;
                }
                else {
                    cont=(cont+30);
                    --m2;
                }
            }
            if (d2<d1) {
                while (d2!=d1) {
                    --cont;
                    ++d2;
                }
                printf("%d\n", cont);
            }
            else {
                while (d2!=d1) {
                ++cont;
                --d2;
                }
                printf("%d\n", cont);
            }
        } 
    }
    return 0;
}