#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float temp;
    char fumaca;
} ambiente[100];

int main() {
    int c, n, nt=0, aux, aux2, media=0;
    ambiente ambiente;
    scanf("%d", &c);
    for(aux=0; aux<c; ++aux) {
        printf("TESTE %d\n", aux+1);
        scanf("%d", &n);
        nt+=n;
        for(aux2=nt-n; aux2<nt; ++aux2) {
            scanf("%d", &ambiente[aux2].id);
            scanf("%f", &ambiente[aux2].temp);
            scanf(" %c", &ambiente[aux2].fumaca);
            media+=ambiente[aux2].temp;
        }
        media/=n;
        for(aux2=nt-n; aux2<nt; ++aux2) {
            if(ambiente[aux2].temp > 1.15*media || ambiente[aux2].temp >= 40 || ambiente[aux2].fumaca == 'S') {
                printf("%d\n", ambiente[aux2].id);
            }
        }

        media=0;
    }
    return 0;
}