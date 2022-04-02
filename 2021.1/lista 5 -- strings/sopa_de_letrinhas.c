#include <stdio.h>
#include <string.h>
int main() {
    char str[30], straux[30];
    scanf("%s", str);
    strcpy(straux, str);
    int n, k, t, aux, aux2, t_str = strlen(str), flag = 0, count = 0;
    scanf("%d", &n);
    char palavras[n][30];
    for (k = 0; k < n; ++k) {
        scanf("%s", palavras[k]);
    }
    for (k = 0; k < n; ++k) {
        t = strlen(palavras[k]);
        flag = 0;
        for (aux = 0; aux < t && flag != 2; ++aux) {
            flag = 0;
            for (aux2 = 0; aux2 < t_str && flag != 1; ++aux2) {
                flag = 2;
                if (strncmp(&palavras[k][aux], &str[aux2], 1) == 0) {
                    str[aux2] = '0';
                    flag = 1;
                }
            }
            if (flag == 2) { //nao encontrou letra, logo, nao encontrou palavra
                strcpy(str, straux);
            }
        }
        if (flag != 2) { //encontrou palavra
            strcpy(straux, str);
            ++count;
        }
    }
    printf("E possivel formar %d palavras com esse conjunto\n", count);

    return 0;
}