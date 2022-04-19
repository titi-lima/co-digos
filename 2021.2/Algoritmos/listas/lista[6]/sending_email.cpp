#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

class G {
public:
    unsigned short int numEdge;
    unsigned short int numVertices;
    unsigned short int **matrix;
    bool *mark;
    G(int n) {
        numEdge = 0;
        numVertices = n;
        matrix = new unsigned short int *[n];
        mark = new bool[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new unsigned short int[n];
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
        if(w==0) w = USHRT_MAX;
        if (!isEdge(i, j)) numEdge++;
        if(matrix[i][j] > w || !matrix[i][j])matrix[i][j] = w;
        if (!isEdge(j, i)) numEdge++; // nao dirigido
        if(matrix[j][i] > w || !matrix[j][i]) matrix[j][i] = w;
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
        if(matrix[v1][v2] == USHRT_MAX) return 0;
        return matrix[v1][v2];
    }

    struct CompareWeight {
        bool operator()(tuple<int, int, int> const &t1, tuple<int, int, int> const &t2) {
            return get<2>(t1) > get<2>(t2);
        }
    };

    void dijkstra(int s, int *D) {
        tuple <int,int,int> t;
        t = make_tuple(s, s, 0);
        int P[numVertices], w, p, v;
        for (int i = 0; i < numVertices; i++) {
            D[i] = -1;
            setMark(i, false);
        }
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
                //cout << "D[w] eh " << D[w] << " D[v] eh " << D[v] << " Weight(v, w) eh " << weight(v,w) << " Visited eh " << isVisited(w) << endl;
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

int main() {
    int N, n, m, v, a, b, w, t;
    cin >> N;
    for(int j = 0; j < N; j++) {
        cout << "Case #" << j+1 << ": ";
        cin >> n >> m >> v >> t; // n eh o numero de vertices, m o de arestas, v o que parte e t o que chega
        int D[n];
        G g(n);
        while (m--) {
            cin >> a >> b >> w;
            g.setEdge(a, b, w);
        }
        g.dijkstra(v, D);
        if(D[t] != -1) cout << D[t] << '\n';
        else cout << "unreachable\n";
        g.clear_matrix();
    }
    return 0;
}