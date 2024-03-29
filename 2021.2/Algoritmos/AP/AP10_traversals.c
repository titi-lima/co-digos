#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int** matrix;
    int numEdge;
    int numVertices;
    int* mark;
} G;

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

typedef struct {
    int size;
    Node* top;
} Stack;

typedef struct {
    int size;
    Node* front;
    Node* rear;
} Queue;

int clock = 1;

Queue* create_queue() {
    Queue *q = NULL;
    q = (Queue*) malloc(sizeof(Queue));
    q->front = (Node*) malloc(sizeof(Node));
    q->rear = q->front;
    q->size = 0;
    return q;
}

Stack* create_stack() {
    Stack *s = NULL;
    s = (Stack*) malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

Node *create_node(int data, Node* next) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = next;
    return temp;
}

void enqueue(Queue *q, int data) {
    q->rear->next = create_node(data, NULL);
    q->rear = q->rear->next; // comeca no front, o rear n pode apontar p ngm no final msm, ta certo inacreditavelmente
    ++(q->size);
}

int dequeue(Queue *q) {
    int it;
    Node *temp = q->front->next;
    if(q->size != 0) {
        it = q->front->next->data;
        q->front->next = q->front->next->next;
        if(q->front->next == NULL) q->rear = q->front;
        free(temp);
        q->size--;
        return it;
    }
    else return -1; //msm coisa, medo disso dar -1 de fato
}

void clear_queue(Queue *q) {
    Node *temp = NULL;
    Node *temp2 = q->front;
    while(temp2->next != NULL) {
        temp = temp2->next;
        free(temp2);
        temp2 = temp;
    }
    free(temp);
    free(q);
}

void clear_stack(Stack *s) {
    Node *new_top = s->top;
    while(new_top != NULL) {
        new_top = s->top->next;
        free(s->top);
        s->top = new_top;
    }
    free(s);
}

void push(Stack *s, int data) {
    s->top = create_node(data, s->top);
    s->size++;
}

int pop(Stack *s) {
    int it;
    Node* temp = s->top;
    if(s->top != NULL) {
        it = s->top->data;
        s->top = s->top->next;
        s->size--;
        free(temp);
        return it;
    }
    else return -1; // e se der pra retornar -1 normalmente?
}

G* create_graph(int n) {
    G *g;
    g = (G*)malloc(sizeof(G));
    g->mark = (int*)malloc(n*sizeof(int));
    g->matrix = (int**)malloc(n*sizeof(int*));
    for(int k = 0; k < n; ++k) g->matrix[k] = (int*)calloc(n, sizeof(int));
    g->numEdge = 0;
    g->numVertices = n;
    return g;
}

int first(G *g, int v) {
    for(int i = 0; i < g->numVertices; ++i) if(g->matrix[v][i] != 0) return i;
    return g->numVertices;
}

int next(G *g, int v, int w) {
    for(int i = w+1; i < g->numVertices; ++i) if(g->matrix[v][i] != 0) return i;
    return g->numVertices;
}

bool isEdge(G *g, int i, int j) {
    return g->matrix[i][j] != 0; //acho q isso funciona?
}

void setEdge(G *g, int i, int j, int wt) {
    if(wt != 0) { // adequado para grafos ponderados
        if(!isEdge(g, i, j)) g->numEdge++;
        g->matrix[i][j] = wt;
        if(!isEdge(g, j, i)) g->numEdge++; // nao dirigido
        g->matrix[j][i] = wt;
    }
}

void delEdge(G *g, int i, int j) {
    if(g->matrix[i][j] == 0) g->numEdge--;
    g->matrix[i][j] = 0;
}

void setMark(G *g, int v, int val) {
    g->mark[v] = val;
}
int getMark(G *g, int v) {
    return g->mark[v];
}

bool isVisited(G *g, int v) {
    return getMark(g, v) != 0;
}

void preVisit(G *g, int v){ //transformar mark em uma struct? no contexto da questao, printar tlvz
    printf("%d ", v);
    g->mark[v] = clock;
    ++clock;
}
void posVisit(G *g, int v){
    g->mark[v] = clock;
    ++clock;
}

void DFS(G *g, int v) {
    int w;
    preVisit(g, v);
    setMark(g, v, 1);
    w = first(g, v);
    while(w < g->numVertices) {
        if(!isVisited(g, w)) DFS(g, w);
        w = next(g, v, w);
    }
    //posVisit(g, v);
}

void BFS(G *g, int v) {
    int w;
    Queue *Q = create_queue();
    enqueue(Q, v);
    setMark(g, v, 1);
    while (Q->size > 0){
        v = dequeue(Q);
        preVisit(g, v);
        w = first(g, v);
        while (w < g->numVertices) {
            if (!isVisited(g, w)) {
                setMark(g, w, 1);
                enqueue(Q, w);
            }
            w = next(g, v, w);
        }
        //posVisit(g, v);
    }
    clear_queue(Q);
}

void graphTraverse(G *g, char traversal, int start) {
    int v;
    for(v = 0; v<g->numVertices; ++v) setMark(g, v, 0);
    switch(traversal) {
        case 'd': {
            for(v=start; v<g->numVertices+start; ++v) {
                if(!isVisited(g, v%g->numVertices)) {
                    DFS(g, v%g->numVertices);
                }
            }
            break;
        }
        case 'b': {
            for(v=start; v<g->numVertices+start; ++v) {
                if(!isVisited(g, v%g->numVertices)) {
                    BFS(g, v%g->numVertices);
                }
            }
            break;
        }
    }
    printf("\n");
    clock = 1;
}

void freeMatrix(int **matrix, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void clear_graph(G *g) {
    freeMatrix(g->matrix, g->numVertices);
    free(g->mark);
    free(g);
}

int main() {
    int n, q, i, j, start;
    char com[4];
    scanf("%d %d", &n, &q);
    G *g = create_graph(n);
    while(q--) {
        scanf(" %s", com);
        switch(com[0]) {
            case 'a': {
                scanf("%d %d", &i, &j);
                setEdge(g, i, j, 1); // passo 1 pq nao eh ponderado?
                break;
            }
            case 'D': {
                scanf("%d", &start);
                graphTraverse(g, 'd', start);
                break;
            }
            case 'B': {
                scanf("%d", &start);
                graphTraverse(g, 'b', start);
                break;
            }
        }
    }
    clear_graph(g);
    return 0;
}