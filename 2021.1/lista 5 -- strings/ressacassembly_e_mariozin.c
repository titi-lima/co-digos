#include <stdio.h>
#include <string.h>
int main() {
    int d, aux;
    scanf("%d", &d);
    for (aux = 0; aux < d; ++aux) {
        char str[11];
        scanf(" %[^\n]", str);
        if (strncmp(str, "mov", 3) == 0) {
            printf("%c = %c\n", str[4], str[7]);
        } else if (strncmp(str, "add", 3) == 0) {
            printf("%c += %c\n", str[4], str[7]);
        } else if (strncmp(str, "sub", 3) == 0) {
            printf("%c -= %c\n", str[4], str[7]);
        } else if (strncmp(str, "and", 3) == 0) {
            printf("%c = %c & %c\n", str[4], str[4], str[7]);
        }
    }

    return 0;
}