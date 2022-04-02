#include <stdio.h>

void derivada(int *c, int *e) {
    *c = (*c) * (*e);
    if (*e != 0) {
        --*e;
    }
}

int main() {
    int n, c, e, flag=0;
    char v;
    scanf("%d", &n);
    while (n != 0) {
        for (int aux = 0; aux < n; ++aux) {
            scanf("%d", &c);
            scanf(" %c", &v);
            scanf("%d", &e);
            if(v!='0') {
                flag=1;
            }
            if (aux == 0 && n == 1) {
                printf("f'(%c)=0", v);
            }
            else if (aux == 0) {
                printf("f'(%c)=", v);
            }
            derivada(&c, &e);
            if (e != 0) {
                if (c > 0) {
                    printf("+%d%c^%d", c, v, e);
                } else if (c < 0) {
                    printf("%d%c^%d", c, v, e);
                }
            } else {
                if (c > 0) {
                    printf("+%d", c);
                } else if (c < 0) {
                    printf("%d", c);
                }
            }
        }
        if (flag == 0) {
            printf("0\n");
        }
        scanf("%d", &n);
        printf("\n");
        flag = 0;
    }

    return 0;
}