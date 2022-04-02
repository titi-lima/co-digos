#include <math.h>
#include <stdio.h>
#define eq 3  // quociente
#define er 2  // resto
#define en2 1 // termo a direita
#define en1 0 // termo a esquerda
int main() {

    int n1, n2, quociente, result, resto = 1, flag = 0, fl = 0, mdc, mat[4][10000], c = 0, qn1 = 1, k, v1, v2;
    float t = 0.00, T = 0.00;
    printf("Digite os dois inteiros para o MDC em ordem decrescente: ");
    scanf("%d %d", &n1, &n2);
    printf("Digite o resultado desejado pelo algoritmo: ");
    scanf("%d", &result);
    printf("\n");
    if (n1 % n2 == 0) {
        printf("faz na mao man, isso n vai rodar aqui n kkkkkkkkkkkkkkkkkkk\n");
        fl = 1;
    }
    while (resto != 0 && fl == 0) {
        quociente = n1 / n2;
        resto = n1 % n2;
        if (resto != 0) {
            printf("Algoritmo estendido: %d = %d.%d + %d -> ", n1, n2, quociente, resto);
            printf("%d = %d - %d.%d\n", resto, n1, n2, quociente);
            mat[en1][c] = n1;
            mat[en2][c] = n2;
            mat[er][c] = resto;
            mat[eq][c] = quociente;
            ++c;
            n1 = resto;
            quociente = n2 / n1;
            resto = n2 % n1;
            if (resto != 0) {
                printf("Algoritmo estendido: %d = %d.%d + %d -> ", n2, n1, quociente, resto);
                printf("%d = %d - %d.%d\n", resto, n2, n1, quociente);
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
                    printf("\nO MDC eh %d\n", mdc);
                }
            } else {
                printf("Algoritmo estendido: %d = %d.%d + %d -> ", n2, n1, quociente, resto);
                printf("%d = %d - %d.%d\n", resto, n2, n1, quociente);
                mat[en1][c] = n2;
                mat[en2][c] = n1;
                mat[er][c] = resto;
                mat[eq][c] = quociente;
                mdc = n1;
                printf("\nO MDC eh %d\n", mdc);
                flag = 1;
            }
        } else if (flag == 0) {
            printf("Algoritmo estendido: %d = %d.%d + %d - > ", n1, n2, quociente, resto);
            printf("%d = %d - %d.%d\n", resto, n1, n2, quociente);
            mat[en1][c] = n1;
            mat[en2][c] = n2;
            mat[er][c] = resto;
            mat[eq][c] = quociente;
            mdc = n2;
            printf("\nO MDC eh %d\n", mdc);
        }
    }
    if (result % mdc == 0) {
        printf("\n%d divide %d, logo, existe solucao inteira para a e b.\n", mdc, result);
        if (mat[er][c] == 0) {
            --c;
        }
        while (c != -1) {
            printf("%d = %d.(%d) - %d.(%d)\n", mdc, mat[en1][c], qn1, mat[en2][c], mat[eq][c]);
            mat[eq][c - 1] *= -1;
            k = -1 * qn1;
            qn1 = -1 * mat[eq][c];
            //pfv pare de ler o codigo, eu tb nao sei mais oq nada disso significa, so confia
            mat[eq][c - 1] = (mat[eq][c] * mat[eq][c - 1]) + k;
            --c;
        }
        ++c;
        k *= -1;
        mat[eq][c] *= -1;
        printf("%d = %d.(%d) + %d.(%d)\n", mdc, mat[en1][c], k, mat[en2][c], mat[eq][c]);
        k *= result / mdc;
        mat[eq][c] *= result / mdc;
        printf("\nSolucao inteira: %d = %d.(%d) + %d.(%d)\n", result, mat[en1][c], k, mat[en2][c], mat[eq][c]);
        if (k < 0) {
            printf("\nCaso o problema exija solucoes naturais, %d nao eh uma solucao valida.\n\nLogo, eh preciso achar um 't' tal que %d + (%d/MDC(%d,%d)).t > 0 e %d + (%d/MDC(%d,%d)).t > 0.\n\n", k, k, mat[en2][c], mat[en1][c], mat[en2][c], mat[eq][c], mat[en1][c], mat[en1][c], mat[en2][c]);
            float K = k;
            t = K * -1 * mdc / (mat[en2][c]);
            printf("Sabe-se que (MDC %d,%d) = %d, Com isso:\n", mat[en1][c], mat[en2][c], mdc);
            printf("\nDesenvolvendo %d + (%d/%d).t > 0, temos t > %d/%d -> t > %.2f.\n", k, mat[en2][c], mdc, k * -1, mat[en2][c] / mdc, t);
            K = mat[eq][c];
            T = K * mdc / (mat[en1][c]);
            printf("Desenvolvendo %d - (%d/%d).t > 0, temos t < %d/%d -> t < %.2f.\n", mat[eq][c], mat[en1][c], mdc, mat[eq][c], mat[en1][c] / mdc, T);
            if (floor(T - t) != 0) {
                v1 = t;
                v2 = T;
                if (T - t == 1 && v1 == t && v2 == T) {
                    printf("\nNao existem inteiros entre %.2f e %.2f, logo, esse problema tem solucao inteira, mas nao tem solucao natural.\n", t, T);
                } else
                    printf("\nExistem inteiros entre %.2f e %.2f, logo, esse problema tem solucao natural.\n", t, T);
                printf("Gostaria de ver todas as solucoes naturais? Digite S: ");
                char kkk;
                scanf(" %c", &kkk);
                if (kkk == 'S' || kkk == 's') {
                    for (v1 += 1; v1 < T; ++v1) {
                        int x, y;
                        printf("\nPara t=%d:\n", v1);
                        x = k + (mat[en2][c] * v1) / mdc;
                        y = mat[eq][c] - (mat[en1][c] * v1) / mdc;
                        printf("x = %d + (%d/%d).t -> x = %d + %d.%d -> x = %d\n", k, mat[en2][c], mdc, k, mat[en2][c] / mdc, v1, x);
                        printf("y = %d - (%d/%d).t -> y = %d - %d.%d -> y = %d\n", mat[eq][c], mat[en1][c], mdc, mat[eq][c], mat[en1][c] / mdc, v1, y);
                        printf("Ficaria: %d = %d.(%d) + %d.(%d)\n", result, mat[en1][c], x, mat[en2][c], y);
                    }
                }
            } else
                printf("\nNao existem inteiros entre %.2f e %.2f, logo, esse problema tem solucao inteira, mas nao tem solucao natural.\n", t, T);
        }

        else if (mat[eq][c] < 0) {
            printf("\nCaso o problema exija solucoes naturais, %d nao eh uma solucao valida.\n\nLogo, eh preciso achar um 't' tal que %d - (%d/MDC(%d,%d)).t > 0 e %d + (%d/MDC(%d,%d)).t > 0.\n\n", mat[eq][c], k, mat[en2][c], mat[en1][c], mat[en2][c], mat[eq][c], mat[en1][c], mat[en1][c], mat[en2][c]);
            float K = k;
            t = K / (mat[en2][c] * mdc);
            printf("Sabe-se que (MDC %d,%d) = %d, Com isso:\n", mat[en1][c], mat[en2][c], mdc);
            printf("\nDesenvolvendo %d - (%d/%d).t > 0, temos t < %d/%d -> t < %.2f.\n", k, mat[en2][c], mdc, k, mat[en2][c] / mdc, t);
            K = mat[eq][c];
            T = K * -1 / (mat[en1][c] * mdc);
            printf("Desenvolvendo %d + (%d/%d).t > 0, temos t > %d/%d -> t > %.2f.\n", mat[eq][c], mat[en1][c], mdc, -1*mat[eq][c], mat[en1][c] / mdc, T);
            if (floor(t - T) != 0) {
                v1 = t;
                v2 = T;
                if (t - T == 1 && v1 == t && v2 == T) {
                    printf("\nNao existem inteiros entre %.2f e %.2f, logo, esse problema tem solucao inteira, mas nao tem solucao natural.\n", T, t);
                } else // ARRUMAR AQUI
                    printf("\nExistem inteiros entre %.2f e %.2f, logo, esse problema tem solucao natural.\n", T, t);
                printf("Gostaria de ver todas as solucoes naturais? Digite S: ");
                char kkk;
                scanf(" %c", &kkk);
                if (kkk == 'S' || kkk == 's') {
                    //printf("%d %d\n", v1, T);
                    for (v2 += 1; v2 < t; ++v2) {
                        int x, y;
                        printf("\nPara t=%d:\n", v2);
                        x = k - (mat[en2][c] * v2) / mdc;
                        y = mat[eq][c] + (mat[en1][c] * v2) / mdc;
                        printf("x = %d - (%d/%d).t -> x = %d - %d.%d -> x = %d\n", k, mat[en2][c], mdc, k, mat[en2][c] / mdc, v2, x);
                        printf("y = %d + (%d/%d).t -> y = %d + %d.%d -> y = %d\n", mat[eq][c], mat[en1][c], mdc, mat[eq][c], mat[en1][c] / mdc, v2, y);
                        printf("Ficaria: %d = %d.(%d) + %d.(%d)\n", result, mat[en1][c], x, mat[en2][c], y);
                    }
                }
            } else
                printf("\nNao existem inteiros entre %.2f e %.2f, logo, esse problema tem solucao inteira, mas nao tem solucao natural.\n", T, t);
        }
    } else
        printf("\n%d nao divide %d, logo, nao existe solucao inteira para a e b.\n", mdc, result);

    return 0;
}