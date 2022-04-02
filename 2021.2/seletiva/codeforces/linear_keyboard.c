#include <stdio.h>
#include <string.h>

int main() {
    int qtd, aux, aux2, flag=0, pos[2], time=0;
    char str[51], tecla[27];

    scanf("%d", &qtd);
    while(qtd>0) {
        scanf(" %c", &tecla[0]);
        for(aux=1; aux<26; ++aux) {
            scanf("%c", &tecla[aux]);
        }
        scanf(" %s", str);
        for(aux=1; aux<strlen(str); ++aux) {
            for(aux2=0; flag!=2; ++aux2) {
                if(str[aux]==tecla[aux2]) {
                    ++flag;
                    pos[0] = aux2;
                }
                if(str[aux-1]==tecla[aux2]) {
                    ++flag;
                    pos[1] = aux2;
                }
                //printf("%c %c\n", str[aux], tecla[aux2]);
                //printf("%d\n", flag);
            }
            if(pos[1]-pos[0] < 0) time += (pos[0]-pos[1]);
            else time += (pos[1]-pos[0]);
            //printf("%d %d\n", pos[1], pos[0]);

            flag=0;
        }
        printf("%d\n", time);
        time=0;

        --qtd;
    }

 
}