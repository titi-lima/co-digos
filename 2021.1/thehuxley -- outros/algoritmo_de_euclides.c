#include <math.h>
#include <stdio.h>
#define eq 3  // quociente
#define er 2  // resto
#define en2 1 // termo a direita
#define en1 0 // termo a esquerda
int main() {
    int k, i;
    scanf("%d", &k);
    for (i = 0; i < k; ++i) {
        int n1, n2, quociente, resto = 1, flag = 0, mdc, mat[4][10000], c = 0, qn1 = 1, fn1, fn2;
        scanf("%d %d", &n1, &n2);
        fn1 = n1;
        fn2 = n2;
        while (resto != 0) {
            quociente = n1 / n2;
            resto = n1 % n2;
            if (resto != 0) {
                //printf("Algoritmo estendido: %d = %d.%d + %d -> ", n1, n2, quociente, resto);
                //printf("%d = %d - %d.%d\n", resto, n1, n2, quociente);
                mat[en1][c] = n1;
                mat[en2][c] = n2;
                mat[er][c] = resto;
                mat[eq][c] = quociente;
                ++c;
                n1 = resto;
                quociente = n2 / n1;
                resto = n2 % n1;
                if (resto != 0) {
                    //printf("Algoritmo estendido: %d = %d.%d + %d -> ", n2, n1, quociente, resto);
                    //printf("%d = %d - %d.%d\n", resto, n2, n1, quociente);
                    mat[en1][c] = n2;
                    mat[en2][c] = n1;
                    mat[er][c] = resto;
                    mat[eq][c] = quociente;
                    ++c;
                    n2 = resto;
                    quociente = n1 / n2;
                    resto = n1 % n2;
                    if (resto == 0) {
                        mdc = n2;
                        --c;
                        printf("MDC(%d,%d) = %d\n", fn1, fn2, mdc);
                    }
                } else {
                    //printf("Algoritmo estendido: %d = %d.%d + %d -> ", n2, n1, quociente, resto);
                    //printf("%d = %d - %d.%d\n", resto, n2, n1, quociente);
                    mat[en1][c] = n2;
                    mat[en2][c] = n1;
                    mat[er][c] = resto;
                    mat[eq][c] = quociente;
                    mdc = n1;
                    printf("MDC(%d,%d) = %d\n", fn1, fn2, mdc);
                    flag = 1;
                }
            } else if (flag == 0) {
                //printf("Algoritmo estendido: %d = %d.%d + %d - > ", n1, n2, quociente, resto);
                //printf("%d = %d - %d.%d\n", resto, n1, n2, quociente);
                mat[en1][c] = n1;
                mat[en2][c] = n2;
                mat[er][c] = resto;
                mat[eq][c] = quociente;
                mdc = n2;
                printf("MDC(%d,%d) = %d\n", fn1, fn2, mdc);
            }
        }
    }
    return 0;
}