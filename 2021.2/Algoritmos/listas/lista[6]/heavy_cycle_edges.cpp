#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class DS {
public:
    unordered_map<int, int> parent;

    DS(int n) {
        for(int i = 0; i < n; i++) parent[i] = i; // cada subconjunto de vertices tem o proprio vertice como raiz no inicio
    }

    int findRoot(int curr) {
        if(parent[curr] == curr) return curr;
        return findRoot(parent[curr]); // ate encontrar a raiz
    }

    int findRootCout(int curr) {
        cout << curr << '\n';
        if(parent[curr] == curr) {
            return curr;
        }
        return findRootCout(parent[curr]); // ate encontrar a raiz
    }

    void uniao(int a, int b) {
        int r1 = findRoot(a);
        int r2 = findRoot(b);
        if(r1!=r2) parent[r2] = r1;
    }
};

class G {
public:
    int numEdge;
    int numVertices;
    int **matrix;
    bool *mark;
    G(int n) {
        numEdge = 0;
        numVertices = n;
        matrix = new int *[n];
        mark = new bool[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) matrix[i][j] = 0;
        }
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
        return matrix[i][j] != 0;
    }

    void setEdge(int i, int j, int w) {
        if (!isEdge(i, j)) numEdge++;
        matrix[i][j] = w;
        if (!isEdge(j, i)) numEdge++; // nao dirigido
        matrix[j][i] = w;
    }

    void delEdge(int i, int j) {
        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }

    void setMark(int v, bool val) {
        mark[v] = val;
    }

    bool isVisited(int v) {
        return mark[v] != 0;
    }
    void clear_matrix() {
        for (int i = 0; i < numVertices; i++) delete[] matrix[i];
        delete[] matrix;
        delete[] mark;
    }

    int weight(int v1, int v2) {
        if (v2 == numVertices) return 0;
        return matrix[v1][v2];
    }

    struct CompareWeight {
        bool operator()(tuple<int, int, int> const &t1, tuple<int, int, int> const &t2) {
            return get<2>(t1) > get<2>(t2);
        }
    };
    struct CompareWeightMax {
        bool operator()(tuple<int, int, int> const &t1, tuple<int, int, int> const &t2) {
            return get<2>(t1) < get<2>(t2);
        }
    };

    void printResult(G &g) {
        for (int i = 0; i < numVertices; i++) {
            for(int j = 0; j < numVertices; j++) {
                cout << (matrix[i][j] != g.matrix[i][j] && matrix[i][j] != g.matrix[j][i]) << ' ';
            }
            cout << '\n';
        }
    }

    void setOneEdge(int i, int j, int w) {
        if (!isEdge(i, j)) numEdge++;
        if(!isEdge(j, i)) matrix[i][j] = w;
    }

    void preVisit(queue<int> &p, int v) {
        p.push(v);
    }

    void posVisit(queue<int> &p, int v) {
        p.pop();
    }

    void findGreatestWeight(queue<int> &q, int p) {
        //talvez ele tente checar o mesmo ciclo tbm
        while(!q.empty()) {
            cout << 'a' << q.front() << ' ';
            q.pop();
        }
        cout << '\n';
    }

    void DFS(int v, int t, int parent, queue<int> p) {
        int w;  
        preVisit(p, v);
        setMark(v, 1);
        w = first(v);
        //cout << "entra aqui qnts vezes, " << v << '\n';
        while(w < numVertices) {
            //cout << v << ' ' << w << '\n';
            if(!isVisited(w)) DFS(w, t, v, p);
            else if(w!=parent && p.size() > 1) return findGreatestWeight(p, t);// achamo, backtracar o vector ate achar o w lembrar o parent

            w = next(v, w);
        }
        posVisit(p, v); //queue
    }

    void Kruskal(G &g) {
        int w, u, v, wt;
        tuple<int, int, int> t;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareWeight> H;
        for (int i = 0; i < numVertices; ++i) {
            w = first(i);
            while (w < numVertices) {
                if(w>=i) {
                    t = make_tuple(i, w, weight(i, w));
                    H.push(t);
                    w = next(i, w);
                }
                else w = next(i, w);
            }
        }
        DS ds(numVertices);
        int numMST = numVertices;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareWeightMax> Hg;
        while (numMST > 1 || !H.empty()) {
            tie(v, u, wt) = H.top();
            H.pop();
            if (ds.findRoot(v) != ds.findRoot(u)) {
                ds.uniao(v, u);
                g.setEdge(v, u, wt);
                numMST--;
            }
            else {
                t = make_tuple(v, u, wt);
                Hg.push(t);
            }
        }
        while(!Hg.empty()) {
            tie(v, u, wt) = Hg.top();
            g.setEdge(v, u, wt);
            cout << v << " ta passando\n";
            queue<int> q;
            for(int i = 0; i < numVertices; i++) g.setMark(i, 0);
            g.DFS(v, v, v, q);
            g.delEdge(v, u); // UMA ARESTA PODE TER MAIS DE UM CICLO
            Hg.pop();
        }
        //printResult(g);
    }
};

int main() {
    int n, m, v, a, b, w;
    cin >> n >> m;
    G g(n);
    G g2(n);
    while (m--) {
        cin >> a >> b >> w;
        g.setEdge(a, b, w);
    }
    g.Kruskal(g2);
    g.clear_matrix();
    return 0;
}