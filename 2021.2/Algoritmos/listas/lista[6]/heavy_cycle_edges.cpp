#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <stack>
#include <climits>

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
        if(w == 0) w = __INT_MAX__;
        if (!isEdge(i, j)) numEdge++;
        matrix[i][j] = w;
        if (!isEdge(j, i)) numEdge++; // nao dirigido
        matrix[j][i] = w;
    }

    void clear_matrix() {
        for (int i = 0; i < numVertices; i++) delete[] matrix[i];
        delete[] matrix;
        delete[] mark;
    }

    int weight(int v1, int v2) {
        if (v2 == numVertices || matrix[v1][v2] == __INT_MAX__) return 0;
        return matrix[v1][v2];
    }

    struct CompareWeight {
        bool operator()(tuple<int, int, int> const &t1, tuple<int, int, int> const &t2) {
            return get<2>(t1) > get<2>(t2);
        }
    };

    void Kruskal() {
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
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareWeight> Hg;
        while (!H.empty()) {
            tie(v, u, wt) = H.top();
            H.pop();
            if (ds.findRoot(v) != ds.findRoot(u)) {
                ds.uniao(v, u);
            }
            else {
                t = make_tuple(v, u, wt);
                Hg.push(t);
            }
        }
        if(Hg.empty()) {
            cout << "forest\n";
            return;
        }
        while(!Hg.empty()) {
            tie(v, u, wt) = Hg.top();
            Hg.pop();
            if(!Hg.empty()) cout << weight(v, u) << ' ';
            else cout << weight(v, u);
        }
        cout << '\n';
    }
};

int main() {
    int n, m, v, a, b, w;
    do {
        cin >> n >> m;
        if(n==0 && m==0) return 0;
        G g(n);
        while (m--) {
            cin >> a >> b >> w;
            g.setEdge(a, b, w);
        }
        g.Kruskal();
        g.clear_matrix();
    } while (!(n == 0 && m == 0)); 
    return 0;
}