#include <stdio.h>
int main () {
    int n;
    scanf("%d", &n);
    if (n==0) {
        printf("Vazia\n");
    }
    int m1[n][n], m2[n][n], m3[n][n];
    for (int k=0; k<n; ++k) {
        for (int j=0; j<n; ++j) {
            scanf("%d", &m1[k][j]);
        }
    }
    for(int k=0; k<n; ++k) {
        for(int j=0; j<n; ++j) {
            scanf("%d", &m2[k][j]);
        }
    }
    for(int k=0; k<n; ++k) {
        for(int j=0; j<n; ++j) {
            m3[k][j] = ((m2[k][j])+(m1[k][j]));
            printf("%d\n", m3[k][j]);
        }
    }

    return 0;
}