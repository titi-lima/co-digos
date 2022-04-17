#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

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
        return matrix[i][j] != 0;
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

    int encontre(vector<vector<int>> &ds, int curr) {
        for (int i = 0; i < ds.size(); i++) {
            if (find(ds[i].begin(), ds[i].end(), curr) != ds[i].end()) return i;
        }
        return -1;
    }

    void uniao(vector<vector<int>> &ds, int a, int b) {
        int r1 = encontre(ds, a);
        int r2 = encontre(ds, b);
        if (ds[r1][0] != ds[r2][0]) {
            for (int i = 0; i < ds[r1].size(); i++) {
                ds[r2].push_back(ds[r1][i]);
            }
            ds[r1].clear();
        }
    }

    void createDisjointSubset(vector<vector<int>> &ds) {
        for (int i = 0; i < numVertices; i++) {
            vector<int> t;
            t.push_back(i);
            ds.push_back(t);
        }
    }

    void printResult() {
        int sum = 0;
        for (int i = 0; i < numVertices; i++) {
            sum += weight(i, first(i));
        }
        cout << sum << '\n';
    }

    void setOneEdge(int i, int j, int w) {
        if (!isEdge(i, j)) numEdge++;
        matrix[i][j] = w;
    }

    void Kruskal(G &g) {
        int w, u, v, wt;
        tuple<int, int, int> t;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareWeight> H;
        for (int i = 0; i < numVertices; ++i) {
            w = first(i);
            while (w < numVertices) {
                t = make_tuple(i, w, weight(i, w));
                H.push(t);
                w = next(i, w);
            }
        }
        vector<vector<int>> ds;
        createDisjointSubset(ds);
        int numMST = numVertices;
        while (numMST > 1) {
            tie(v, u, wt) = H.top();
            H.pop();
            if (encontre(ds, v) != encontre(ds, u)) {
                uniao(ds, v, u);
                g.setOneEdge(v, u, wt);
                numMST--;
            }
        }
        g.printResult();
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