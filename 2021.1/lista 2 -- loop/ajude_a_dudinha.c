#include <stdio.h>

int main() {
    long int min, max, k, x=2, y=2;
    int cont=0, cont2=0;
    int flag1 = 0, flag2=0, flag3=0;
    scanf("%ld %ld %ld", &min, &max, &k);

    if(min<3) {
        min = 3;
    }
    if(k==0) {
        flag1=1;
            while(min<=max) {
            while (x<=min) {
                //printf("roda2\n");
                if (min % x == 0 && x%2!=0) { // achou um divisor impar
                    //printf("roda3\n");
                    while(y<=x/2 && flag2!=1) { //checa se o divisor eh primo
                        if(x % y == 0) { // divisor n eh primo
                            flag2=1; //divisor n eh primo, n tem pq checar mais
                        }
                        else ++y;
                    }
                    y=2;
                    if (flag2 == 0) { // divisor eh primo
                        cont++; //aumenta contador de divisores primos impares
                    }
                    flag2=0;
                    ++x;
                }
                else ++x;
            }
            x=2;
            if(cont==k) {
                if(cont2==0) {
                    printf("%ld ", min);
                }
                ++cont2;
            }
            ++min;
            cont=0;
            }
    }
    if(cont2==0 && flag1==1) {
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }
    else if (flag1==1) printf("%d\n", cont2-1);

    while(min<max && flag1!=1) {

        //printf("roda1\n");
        while (x<=min/2 && flag3!=1) {
            //printf("roda2\n");
            if (min % x == 0 && x%2!=0 && flag3!=1) { // achou um divisor impar
                //printf("roda3\n");
                while(y<=x/2 && flag2!=1) { //checa se o divisor eh primo
                    if(x % y == 0) { // divisor n eh primo
                        flag2=1; //divisor n eh primo, n tem pq checar mais
                    }
                    else ++y;
                }
                y=2;
                if (flag2 == 0) { // divisor eh primo
                    if (min % (x*x) == 0) {
                        //printf("%ld\n", min);
                        flag3=1;
                    }
                    else cont++; //aumenta contador de divisores primos impares
                }
                flag2=0;
                ++x;
            }
            else if (flag3!=1) ++x;
        }
        x=2;
        if(cont==k || cont == 0 && min % 2 != 0 && k==1) {
            if(cont2==0 && flag3!=1) {
                printf("%ld ", min);
                ++cont2;
            }
            else if (flag3 != 1) ++cont2;
        }
        flag3=0;
        ++min;
        cont=0;
    }
    if(cont2==0 && flag1!=1) {
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }
    else if(flag1 != 1) printf("%d\n", cont2-1);


    return 0;
}