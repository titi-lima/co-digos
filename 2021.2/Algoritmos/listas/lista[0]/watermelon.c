#include <stdio.h>

int main() {
    int d;
    scanf("%d", &d);
    if(d>2 && d%2 == 0) {
        printf("YES\n");
    }
    else printf("NO\n");


    return 0;
}