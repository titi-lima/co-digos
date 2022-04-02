#include <stdio.h>
#include <string.h>
int main() {
    char str1[10000], str2[10000];
    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);
    int s_str1 = strlen(str1), s_str2 = strlen(str2), cont = 0;
    for (int k = 0; k < s_str1; ++k) {
        if (strncmp(&str1[k], str2, s_str2) == 0) {
            ++cont;
        }
    }
    printf("%d\n", cont);
    return 0;
}