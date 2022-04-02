#include <stdio.h>
#include <string.h>
int main() {
    int q, x, c, n, m, Q = 0, C = 0, N = 0, M = 0, cont = 0, contcaca = 0;
    scanf("%d %d %d %d %d", &q, &x, &c, &n, &m);
    if (q > 100) {
        q = 100;
    }
    if (x > 500) {
        x = 500;
    }
    if (c > 10) {
        c = 10;
    }
    if (n > 20) {
        n = 20;
    }
    if (m > 20) {
        m = 20;
    }
    char caca[n][m], nomes[c][1000], invertida[1000][1000], transposta[1000][1000], transpinvertida[1000][1000], elaaaa[5] = "YUKI";
    for (C = 0; C < c; ++C) {
        nomes[C][0] = '\0';
        scanf(" %[^\n]", &nomes[C][0]);
    }
    for (Q = 0; Q < q; ++Q) {
        for (N = 0; N < n; ++N) {
            caca[N][0] = '\0';
            scanf(" %[^\n]", caca[N]);
            //printf("N:%d\n", N);
        }
        //printf("test:%c\n", caca[0][(n*m)-1]);
        for (C = 0; C < c; ++C) {
            for (M = 0; M < m * n; ++M) {
                int q = strlen(&nomes[C][0]);
                //printf("%d\n", q);
                if ((strncasecmp(&nomes[C][0], &caca[0][M], q) == 0) && (M % m <= (M + q-1) % m && q <= m)) {
                    ++cont;
                    //printf("%d cont em normal\n", cont);
                }
                else if ((strncasecmp(&nomes[C][0], &caca[0][M], q) == 0)) {
                    //printf("%d mod %d <= (%d + %d) mod %d E %d <= %d\n", M, m, M, q, m, q, m);
                }
                //printf("prox linha\n");
            }
        }
        for (M = 0; M < m * n; ++M) {
            if ((strncasecmp(&caca[0][M], elaaaa, 4) == 0) && (M % m <= (M + 3) % m && 4 <= m)) {
                ++cont;
            }
        }
        //printf("M:%d\nN:%d\n", m, n);
        for (N = 0; N < n; ++N) {
            invertida[N][0] = '\0';
            for (M = 0; M < m; ++M) {
                invertida[N][M] = caca[N][m - M - 1];
                //printf("%c", invertida[N][M]);
            }
            //printf("\n");
        }
        //printf("\n");
        for (C = 0; C < c; ++C) {
            for (N = 0; N < n; ++N) {
                for (M = 0; M < m; ++M) {
                    int q = strlen(&nomes[C][0]);
                    if ((strncasecmp(&nomes[C][0], &invertida[N][M], q) == 0)) {
                        ++cont;
                    }
                }
            }
        }
        for (N = 0; N < n; ++N) {
            for (M = 0; M < m * n; ++M) {
                if ((strncasecmp(&invertida[N][M], elaaaa, 4) == 0)) {
                    ++cont;
                }
            }
        }
        for (M = 0; M < m; ++M) {
            transposta[M][0] = '\0';
            for (N = 0; N < n; ++N) {
                transposta[M][N] = caca[n - N - 1][m - M - 1];
            }
        }
        for (C = 0; C < c; ++C) {
            for (M = 0; M < m; ++M) {
                for (N = 0; N < n; ++N) {
                    int q = strlen(&nomes[C][0]);
                    if ((strncasecmp(&nomes[C][0], &transposta[M][N], q) == 0)) {
                        ++cont;
                    }
                }
            }
        }
        for (M = 0; M < m; ++M) {
            for (N = 0; N < m * n; ++N) {
                if ((strncasecmp(&transposta[M][N], elaaaa, 4) == 0)) {
                    ++cont;
                }
            }
        }
        for (M = 0; M < m; ++M) {
            transpinvertida[M][0] = '\0';
            for (N = 0; N < n; ++N) {
                transpinvertida[M][N] = transposta[M][n - N - 1];
            }
        }
        //printf("AQUI: %s\n", &transpinvertida[0][0]);
        for (C = 0; C < c; ++C) {
            for (M = 0; M < m; ++M) {
                for (N = 0; N < n; ++N) {
                    int q = strlen(&nomes[C][0]);
                    if ((strncasecmp(&nomes[C][0], &transpinvertida[M][N], q) == 0)) {
                        ++cont;
                        //printf("%s\n", &nomes[C][0]);
                    }
                }
            }
        }
        for (M = 0; M < m; ++M) {
            for (N = 0; N < n; ++N) {
                if ((strncasecmp(&transpinvertida[M][N], elaaaa, 4) == 0)) {
                    ++cont;
                }
            }
        }
        //printf("%d\n", cont);
        if (cont > x) {
            ++contcaca;
        }
        cont = 0;
    }
    printf("%d\n", q - contcaca);

    return 0;
}