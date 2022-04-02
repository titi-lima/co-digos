#include <stdio.h>
int main() {
    int n1, n2, i=0, m, cont=0, flag;
    scanf("%d %d", &n1, &n2);
    int checagem[n1], elementos[1000], k=n1;
    for(n1=0; n1<k; ++n1) {
        scanf("%d", &checagem[n1]);
    }
    while(cont<n2) {
        flag=0;
        scanf("%d", &elementos[i]);
        for(k=0; k<n1 && flag==0; ++k) {
            if (elementos[i] == checagem[k]) {
                flag=1;
            }
        }
        if (flag==0) {
            ++cont;
        }
        ++i;
    }
    int imenosum = (i-1), imaisum = (i+1), x, printar[i];
    k=i;
    m=n1;
    k=i;
    for(i=0; i<k; ++i) {
        imenosum = (i-1), imaisum = (i+1);
        flag=0;

        if(i==0) {
            x = elementos[0];
        }
        else if (i==(k-1)) {
            x = elementos[i]*elementos[imenosum];
        }
        else {
        x = ((elementos[i]*elementos[imenosum])-elementos[imaisum]);
        }

        for(n1=0; n1<m && flag==0; ++n1) {
            if(x-checagem[n1] == 2*x || x-checagem[n1] == 0) {
                printar[i] = x;
                flag=1;
            }
        }
        if (flag!=1) {
            printar[i] = x;
        }
    }
       
    k=i;
    imaisum = (i+1);
    for(i=0; i<k; ++i) {
    if (printar[i]<0) {
        printar[i]=(printar[i]*-1);
    }
    }
    for(i=0; i<k; ++i) {
        imaisum=(i+1);
        while (imaisum<k) {
         if (printar[i]>printar[imaisum] && printar[i] != -1914 && printar[imaisum]!=-1914) {
            x = printar[i];
            printar[i] = printar[imaisum];
            printar[imaisum] = x;
            ++imaisum;
         }
         else imaisum++;
        }
    }
    for(i=0; i<k; ++i) {
        flag=0;
        for(n1=0; n1<m && flag==0; ++n1) {
            flag=0;
            x = printar[i];
            if(x-checagem[n1] == (2*x) || x == checagem[n1]) {
                printar[i] = -1914;
                flag=1;
            }
        }
        
    }
    for(i=0; i<k; ++i) {
        if (printar[i] == -1914) {
            printf("DELETADO ");
        }
        else if (printar[i]<0) {
            printar[i]=(printar[i]*-1);
            printf("%d ", printar[i]);
        }
        else printf("%d ", printar[i]);
    }




    return 0;
}