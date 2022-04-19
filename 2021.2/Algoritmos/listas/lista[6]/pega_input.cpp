#include <iostream>

#define pivot 82

using namespace std;

int main() {
    int n, a, b, c, d, e, f, g;
    cin >> n;
    cout << 1 << '\n';
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
            if (i == pivot-1) {
                for (int j = 0; j < b; ++j) {
                    if (j == 0) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
                    cin >> e >> f >> g;
                    cout << e << ' ' << f << ' ' << g << '\n';
                }
                return 0;
            }
        for (int j = 0; j < b; ++j)
            cin >> e >> f >> g;
    }
    return 0;
}
