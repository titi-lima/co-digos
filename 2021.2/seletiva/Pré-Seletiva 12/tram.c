#include <stdio.h>

int main() {
    int n, exit, enter, mincap=0, currcap=0;
    scanf("%d", &n);

    while(n--) {
        scanf("%d %d", &exit, &enter);
        currcap += enter-exit;
        if(currcap > mincap) mincap = currcap;
    }
        printf("%d\n", mincap);

    return 0;
}