#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

typedef struct Node Node;

typedef struct {
    Node *head;
    Node *curr;
    Node *tail;
} Link;

void insert(Link *l, char data) { // cria um node novo, retorna o ponteiro para esse node
    Node* temp = NULL;
    temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = l->curr->next;
    if(temp->next == NULL) { // checa se o node criado ta na ultima posicao. se sim, sera o novo tail
        //printf("lol\n");
        l->tail = temp;
    }
    l->curr->next = temp;
    l->curr = l->curr->next;
}

void print(Link *l) {
    Node* temp = NULL;
    temp = l->head->next;
    while(temp->next!=NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("%c\n", temp->data);
}

void clear(Link *l) {
    Node *temp = NULL;
    Node *curr = l->head; // mantem o header vazio alocado
    do {
        temp = curr->next;
        free(curr);
        curr = temp;
    } while(temp->next != NULL);
}

int main() { // le a linha toda, passa cada char como parametro
    int k, tam;
    char c, str[100000];
    Link *l = (Link*)malloc(sizeof(Link));
    while(scanf(" %[^\n]", str) != EOF) {
        l->head = (Node*)malloc(sizeof(Node));
        l->curr = (Node*)malloc(sizeof(Node));
        l->tail = (Node*)malloc(sizeof(Node));
        l->head->next = NULL;
        l->curr = l->head;
        l->tail = l->head;
        tam = strlen(str);
        for(k=0; k<tam; ++k) {
            if(str[k] == '[') { // retorna curr para o head
                l->curr = l->head;
            }
            else if(str[k] == ']') { // vai para o tail
                l->curr = l->tail;
            }
            else insert(l, str[k]);
        }
        print(l);
        clear(l);
    }
    return 0;
}