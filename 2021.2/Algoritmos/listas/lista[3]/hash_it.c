#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char array[16];
    int status;
} List[101];

struct Dictionary {
    int size;
    int cnt;
    List l;
    int (*h)(char*, struct Dictionary*, int);
};
typedef struct Dictionary Dictionary;

int h(char *data, Dictionary *d, int isInsert) {
    int key=0, j, tam, pos;
    tam = strlen(data);
    for(j=0; j<tam; ++j) {
        key+=data[j]*(j+1);
    }
    key = (19*key)%101;
    pos=key;
    if(isInsert) { // entra se for insert
        //printf("\n%s key %d status %d\n", data, key, d->l[key].status);
        for(j=0; j<20; ++j) { // primeiro checa se ele ja ta la. dps checa onde colocar
            key=(pos+j*j+23*j)%101;
            if(!strcmp(data, d->l[key].array) && d->l[key].status) {
                return -1;
            }
        }
        for(j=0; j<20; ++j) { // primeiro checa se ele ja ta la. dps checa onde colocar
            key=(pos+j*j+23*j)%101;
            //printf("\n%d\n", key);
            if(!d->l[key].status) {
                d->l[key].status=1;
                return key;
            }
        }
        return -1;
    }
    else { // entra se for remove
        j=0;
        while(j<20) { //enquanto tiver uma palavra. e se nao tiver uma palavra viva nessa primeira checagem mas ela estiver depois? obsoleto
            if(!strcmp(data, d->l[key].array) && d->l[key].status) {
                d->l[key].status = 0;
                return key;
            }
            else {
                //printf("key: %d, pos: %d, j: %d\n", key, pos, j);
                j++;
                key=(pos+j*j+23*j)%101;
            }
            //printf("%s ta tentando apagar; compara com %s, de key %d e status %d\n", data, d->l[key].array, key, d->l[key].status);
        } 
        return -1; //n tem ngm com essa palavra
    }
}

Dictionary *create_dict(int (*h)(char*, Dictionary*, int)) {
    Dictionary *d = NULL;
    d = (Dictionary*) malloc(sizeof(Dictionary));
    d->cnt = 0;
    d->h = h;
    d->size = 101;
    for(int i=0; i<101; ++i) {
        d->l[i].status = 0;
    }
    return d;
}

void clear_dict(Dictionary *d) {
    free(d); // limpa o dicionario
}

void insert(Dictionary *d) {
    char data[16];
    int j=0, i, flag=0;
    //printf("%s key %d status %p\n", data, &d->l[key]);
    do {
        if(scanf("%c", &data[j]) == EOF) {
            flag=1;
            break;
        }
        ++j;
    } while(data[j-1]!='\n');
    if(j>1 && flag!=1) data[j-1] = '\0';
    else if(flag==1) data[j]='\0';
    for(int k=0; k<j; ++k) if(data[k] == ' ') {
        data[k] = '\0';
        break;
    }
    if(data[0] == '\n' || data[0] == ' ' || data[0] == '\0') return;
    i = d->h(data, d, 1);
    //printf("s");
    if(i!=-1) {
        //printf("Entrou com a string %s!\n", data);
        strcpy(d->l[i].array, data);
        //printf("\n\naqui\n\n");
        d->l[i].status = 1;
        d->cnt++;
    }
}

void deletee(Dictionary *d) {
    int i, j=0, flag=0;
    char data[16];
    do {
        if(scanf("%c", &data[j]) == EOF) {
            flag=1;
            break;
        }
        ++j;
    } while(data[j-1]!='\n');
    if(j>1 && flag!=1) data[j-1] = '\0';
    else if(flag==1) data[j]='\0';
    for(int k=0; k<j; ++k) if(data[k] == ' ') {
        data[k] = '\0';
        break;
    }
    if(data[0] == '\n' || data[0] == ' ' || data[0] == '\0') return;
    i=d->h(data, d, 0);
    if(i!=-1) {
        d->l[i].array[0] = '\0';
        d->l[i].status = 0;
        d->cnt--;
    }
}

void print_dict(Dictionary *d) {
    int i;
    printf("%d\n", d->cnt);
    for(i=0; i<101; ++i) {
        if(d->l[i].status) printf("%d:%s\n", i, d->l[i].array);
    }
}

int main() {
    Dictionary *d = NULL;
    int n, n2;
    char com[5], aux[16];
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &n2);
        d = create_dict(&h);
        while(n2--) {
            scanf(" %c%c%c%c", &com[0], &com[1], &com[2], &com[3]);
            if(!strcmp(com, "ADD:")) {
                insert(d);
            }
            else if(!strcmp(com, "DEL:")) {
                deletee(d);
            }
            else scanf("%[^\n]", aux);
        }
        print_dict(d);
        clear_dict(d);
    }

    return 0;
}