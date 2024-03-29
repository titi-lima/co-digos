#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool** matrix;
    int numEdge;
    int numVertices;
    bool* mark;
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

Stack* create_stack() {
    Stack *s = NULL;
    s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

Node *create_node(int data, Node* next) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = next;
    return temp;
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

void freeMatrix(bool **matrix, int size) {
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
    g->mark = (bool*)calloc(n, sizeof(bool));
    g->matrix = (bool**)malloc(n*sizeof(bool*));
    for(int k = 0; k < n; ++k) g->matrix[k] = (bool*)calloc(n, sizeof(bool));
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
    }
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

void printStack(Stack *s) {
    Node* temp = s->top;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void toposort(G *g, int v, Stack *s) {
    setMark(g, v, 1);
    int w = first(g, v);
    while (w < g->numVertices) {
        if(!isVisited(g, w)) toposort(g, w, s);
        w = next(g, v, w);
    }
    push(s, v);
}


int main() {
    int n, q, i, j, start;
    char com[4];
    scanf("%d %d", &n, &q);
    G *g = create_graph(n);
    while(q--) {
        scanf("%d %d", &i, &j);
        setEdge(g, i, j, 1);
    }
    Stack *s = create_stack();
    for(int v = 0; v<n; ++v) if(!isVisited(g, v)) toposort(g, v, s);
    printStack(s);
    clear_stack(s);
    clear_graph(g);
    return 0;
}