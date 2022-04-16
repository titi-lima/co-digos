#include <iostream>
#include <limits.h>
#include <queue>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


class G {
public:
    bool matrix[300][300];
    int numEdge;
    int numVertices;
    int *mark;
    int ahmad;
    int maxdist;
    G(int n) {
        mark = (int *)calloc(n, sizeof(int));
        numEdge = 0;
        numVertices = 0;
        maxdist = 0;
        for (int i = 0; i < 300; ++i)
            for (int j = 0; j < 300; ++j)
                matrix[i][j] = 0;
    }
    int first(int v) {
        for (int i = 0; i < numVertices; ++i)
            if (matrix[v][i] != 0) return i;
        return numVertices;
    }

    int next(int v, int w) {
        for (int i = w + 1; i < numVertices; ++i)
            if (matrix[v][i] != 0) return i;
        return numVertices;
    }

    bool isEdge(int i, int j) {
        return matrix[i][j] != 0; // acho q isso funciona?
    }

    void setEdge(int i, int j) {
        if (!isEdge(i, j)) numEdge++;
        matrix[i][j] = 1;
        if (!isEdge(j, i)) numEdge++; // nao dirigido
        matrix[j][i] = 1;
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }
    int getMark(int v) {
        return mark[v];
    }

    bool isVisited(int v) {
        return getMark(v) != 0;
    }


    void setEdges(int i, int j, int k) {
        setEdge(i, j);
        setEdge(j, k);
        setEdge(k, i);
    }
};

class Player {
public:
    string nome;
    int dist;
    int v;
    Player(G *g, string name, int indexes[3], int k) {
        if (name == "Ahmad") g->ahmad = g->numVertices; // ainda n incrementei, isso ta certo
        ++(g->numVertices);
        // a alocacao eh por aqui
        nome.assign(name);
        // cout << p[g->numVertices-1].nome << endl;
        dist = __INT_MAX__;
        g->mark = (int *)realloc(g->mark, g->numVertices * sizeof(int)); // mds pq tem tanta alocacao
        g->mark[g->numVertices - 1] = 0;
    }
};

void setDist(G *g, vector<Player> &p, int v, int dist) {
    if (dist > g->maxdist) g->maxdist = dist;
    if (dist < p[v].dist) p[v].dist = dist;
}

void BFS(G *g, int v, vector<Player> &p) {
    int w, dist = 0;
    queue<int> q;
    q.push(v);
    setDist(g, p, v, dist); // parent...?
    g->setMark(v, 1);
    while (q.size() > 0) {
        // toda vez que ele dequeua, eh +1 no clock
        v = q.front();
        q.pop();
        dist = p[v].dist + 1;
        w = g->first(v);
        while (w < g->numVertices) {
            setDist(g, p, w, dist);
            if (!g->isVisited(w)) { // possivelmente o setdist vai bater antes dessa condicao
                g->setMark(w, 1);
                q.push(w);
            }
            w = g->next(v, w);
        }
    }
}

bool isNew(string name, vector<Player> const &p, int indexes[3], int k) {
    int i = 0;
    for (i = 0; i < p.size(); i++) {
        if (name == p[i].nome) {
            indexes[k] = i;
            return false;
        }
    }
    indexes[k] = i;
    return true;
}

void clear_graph(G *g) {
    free(g->mark);
    delete g;
}

int HoarePartition(vector<Player> &p, int l, int r) {
    string s;
    s = p[l].nome;
    int i = l;
    int j = r + 1;
    do {
        do {
            ++i;
        } while (s > p[i].nome && r > i);
        do {
            --j;
        } while (s < p[j].nome);
        swap(p[i], p[j]);
    } while (i < j);
    swap(p[i], p[j]);
    swap(p[l], p[j]);
    return j;
}

void Quicksort(vector<Player> &p, int l, int r) {
    if (l < r) {
        int s = HoarePartition(p, l, r);
        Quicksort(p, l, s - 1);
        Quicksort(p, s + 1, r);
    }
}

void printResult(vector<Player> const &p, G *g, int n) {
    int k, j;
    cout << g->numVertices << endl;
    for (k = 0; k <= n; ++k) {
        for (j = 0; j < g->numVertices; ++j) {
            if (p[j].dist == k) cout << p[j].nome << " " << p[j].dist << endl;
        }
    }
    for (j = 0; j < g->numVertices; ++j) {
        if (p[j].dist == __INT_MAX__) cout << p[j].nome << " undefined" << endl;
    }
}

int main() {
    int n, q, k, indexes[3];
    cin >> n;
    string name;
    vector<Player> p;
    G *g = NULL;
    while (n--) {
        g = new G(1); // dava pra passar tipo q*3 sla
        cin >> q;
        for (k = 0; k < q * 3; ++k) {
            cin >> name;
            if (isNew(name, p, indexes, k % 3)) p.push_back(Player(g, name, indexes, k));
            if (k % 3 == 2) {
                g->setEdges(indexes[0], indexes[1], indexes[2]); // 3 jogadores
            }
        }
        BFS(g, g->ahmad, p);
        Quicksort(p, 0, g->numVertices - 1);
        printResult(p, g, g->maxdist);
        p.clear();
        clear_graph(g); // talvez n de certo isso
    }
    p.shrink_to_fit();
    return 0;
}