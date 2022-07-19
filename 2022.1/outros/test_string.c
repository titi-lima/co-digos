#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[10] = "eu";
    for (int i = 0; str[i]; i++) printf("%c", str[i]);

    return 0;
}