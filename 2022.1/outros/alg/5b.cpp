#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;

typedef struct {
    int x;
    int y;
    bool visited;
} Coordinates;

void printSolution(int *path, int distance) {
    int curr = 0;
    cout << "distancia total: " << distance << '\n'
         << "1 -> ";
    do {
        cout << path[curr] + 1 << " -> ";
        curr = path[curr];
    } while (path[curr] != 0);
    cout << "1 \n";
}

int main() {
    int N, x, y, curr = 0, distance = 0;
    cin >> N; // le o numero de coordenadas
    std::vector<Coordinates> c;
    int path[N];
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        c.push_back({x, y, false});
    }

    for (int i = 0; i < N; i++) {
        int min = __INT_MAX__;
        if (i == N - 1) {
            path[curr] = 0;
            distance += sqrt(abs((c[curr].x - c[0].x) * (c[curr].x - c[0].x) + (c[curr].y - c[0].y) * (c[curr].y - c[0].y)));
            break;
        }
        for (int k = 1; k < N; k++) { // k = 0 vai ser de onde ele parte e pra onde ele volta
            if (curr != k && !c[k].visited) {
                if (min != std::min((c[curr].x - c[k].x) * (c[curr].x - c[k].x) + (c[curr].y - c[k].y) * (c[curr].y - c[k].y), min)) { // checa se a distancia entre os dois pontos eh menor do que a menor distancia ate entao
                    min = (c[curr].x - c[k].x) * (c[curr].x - c[k].x) + (c[curr].y - c[k].y) * (c[curr].y - c[k].y);
                    path[curr] = k;
                }
            }
        }
        distance += sqrt((c[curr].x - c[path[curr]].x) * (c[curr].x - c[path[curr]].x) + (c[curr].y - c[path[curr]].y) * (c[curr].y - c[path[curr]].y));
        c[path[curr]].visited = true;
        curr = path[curr];
    }

    printSolution(path, distance);
    return 0;
}
