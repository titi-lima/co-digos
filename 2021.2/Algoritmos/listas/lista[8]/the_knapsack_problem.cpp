#include <iostream>
#include <vector>

using std::cin;
using std::cout;

class Bag {
public:
    int capacity;
    int numitems;
    int** F;
    int** W;
    std::vector<int> w;
    std::vector<int> v;

    Bag(int n, int s) {
        capacity = ++s;
        numitems = ++n;
        F = new int *[numitems];
        W = new int *[numitems];
        for (int i = 0; i < n; i++) {
            F[i] = new int[capacity];
            W[i] = new int [capacity];
            for(int j = 0; j < capacity; j++) W[i][j] = 0;
        }
        w.reserve(numitems);
        v.reserve(numitems);
        w.emplace_back(0);
        v.emplace_back(0);
    }

    ~Bag() {
        w.clear();
        w.shrink_to_fit();
        v.clear();
        v.shrink_to_fit();
        for (int i = 0; i < numitems; i++) delete[] F[i];
        delete[] F;
    }

    int Knapsack() {
        for(int i = 0; i < numitems; i++) {
            for(int j = 0; j < capacity; j++) {
                if(i==0 || j==0) F[i][j] = 0;
                else if(w[i] <= j) {
                    if(j-(w[i])>=0) F[i][j] = std::max(F[i-1][j], v[i] + F[i-1][j-w[i]]);
                    else F[i][j] = std::max(F[i-1][j], v[i]);
                }
                else F[i][j] = F[i-1][j];
            }
        }
        return F[numitems-1][capacity-1];
    }
};

int main() {
    int n, s, ajudador, ajudador_auxiliar;
    cin >> n >> s;
    Bag b(s, n);
    while(s--) {
        cin >> ajudador >> ajudador_auxiliar;
        b.w.emplace_back(ajudador);
        b.v.emplace_back(ajudador_auxiliar);
    }
    cout << b.Knapsack() << '\n';
    return 0;
}