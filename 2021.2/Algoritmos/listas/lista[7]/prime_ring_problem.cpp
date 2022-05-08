#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void printVector(vector<unsigned short int> const &v) {
    for(unsigned short int i: v) {
        cout << i << ' ';
    }
    cout << '\n';
}

bool isPrime(const unsigned short int n) {
    return !(!(n%2) || !(n%3) || !(n%5) || !(n%7));
}

bool buildSolutions(unsigned short int n, vector<unsigned short int> &v, unsigned short int curr) {
    cout << curr << '\n';
    if (curr == n) {
        printVector(v);
        return false;
    } else {
        for (int i = 1; i < n; i++) { // talvez seja mais interessante fazer uma pilha do que esse for
            if (isPrime(i+v.back())) {
                v.emplace_back(i);
                if (buildSolutions(n, v, i+1)) return true;
                else v.pop_back();
            }
        }
        return false;
    }
}

int main() {
    unsigned short int n;
    while (cin >> n) {
        vector<unsigned short int> v;
        v.resize(n);
        v.emplace_back(0);
        buildSolutions(n, v, 1);
    }
    return 0;
}
// pula dois numeros em vez de um. 2 3 5 7. manda por ultimo colocar 1 e aloca como um maior que deveria. currvar?