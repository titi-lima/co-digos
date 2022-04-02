#include <stdio.h>

void maior(int *p, int *b) {
    for (int k = 0; k < 6; ++k) {
        if (*b < *(p + k)) {
            *b = *(p + k);
        }
    }
}
void menor(int *p, int *s) {
    for (int k = 0; k < 6; ++k) {
        if (*s > *(p + k)) {
            *s = *(p + k);
        }
    }
}

int main() {
    int array[6];
    int b = 0, s = 1000000, *p = array;
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &array[i]);
    }
    maior(p, &b);
    menor(p, &s);
    printf("%d\n", s);
    printf("%d\n", b);

    return 0;
}