#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(0));
    char str[100001];
    int com, s, n=25, k;
    sprintf(str, "%d", n);
    printf("%s\n", str);
    while(n--) {
        com = rand()%3;
        s = rand()%2;
        k = rand();
        switch (com) {
            case 1: {
                if(s==0) printf("insert %d\n", k);
                else printf("insert %d\n", k*-1);
                break;
            }
            case 2: {
                if(s==0) printf("getMin %d\n", k);
                else printf("getMin %d\n", k*-1);
                break;
            }
            case 0: {
                printf("removeMin\n");
                break;
            }
        }
    }
    return 0;
}