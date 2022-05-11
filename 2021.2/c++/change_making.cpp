#include <iostream>
#include <climits>

using std::cin;
using std::cout;

int changeMaking(int n) {
    static int D[6] = {0, 1, 5, 10, 25, 50};
    int F[n+1], temp;
    F[0] = 0;
    for (int i = 1; i <= n; i++) {
        temp = __INT_MAX__;
        for(int j = D[i]; j<=6 && i >= D[j]; j++) {
            temp = std::min(F[i-D[j]], temp);
        }
        F[i] = temp + 1; 
    }
    return F[n];
}

int main() {
    int n;

    while(cin >> n) {
        cout << changeMaking(n) << '\n';
    }

    return 0;
}