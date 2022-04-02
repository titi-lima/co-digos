#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

typedef struct {
    int size;
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue *q, int data) {
    Node* new_rear = NULL;
    new_rear = (Node*)malloc(sizeof(Node));
    new_rear->data = data;
    new_rear->next = NULL;
    q->rear->next = new_rear;
    q->rear = new_rear;
    ++(q->size);
}

void clear(Node* front) {
    Node *temp = NULL;
    Node *temp2 = front->next;
    while(temp2->next != NULL) {
        temp = temp2->next;
        free(temp2);
        temp2 = temp;
    }
    free(temp);
}

int check(Queue *q) { // intera toda a fila, checa se ha numero fora de posicao e se no caminho dele ha numero maior
    Node *templ = q->front->next;
    Node *tempr = q->front->next->next;
    int j=0, pos=0, i;
    int k = q->size;
    for(i=0; i<q->size-1; ++i) {
        ++pos;
        //printf("%d %d\n", i, q->size);
        for(j=pos; j<=(templ->data-pos); ++j) { //deixa o templ fixo, vai ate a posicao dele procurando
            //printf("\n%d %d\n", templ->data, tempr->data);
            //printf("j: %d, data: %d, data-j: %d\n", j, templ->data, templ->data-j);
            if(tempr->data > templ->data) {
                printf("no\n");
                return 0;
            }
            else tempr = tempr->next;
        }
        templ = templ->next;
        tempr = templ->next;
    }
    return 1;
}

int main() { // se um numero estiver fora de posicao e houver um numero maior que ele no caminho, f.
    int cont=0, a, b, aux, data, tam=0, aux2, checa;
    Queue *q = NULL;
    q = (Queue*) malloc(sizeof(Queue));
    q->front = (Node*) malloc(sizeof(Node));
    scanf("%d", &a);
    while(a!=0) {
        q->rear = q->front;
        q->size = 0;
        for(aux = 0; aux < a; ++aux) {
            scanf("%d", &data);
            enqueue(q, data);
        }
        checa = check(q);
        if(checa == 1) printf("yes\n");
        clear(q->front);
        scanf("%d", &a);
    }
    return 0;
}