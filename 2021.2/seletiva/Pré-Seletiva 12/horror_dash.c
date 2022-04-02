#include <stdio.h>

int main() {
    int n=0, greatest=0, c=0, aux, aux2, std;

    scanf("%d", &c);
    for(aux=1; aux<=c; ++aux) {
        scanf("%d", &n);
        printf("Case %d: ", aux);
        for(aux2=0; aux2<n; ++aux2) {
            scanf("%d", &std);
            if(std>greatest) greatest=std;
        }
        printf("%d\n", greatest);
        greatest=0;
    }
    return 0;
}