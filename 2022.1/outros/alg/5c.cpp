#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;

typedef struct {
    int x;
    int y;
} Coordinates;

class Graph {
public:
    bool visited;
    int **matrix;
    int numEdge;
    bool *mark;

    bool isEdge(int i, int j) {
        return matrix[i][j] != 0;
    }

    int next(int v, int w) {
        for (int i = w; i < 50; ++i)
            if (isEdge(v, i)) return i;
        return 50;
    }

    bool isIn(int i) {
        return mark[i];
    }

    void setEdge(int i, int j, int w) {
        if (!isEdge(i, j)) numEdge++;
        matrix[i][j] = w;
        mark[i] = true;
    }

    void createGraph(std::vector<Coordinates> &c, std::vector<int> &in) {
        matrix = new int *[50];
        mark = new bool[50]();
        for (int i = 0; i < 50; i++) {
            matrix[i] = new int[50](); // inicializa com 0
        }
        // 1-5-10-15-20-1
        in.push_back(0);
        in.push_back(4);
        in.push_back(9);
        in.push_back(14);
        in.push_back(19);
        setEdge(0, 4, sqrt((c[0].x - c[4].x) * (c[0].x - c[4].x) + (c[0].y - c[4].y) * (c[0].y - c[4].y)));
        setEdge(4, 9, sqrt((c[9].x - c[4].x) * (c[9].x - c[4].x) + (c[9].y - c[4].y) * (c[9].y - c[4].y)));
        setEdge(9, 14, sqrt((c[9].x - c[14].x) * (c[9].x - c[14].x) + (c[9].y - c[14].y) * (c[9].y - c[14].y)));
        setEdge(14, 19, sqrt((c[19].x - c[14].x) * (c[19].x - c[14].x) + (c[19].y - c[14].y) * (c[19].y - c[14].y)));
        setEdge(19, 0, sqrt((c[0].x - c[19].x) * (c[0].x - c[19].x) + (c[0].y - c[19].y) * (c[0].y - c[19].y)));
    }

    void printMatrix() {
        int curr = 0;
        cout << "1 -> ";
        do {
            for (int i = 0; i < 50; i++) {
                if (matrix[curr][i]) {
                    cout << i + 1 << " -> ";
                    curr = i;
                    break;
                }
            }
        } while (curr != 0);
    }
};
struct CompareWeight {
    bool operator()(std::tuple<int, int, int> const &t1, std::tuple<int, int, int> const &t2) {
        return std::get<2>(t1) > std::get<2>(t2);
    }
};
int main() {
    int N, x, y;
    cin >> N; // le o numero de coordenadas
    std::vector<Coordinates> c;
    std::vector<int> in;
    for (int i = 0; i < N; i++) {
        cin >> x >> y; // le as coordenadas
        c.push_back({x, y});
    }
    Graph g;
    g.createGraph(c, in);

    for (int i = 1; i < 50; i++) {
        if (!g.isIn(i)) {
            std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, CompareWeight> p;
            for (int j = 0; j < (int)in.size(); j++) {
                int k = g.next(in[j], 0);
                int cost = (sqrt((c[i].x - c[in[j]].x) * (c[i].x - c[in[j]].x) + (c[i].y - c[in[j]].y) * (c[i].y - c[in[j]].y)) + sqrt((c[i].x - c[k].x) * (c[i].x - c[k].x) + (c[i].y - c[k].y) * (c[i].y - c[k].y))) - g.matrix[in[j]][k]; // quanto maior, mais caro
                p.push({in[j], k, cost});
            }
            std::tuple<int, int, int> ans = p.top();

            in.push_back(i);
            g.setEdge(std::get<0>(ans), std::get<1>(ans), 0);
            g.setEdge(std::get<0>(ans), i, sqrt((c[i].x - c[std::get<0>(ans)].x) * (c[i].x - c[std::get<0>(ans)].x) + (c[i].y - c[std::get<0>(ans)].y) * (c[i].y - c[std::get<0>(ans)].y)));
            g.setEdge(i, std::get<1>(ans), sqrt((c[i].x - c[std::get<1>(ans)].x) * (c[i].x - c[std::get<1>(ans)].x) + (c[i].y - c[std::get<1>(ans)].y) * (c[i].y - c[std::get<1>(ans)].y)));
        }
    }
    g.printMatrix();
    return 0;
}