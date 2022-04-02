#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int pstate;
    int qstate;
    int sstate;
    int state;
} Elementos;

int main() {
    int n, type, fstack=1, fqueue=1, fpqueue=1, k, j, auxqueue=0, auxstack=0, fimpossible=1, flag=0;
    Elementos *elemento = NULL;
    int flag2=0, flag3=0, flag4=0;
    while(scanf("%d", &n) != EOF) {
        flag2=0;
        flag=0;
        elemento = (Elementos *)realloc(elemento, n*sizeof(Elementos));
        for(k=0; k<n; ++k) {
            scanf("%d %d", &type, &elemento[k].num);
            if(flag3==0) {
                if(type == 2) {
                    flag2=1;
                    elemento[k].state=0;
                    elemento[k].qstate=0;
                    elemento[k].pstate=0;
                    elemento[k].sstate=0;
                    fimpossible=1;
                    for(j=0; j<k; ++j) {
                        //printf("a %d %d %d, %d\n", elemento[k].num, elemento[j].num, elemento[j].state, fimpossible);
                        //printf("%d %d\n", j, k);
                        if(elemento[k].num == elemento[j].num && elemento[j].state == 1) {
                            //ele nao pega objeto do meio
                            elemento[j].state=0;
                            fimpossible=0;
                            break;
                        }
                    }
                    if(fimpossible==1 && flag==0) {
                        printf("impossible\n");
                        flag=1;
                        fqueue=1;
                        fstack=1;
                        fpqueue=1;
                        flag3=1;
                        //printf("fpqueue resetada para 1\n");
                        auxqueue=0;
                        continue;
                    }
                    if(fpqueue == 1) {
                        //printf("\n");
                        for(j=0; j<k; ++j) {
                            //printf("a %d %d %d\n", elemento[k].num, elemento[j].num, elemento[j].pstate);
                            if(elemento[k].num < elemento[j].num && elemento[j].pstate == 1) {
                                //printf("\n%d %d %d\n", elemento[k].num, elemento[j].num, elemento[j].pstate);
                                //printf("IHHHHHH\n");
                                fpqueue=0;
                            }
                            else if(elemento[k].num == elemento[j].num && elemento[j].pstate == 1 && flag4==0) {
                                elemento[j].pstate = 0;
                                flag4=1;
                            }
                        }
                        flag4=0;
                        fimpossible=0;
                    }
                    if(fqueue==1) {
                        //printf("el: %d %d %d %d\n", elemento[auxqueue].num, elemento[k].num, elemento[auxqueue].qstate, auxqueue);
                        if(elemento[auxqueue].num != elemento[k].num && elemento[auxqueue].qstate == 1) fqueue = 0;
                        else {
                            elemento[auxqueue].qstate = 0;
                            while(elemento[auxqueue].qstate!=1 && auxqueue<k+1 && auxqueue<n-1) ++auxqueue;
                        }
                        fimpossible=0;
                    }
                    //printf("test\n");
                    if(fstack==1) {
                        //printf("%d %d", elemento[auxstack].num, elemento[k].num);
                        if(elemento[auxstack].num != elemento[k].num && elemento[auxstack].sstate == 1) fstack = 0;
                        else {
                            elemento[auxstack].sstate=0;
                            while(elemento[auxstack].sstate!=1 && auxstack>0) {
                                //printf("el %d %d %d\n", elemento[auxstack].num, elemento[k].num, auxstack);
                                if(auxstack>0) --auxstack;
                                //else while(1);
                            }
                        }
                        fimpossible=0;
                    }
                }
                else {
                    elemento[k].state=1;
                    elemento[k].pstate=1;
                    elemento[k].qstate=1;
                    elemento[k].sstate=1;
                    auxstack=k;
                }
            }
        }
        if(fimpossible!=1 && flag==0 || flag2==0) {
            if(fqueue==1 && fstack==1 || fqueue==1 && fpqueue==1 || fstack==1 && fpqueue==1) printf("not sure\n");
            else if(fqueue==1) printf("queue\n");
            else if(fpqueue==1) printf("priority queue\n");
            else if(fstack==1) printf("stack\n");
            else printf("impossible\n");
            //printf("%d %d %d %d %d %d\n", fimpossible, flag, flag2, fqueue, fpqueue, fstack);
            //printf("%d\n", flag2);
        }
        fqueue=1;
        fstack=1;
        fpqueue=1;
        auxqueue=0;
        fimpossible=1;
        flag3=0;
    }
    free(elemento);

    return 0;
}