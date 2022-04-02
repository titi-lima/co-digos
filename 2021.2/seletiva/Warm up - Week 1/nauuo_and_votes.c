#include <stdio.h>

int main() {
    int up, down, un;
    scanf("%d %d %d", &up, &down, &un);
    if(up>down+un) printf("+\n");
    else if(down>up+un) printf("-\n");
    else if(up==down && un==0) printf("0\n");
    else printf("?\n");
    return 0;
}