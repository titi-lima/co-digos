#include <stdio.h>

int main() {
    int d1, d2, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &d1, &d2, &x1, &y1, &x2, &y2);
    if(x1+x2 <= d1 && y1 <= d2 && y2 <= d2 || x1+x2 <= d2 && y1 <= d1 && y2 <= d1 || x1+y2 <= d1 && y1 <= d2 && x2 <= d2 || x1+y2 <= d2 && y1 <= d1 && x2 <= d1 || x2+y1 <= d1 && y2 <= d2 && x1 <= d2 || x2+y1 <= d2 && y2 <= d1 && x1 <= d1 || y1+y2 <= d1 && x1 <= d2 && x2 <= d2 || y1+y2 <= d2 && x1 <= d1 && x2 <= d1 ) {
        printf("S\n");
    }
    else printf("N\n");

    return 0;
}