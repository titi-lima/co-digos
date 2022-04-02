#include <stdio.h>

int main() {
    int k, aux, budget, sum=0, c;
    scanf("%d %d", &c, &budget);

    for(aux=0; aux<c; ++aux) {
        scanf("%d", &k);
        sum+=k;
    }
    if(sum<budget) printf("More funding required\n");
    else if(sum>budget) printf("Success\n");
    else printf("Just enough\n");
    return 0;
}