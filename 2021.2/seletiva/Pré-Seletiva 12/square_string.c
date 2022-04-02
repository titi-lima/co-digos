#include <stdio.h>
#include <string.h>

int main() {
    int t, tam;
    char str[101];

    scanf("%d", &t);
    while(t--) {
        scanf(" %s", str);
        tam = strlen(str);
        if(tam % 2 != 0) {
            printf("NO\n");
        }
        else if(strncmp(str, &str[tam/2], tam/2) == 0) {
            printf("YES\n");
        }
        else printf("NO\n");
    }


    return 0;
}