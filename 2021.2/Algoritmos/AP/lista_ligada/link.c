#include "linked.h"
#include <stdlib.h>
#include <stdio.h>

Node* insert(Node *curr, Node *tail, int data) { // cria um Node novo, retorna o ponteiro para esse Node
    Node* temp = NULL;
    temp = (Node*) malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Erro na alocacao.\n");
        exit(1);
    }
    temp->data = data;
    temp->next = curr->next;
    if(temp->next == NULL) { // checa se o Node criado ta na ultima posicao. se sim, sera o novo tail
        tail = temp;
    }
    return temp;
}

Node* delete(Node *curr) { // remove o Node apontado pelo cursor, retorna o ponteiro para o next desse Node removido
    Node *temp = curr->next->next; // cria um ponteiro para o q era o proximo Node
    free(curr->next);
    return temp;
}

void count(Node *head, int data) {
    int cont=0;
    Node *temp = head->next; //o header eh vazio, faz sentido já iniciar como o próximo Node
    while(temp != NULL) { // para quando chegar no fim
        if(temp->data == data) {
            ++cont;
        }
        temp = temp->next;
    }
    printf("%d\n", cont);
}

Node* prev(Node *curr, Node *head) { //retorna o novo cursor
    if(curr!=head) {
        Node *temp = head->next;
        while(curr != temp->next) {
            temp = temp->next;
        }
        return temp;
    }
    else return curr;
}

Node* next(Node *curr) { //retorna o novo cursor
    if(curr->next->next != NULL) {
        curr = curr->next; // garante q ele n ta empurrando depois do tail
    }
    return curr;
}

void clear(Node *head) {
    Node *temp = NULL;
    Node *curr = head;
    do {
        temp = curr->next;
        free(curr);
        curr = temp;
    } while(temp->next != NULL);
}