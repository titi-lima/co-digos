#include <stdio.h>
#include <stdlib.h>

// nesse codigo, o header eh um node vazio

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node *curr, struct Node *tail, int data) { // cria um node novo, retorna o ponteiro para esse node
    struct Node* temp = NULL;
    temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp == NULL) {
        printf("Erro na alocacao.\n");
        exit(1);
    }
    temp->data = data;
    temp->next = curr->next;
    if(temp->next == NULL) { // checa se o node criado ta na ultima posicao. se sim, sera o novo tail
        tail = temp;
    }
    return temp;
}

struct Node* delete(struct Node *curr) { // remove o node apontado pelo cursor, retorna o ponteiro para o next desse node removido
    struct Node *temp = curr->next->next; // cria um ponteiro para o q era o proximo node
    free(curr->next);
    return temp;
}

void count(struct Node *head, int data) {
    int cont=0;
    struct Node *temp = head->next; //o header eh vazio, faz sentido já iniciar como o próximo node
    while(temp != NULL) { // para quando chegar no fim
        if(temp->data == data) {
            ++cont;
        }
        temp = temp->next;
    }
    printf("%d\n", cont);
}

struct Node* prev(struct Node *curr, struct Node *head) { //retorna o novo cursor
    if(curr!=head) {
        struct Node *temp = head->next;
        while(curr != temp->next) {
            temp = temp->next;
        }
        return temp;
    }
    else return curr;
}

struct Node* next(struct Node *curr) { //retorna o novo cursor
    if(curr->next->next != NULL) {
        curr = curr->next; // garante q ele n ta empurrando depois do tail
    }
    return curr;
}

void clear(struct Node *head) {
    struct Node *temp = NULL;
    struct Node *curr = head;
    do {
        temp = curr->next;
        free(curr);
        curr = temp;
    } while(temp->next != NULL);
}

int main() {
    int cont=0, a, b, aux, data, tam=0, aux2;
    char str[7];
    struct Node *head = NULL;
    struct Node *curr = NULL;
    struct Node *tail = NULL;
    head = (struct Node*) malloc(sizeof(struct Node));
    head->next = NULL;
    curr = head;
    tail = head;

    scanf("%d", &a);

    for(aux = 0; aux < a; ++aux) {
        scanf("%d", &b);
        printf("Caso %d:\n", aux+1);
        for(aux2 = 0; aux2 < b; ++aux2) {
            scanf(" %s", str);
            switch(str[0]) {
                case 'i': {
                    scanf("%d", &data);
                    ++tam;
                    curr->next = insert(curr, tail, data);
                    break;
                }
                case 'r': {
                    --tam;
                    curr->next = delete(curr);
                    break;
                }
                case 'c': {
                    scanf("%d", &data);
                    count(head, data);
                    break;
                }
                case 'p': {
                    curr = prev(curr, head);
                    break;
                }
                case 'n': {
                    curr = next(curr);
                    break;
                }
            }
        }
    }


    clear(head);
    return 0;
}