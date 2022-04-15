#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct {
    bool matrix[300][300];
    int numEdge;
    int numVertices;
    int* mark;
    int ahmad;
    int maxdist;
} G;

typedef struct {
    char nome[21];
    int dist;
    int v;
} Player;

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

Queue* create_queue() {
    Queue *q = NULL;
    q = (Queue*) malloc(sizeof(Queue));
    q->front = (Node*) malloc(sizeof(Node));
    q->rear = q->front;
    q->size = 0;
    return q;
}

Node *create_node(int data, Node* next) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = next;
    return temp;
}

Player *newPlayer(G* g, Player *p, char nome[21], int indexes[3], int k) {
    //checa se pode msm
    for(int i = 0; i < g->numVertices; ++i) { // sla man
        if(!strcasecmp(nome, p[i].nome)) {
            indexes[k] = i;
            return p;
        }
    }
    indexes[k] = g->numVertices;
    if(!strcasecmp(nome, "Ahmad")) g->ahmad = g->numVertices; // ainda n incrementei, isso ta certo
    ++(g->numVertices);
    p = (Player*) realloc(p, (g->numVertices)*sizeof(Player));
    p[g->numVertices-1].v = g->numVertices-1;
    strcpy(p[g->numVertices-1].nome, nome);
    p[g->numVertices-1].dist = __INT_MAX__;
    g->mark = (int*)realloc(g->mark, g->numVertices*sizeof(int));
    g->mark[g->numVertices-1] = 0;
    return p;
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

G* create_graph(int n) {
    G *g = NULL;
    g = (G*)malloc(sizeof(G));
    g->mark = (int*)calloc(n, sizeof(int));
    g->numEdge = 0;
    g->numVertices = 0;
    g->maxdist = 0;
    for(int i=0; i<300; ++i) for(int j=0; j<300; ++j) g->matrix[i][j] = 0;
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

void setEdge(G *g, int i, int j) {
    if(!isEdge(g, i, j)) g->numEdge++;
    g->matrix[i][j] = 1;
    if(!isEdge(g, j, i)) g->numEdge++; // nao dirigido
    g->matrix[j][i] = 1;
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

void preVisit(G *g, int v, int clock){ //transformar mark em uma struct? no contexto da questao, printar tlvz
    printf("%d ", v);
    g->mark[v] = clock;
    ++clock;
}
void posVisit(G *g, int v){
    //g->mark[v] = clock;
    //++clock;
}

void setDist(G *g, Player *p, int v, int dist) {
    if(dist>g->maxdist) g->maxdist = dist;
    if(dist<p[v].dist) p[v].dist = dist;
}

void BFS(G *g, int v, Player* p) {
    int w, dist=0;
    Queue *Q = create_queue();
    enqueue(Q, v);
    setDist(g, p, v, dist); // parent...?
    setMark(g, v, 1);
    while (Q->size > 0){
        //toda vez que ele dequeua, eh +1 no clock
        v = dequeue(Q);
        dist = p[v].dist+1;
        w = first(g, v);
        while (w < g->numVertices) {
            setDist(g, p, w, dist);
            if (!isVisited(g, w)) {
                setMark(g, w, 1);
                enqueue(Q, w);
            }
            w = next(g, v, w);
            //++clock?
        }
        //posVisit(g, v);
    }
    clear_queue(Q);
}

void clear_graph(G *g) {
    free(g->mark);
    free(g);
}

void setEdges(G *g, int i, int j, int k) {
    setEdge(g, i, j);
    setEdge(g, j, k);
    setEdge(g, k, i);
}

void printMatriz(bool matrix[300][300], int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap(Player *p, int i, int j) {
    Player temp;
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

int HoarePartition(Player *p, int l, int r) {
    char s[21];
    strcpy(s, p[l].nome);
    int i = l;
    int j = r+1;
    do {
        do {
            ++i;
        } while(strcasecmp(s, p[i].nome) > 0 && r > i);
        do {
            --j;
        } while(strcasecmp(s, p[j].nome) < 0);
        swap(p, i, j);
    } while(i<j);
    swap(p, i, j);
    swap(p, l, j);
    return j;
}

void Quicksort(Player *p, int l, int r) {
    if(l<r) {
        int s = HoarePartition(p, l, r);
        Quicksort(p, l, s-1);
        Quicksort(p, s+1, r);
    }
}

void printResult(Player *p, G *g, int n) {
    int k, j;
    printf("%d\n", g->numVertices);
    for(k = 0; k <= n; ++k) {
        for(j = 0; j < g->numVertices; ++j) {
            if(p[j].dist == k) printf("%s %d\n", p[j].nome, p[j].dist);
        }
    }
    for(j = 0; j < g->numVertices; ++j) {
        if(p[j].dist == __INT_MAX__) printf("%s undefined\n", p[j].nome);
    }

}

int main() {
    int n, q, k, cont=0, indexes[3];
    G *g = NULL;
    char nome[21];
    scanf("%d", &n);
    while(n--) {
        Player *p = NULL;
        G *g = create_graph(1); // dava pra passar tipo q*3 sla
        scanf(" %d", &q);
        for(k = 0; k < q*3; ++k) {
            //scannea os times, procura por um ahmad nele (enquanto procura se o jogador eh repetido) e se tiver, ja seta a aresta
            scanf(" %s", nome);
            p = newPlayer(g, p, nome, indexes, k%3);
            if(k%3==2) {
                setEdges(g, indexes[0], indexes[1], indexes[2]); //3 jogadores
            }
        }
        //se tudo der certo, nesse ponto, eu sei onde ta ahmad e ja setei a matriz de adjacencias
        //printMatriz(g->matrix, g->numVertices);
        BFS(g, g->ahmad, p);
        Quicksort(p, 0, g->numVertices-1);
        printResult(p, g, g->maxdist);
        //for(int s = 0; s < g->numVertices; s++) printf("%d ", p[s].dist);
        free(p);
        clear_graph(g); // talvez n de certo isso
    }
    return 0;
}
//criar funcao q aloca os vertices / funcao q checa se o vertice ja existe
// cada while roda uma linha. deve ter algum jeito logico de checar se tem um ahmad e ja setar as arestas
// o clock aumenta a cada vez que muda o vertice base?
// mark eh um vetor de struct com o nome, a 'marca' de visita e o peso (possivelmente dentro da marca)
// calcular o clock com base no peso do vertice anterior (talvez mais eficiente com a fila), que ja deve estar calculado (talvez criar mais um parametro; passar 0 na main)
//sera q rola uma funcao prev?
// ou mesmo passar o clock como clock+1 nas funcoes e tirar o global/ponteiro
//ordena por nome e printa por numero
//int max pra quem nao for alcancavel?
