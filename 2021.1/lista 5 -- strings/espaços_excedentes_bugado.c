#include <stdio.h>
#include <string.h>
int main() {
    char str[301], str2[301];
    scanf(" %[^\n]", str);
    int q = strlen(str), Q = q, aux, flag = 0;
    for (Q = 0; Q < q; ++Q) {
        if (str[Q] != ' ') {
            strncat(str2, &str[Q], 1);
            flag = 0;
        } else if (flag != 1) {
            strcat(str2, " ");
            flag = 1;
        }
    }
    for (int c = 6; str2[c] != '\0'; c++) {
        printf("%c", str2[c]);
    }

    return 0;
}