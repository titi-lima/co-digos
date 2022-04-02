#include <stdio.h>
#include <string.h>
int main() {
    char str[10000];
    scanf(" %[^\n]", str);
    int t = strlen(str);
    for (int aux = 0; aux < t; ++aux) {
        if (str[aux] == '0') {
            if ((aux == 0 && aux != 1) || str[aux - 2] == '.') {
                str[aux] = 'O';
            } else
                str[aux] = 'o';
        } else if (str[aux] == '1') {
            if ((aux == 0 && aux != 1) || str[aux - 2] == '.') {
                str[aux] = 'I';
            } else
                str[aux] = 'i';
        } else if (str[aux] == '2') {
            if ((aux == 0 && aux != 1) || str[aux - 2] == '.') {
                str[aux] = 'U';
            } else
                str[aux] = 'u';
        } else if (str[aux] == '4') {
            if ((aux == 0 && aux != 1) || str[aux - 2] == '.') {
                str[aux] = 'A';
            } else
                str[aux] = 'a';
        } else if (str[aux] == '5') {
            if ((aux == 0 && aux != 1) || str[aux - 2] == '.') {
                str[aux] = 'E';
            } else
                str[aux] = 'e';
        } else if ((str[aux] >= 'a' && str[aux] <= 'z') && ((aux == 0 && aux != 1) || str[aux - 2] == '.')) {
            char c = str[aux] - 32;
            str[aux] = c;
        }
    }
    printf("%s\n", str);

    return 0;
}