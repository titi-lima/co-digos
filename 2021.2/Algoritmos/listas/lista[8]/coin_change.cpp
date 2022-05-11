#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;

void getMaxChange(int n, std::vector<int> &coins) {
    static int D[5] = {1, 5, 10, 25, 50};
    coins[0] = 1;
    //if(n>maxi) coins.resize(n);
    for (int i = 0; i < 5; i++) {
        for (int j = D[i]; j <= n; j++) {
            coins[j] += coins[j - D[i]];
            //cout << "segfaulltou\n";
        }
    }
    //maxi = std::max(maxi, n);
}

int main() {
    int n, maximo=0;
    std::queue<int> q;
    std::vector<int> coins;
    while (cin >> n) {
        maximo = std::max(maximo, n);
        q.push(n);
    }
    coins.reserve(maximo);
    getMaxChange(maximo, coins);
    while(!q.empty()) {
        cout << coins[q.front()] << '\n';
        q.pop();
    }
    return 0;
}