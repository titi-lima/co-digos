#include <stdio.h>
#include <string.h>

int main() {
    int aux=1, flag=0, aux2=0;
    char str1[200001], str2[200001];
    scanf(" %s %s", str1, str2);
    if(strcmp(str1, str2)==0) { // se for instantaneamente igual, nao precisa operar
        printf("0\n");
        return 0;
    }
    if(strcmp(&str1[strlen(str1)-1], &str2[strlen(str2)-1]) != 0) { // se o ultimo caracter for diferente, vai ser preciso operar ate o fim
        printf("%lu\n", strlen(str1)+strlen(str2));
        return 0;
    }
    if(strlen(str1) > strlen(str2)) {
        while(strcmp(&str1[strlen(str1)-aux], &str2[strlen(str2)-aux]) == 0) {
            //printf("c: %c ", str1[strlen(str1)-aux]);
            if(strcmp(&str1[strlen(str1)-strlen(str2)+aux2], &str2[aux2]) == 0) {
                if(strcmp(&str1[strlen(str1)-strlen(str2)+aux2-1], &str2[aux2-1]) == 0 && strlen(str1)-strlen(str2)+aux2>0) --aux2;
                printf("%lu\n", strlen(str1)-strlen(str2)+2*aux2);
                return 0;
            }
            else aux2+=2;
            if(aux>strlen(str1) || aux> strlen(str2)) break;
            else aux+=2;
        }
    }
    else {
        while(strcmp(&str1[strlen(str1)-aux], &str2[strlen(str2)-aux]) == 0) {
            //printf("%c %c\n", str1[aux2], str2[strlen(str2)-strlen(str1)+aux2]);
            if(strcmp(&str1[aux2], &str2[strlen(str2)-strlen(str1)+aux2]) == 0) {
                if(strcmp(&str2[strlen(str2)-strlen(str1)+aux2-1], &str1[aux2-1]) == 0 && strlen(str2)-strlen(str1)+aux2-1>0) --aux2;
                //printf("%c %c\n", str2[strlen(str2)-strlen(str1)+aux2-1], str1[aux2-1]);
                printf("%lu\n", strlen(str2)-strlen(str1)+2*aux2);
                return 0;
            }
            else aux2+=2;
            if(aux>strlen(str1) || aux> strlen(str2)) break;
            else aux+=2;
        }
    }
    if(strcmp(&str1[strlen(str1)-(aux-1)], &str2[strlen(str2)-(aux-1)]) != 0) --aux;
    printf("%lu\n", strlen(str1)+strlen(str2)-2*(aux-1));
    return 0;
}