#include <stdio.h>
int main () {
int a, b, x=2, ab, abc, cont=0;
    scanf("%d %d", &a, &b);
    
    if (a>b) {
        goto end;
    }
    if ((a<2) && (b>2)) {
        ++cont;
    }
    if (a>2000) {
        goto end;
    }
    if (b>2000) {
        goto end;
    }
    b=(b+1);
    while ((x<=b/2)&&(b>a)) {
        if (b % x == 0) {
            ++b;
            x=2;
        }
        else ++x;
    }
    goto meio;

    inicio:
    if (b<=a) {
        goto end;
    }
    while ((x<=b/2)&&(b>a)) {
        if (b % x == 0) {
            --b;
            x=2;
        }
        else ++x;
    }
    meio:
    x=2;
    ab=(b-1);
    while ((x<=ab/2)&&(ab>=a)) {
        if (ab % x == 0) {
            --ab;
            x=2;
        }
        else ++x;
    }
    x=2;
    abc=(ab-1);
    while ((x<=abc/2) && (abc>2)) {
        if (abc % x == 0) {
            --abc;
            x=2;
        }
        else ++x;
    }
    if ((((abc+b)/2)==ab) && (abc>2)) {
        cont=cont+1;
        b=(b-1);
        x=2;
       // printf("%d\n", ab);
        if ((ab % 2 == 0) || (ab<a)) {
            --cont;
            goto inicio;
        }
        goto inicio;
    }
    else {
        b=(b-1);
        x=2;
        goto inicio;
        end:
    printf("%d\n", cont);
    }
    return 0;
}