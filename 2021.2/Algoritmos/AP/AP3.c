#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

typedef struct {
    int size;
    Node* top;
} Stack;

Node* push(Node* top, int data) {
    Node* new_top = NULL;
    new_top = (Node*)malloc(sizeof(Node));
    new_top->data = data;
    new_top->next = top;
    return new_top;
}

Node* pop(Node* top, int k) {
    Node* new_top = top;
    int cont=0, aux;
    for(aux=0; aux<k; ++aux) {
        if(new_top!=NULL) {
            cont+=new_top->data;
            new_top = top->next;
            free(top);
            top = new_top;
        }
    }
    printf("%d\n", cont);
    return new_top;
}

void clear(Node* top) {
    Node *new_top = top;
    while(new_top != NULL) {
        new_top = top->next;
        free(top);
        top = new_top;
    }
}

int main() {
    int cont=0, a, b, aux, data, tam=0, aux2;
    char str[5];
    Stack *s = NULL;
    s = (Stack*) malloc(sizeof(Stack));
    s->size = 0;

    scanf("%d", &a);

    for(aux = 0; aux < a; ++aux) {
        printf("Caso %d:\n", aux+1);
        scanf(" %s", str);
        while(str[0]!='e') {
            switch(str[1]) {
                case 'u': {
                    scanf("%d", &data);
                    ++(s->size);
                    s->top = push(s->top, data);
                    break;
                }
                case 'o': {
                    scanf("%d", &data);
                    --s->size;
                    s->top = pop(s->top, data);
                    break;
                }
            }
            scanf(" %s", str);
        }
    }

    clear(s->top);
    return 0;
}