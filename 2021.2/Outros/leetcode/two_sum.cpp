#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using std::cin;
using std::cout;

bool solve(std::vector<int> &v, std::queue<int> &q, int target, int i) {
    while(i < v.size()) {
        if(q.front()+v[i] == target) {
            q.push(v[i]);
            return true;
        }
        else if(q.front()+v[i] > target) return false;
        ++i;
    }
    return false;
}

int main() {
    char aux;
    int n, i=0;
    std::vector<int> v;
    std::queue<int> q;
    std::unordered_map<int, int> m;
    cin.ignore(100, '[');
    do {
        cin >> n >> aux;
        v.emplace_back(n);
        m[n] = v.size()-1;
    } while (aux != ']');
    cin.ignore(100, '=');
    cin >> n; // target
    sort(v.begin(), v.end());
    q.push(v[0]);
    while (!solve(v, q, n, ++i)) {
        q.pop();
        q.push(v[i]);
    }
    cout << '[' << m[q.front()] << ',' << m[q.back()] << ']' << '\n';
    return 0;
}