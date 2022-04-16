#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

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
        return matrix[i][j] != 0; // acho q isso funciona?
    }

    void setEdge(int i, int j, int w) {
        if (!isEdge(i, j)) numEdge++;
        matrix[i][j] = w;
        if (!isEdge(j, i)) numEdge++; // nao dirigido
        matrix[j][i] = w;
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
    }

    int weight(int v1, int v2) {
        return matrix[v1][v2];
    }

    struct CompareWeight {
        bool operator()(tuple<int, int, int> const &t1, tuple<int, int, int> const &t2) {
            // return "true" if "t2" is ordered before "t1", for example:
            return get<2>(t1) > get<2>(t2);
        }
    };

    void dijkstra(int s, int *D) {
        tuple <int,int,int> t;
        t = make_tuple(s, s, 0);
        int P[numVertices], w, p, v;
        for (int i = 0; i < numVertices; i++) D[i] = -1;
        D[s] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareWeight> H;
        H.push(t);
        for (int i = 0; i < numVertices; i++) {
            do {
                if (H.empty()) return;
                t = H.top();
                tie(p, v, ignore) = t;
                H.pop();
            } while (isVisited(v));
            setMark(v, true);
            P[v] = p;
            w = first(v);
            while (w < numVertices) {
                if (!isVisited(w) && D[w] > D[v] + weight(v, w) || D[w] == -1) {
                    D[w] = D[v] + weight(v, w);
                    t = make_tuple(v, w, D[w]);
                    H.push(t);
                }
                w = next(v, w);
            }
        }
    }
};
void printDist(int *d, int n) {
    for (int i = 0; i < n; i++) cout << d[i] << ' ';
    cout << '\n';
}

int main() {
    int n, m, v, a, b, w;
    cin >> n >> m >> v;
    int D[n];
    G g(n);
    while (m--) {
        cin >> a >> b >> w;
        g.setEdge(a, b, w);
    }
    g.dijkstra(v, D);
    printDist(D, n);
    g.clear_matrix();
    return 0;
}