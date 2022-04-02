#include <stdio.h>
#include <math.h>
int main() {
    int dhigh = 0, dlow = 0, k, m=0, binario[8], low[4], high[4], inteiro;

    for(k=0; k<8; ++k) {
    scanf(" %d", &binario[k]);
    }
    for(k=0; k<4; ++k) {
        high[k] = binario[k];
    }
    for(k=3; k>=0; --k) {
        if(high[k]==1) {
            dhigh = dhigh + pow(2, m);
            ++m;
        }
        else
        ++m;
    }
    m=0;
    for(k=4; k<8; ++k) {
        low[m] = binario[k];
        ++m;
    }
    m=0;

    for(k=3; k>=0; --k) {
        if(low[k]==1) {
            dlow = dlow + pow(2, m);
            ++m;
        }
        else
        ++m;
    }
    m=0;
    //printf("d:%d\n", dlow);
    //printf("dh:%d\n", dhigh);

    //printf("d:%d\n", low);
    //printf("e:%d\n", high);
    while (dhigh!=15) {
        if (dhigh == 0) {
            for(k=0; k<4; ++k) {
                scanf("%d", &low[k]);
            }
            dlow = 0;
            m=0;
            for(k=3; k>=0; --k) {
                if(low[k]==1) {
                    dlow = dlow + pow(2, m);
                    ++m;
            }
                else ++m;
            }

            for(k=0; k<4; ++k) {
                scanf("%d", &high[k]);
            }
            dhigh=0;
            m=0;
            for(k=3; k>=0; --k) {
                if(high[k]==1) {
                dhigh = dhigh + pow(2, m);
                ++m;
                }
                else ++m;
            }
        }
        if(dhigh==2) {
            printf("O registrador tem os seguintes valores:\n");
            printf("High: %d\n", dhigh);
            printf("Low: %d\n", dlow);
            for(k=0; k<4; ++k) {
                scanf("%d", &high[k]);
            }
            dhigh=0;
            m=0;
            for(k=3; k>=0; --k) {
                if(high[k]==1) {
                dhigh = dhigh + pow(2, m);
                ++m;
                }
                else ++m;
            }
        }

        if(dhigh==5) {
            printf("%d\n", (dlow*dlow));
            for(k=0; k<4; ++k) {
                scanf("%d", &high[k]);
            }
            dhigh=0;
            m=0;
            for(k=3; k>=0; --k) {
                if(high[k]==1) {
                dhigh = dhigh + pow(2, m);
                ++m;
                }
                else ++m;
            }

        }

        if(dhigh==8) {
            printf("%X\n", dlow);
            for(k=0; k<4; ++k) {
                scanf("%d", &high[k]);
            }
            dhigh=0;
            m=0;
            for(k=3; k>=0; --k) {
                if(high[k]==1) {
                dhigh = dhigh + pow(2, m);
                ++m;
                }
                else ++m;
            }
        }

        if(dhigh==12) {
            scanf("%d", &inteiro);
            //printf("inteiro:%d\n", inteiro);
            //printf("dlow:%d\n", dlow);
            printf("%d\n", (dlow*inteiro));
            for(k=0; k<4; ++k) {
                scanf("%d", &high[k]);
            }
            dhigh=0;
            m=0;
            for(k=3; k>=0; --k) {
                if(high[k]==1) {
                dhigh = dhigh + pow(2, m);
                ++m;
                }
                else ++m;
            }
        }
        if(dhigh==15) {
            break;
        }
        else if (dhigh!=0 && dhigh!=2 && dhigh!=5 && dhigh!=8 && dhigh!=12 && dhigh!=15){
            printf("ERRO: A instrucao nao existe.\n");
            for(k=0; k<4; ++k) {
                scanf("%d", &high[k]);
            }   
            dhigh=0;
            m=0;
            for(k=3; k>=0; --k) {
                if(high[k]==1) {
                dhigh = dhigh + pow(2, m);
                ++m;
                }
                else ++m;
            }
        }
        
    }
    return 0;
}