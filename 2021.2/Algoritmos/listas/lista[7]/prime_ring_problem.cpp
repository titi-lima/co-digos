#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;
using std::stack;

void printVector(vector<unsigned short int> const &v) {
    for(int i =0; i < v.size(); i++) {
        if(i!=v.size()-1)cout << v[i] << ' ';
        else cout << v[i] << '\n';
    }
}

bool isPrime(const unsigned short int n) {
    return (n==1 || n==2 || n==3 || n==5 || n==7 || n==11 || n==13 || n==17 || n==19 || n==23 || n==29 || n==31);
}

bool buildSolutions(unsigned short int n, vector<unsigned short int> &v, stack<unsigned short int> s, priority_queue<unsigned short int> q, unsigned short int curr) {
    while(!q.empty()){ // "reseta" a stack para analisarmos o novo numero
        s.push(q.top());
        q.pop();
    }
    //cout << v.size() << '\n'; 
    if (v.size() == n) { // encontramos uma solucao, falta ver se a propriedade de circular esta satisfeita
        if (isPrime(v.back()+1)) printVector(v); //  o primeiro elemento sempre eh 1 mesmo
        return false;
    } else {
        while(!s.empty()) {

            if (isPrime(v.back()+s.top())) {
                v.emplace_back(s.top());
                s.pop();
                if (buildSolutions(n, v, s, q, v.back())) return true; // passa a stack e a p_queue como cópia para o backtracking funcionar melhor
                else {
                    q.push(v.back());
                    v.pop_back();
                }
            }
            else {
                q.push(s.top());
                s.pop();
            }
        }
        return false;
    }
}

void create_structures(vector<unsigned short int> &v, stack<unsigned short int> &s, unsigned short int n) {
    v.reserve(n);
    v.emplace_back(1);
    n++;
    while(--n) s.push(n); // coloca na stack de n a 1
    s.pop(); //tira o 1
}

    int main() {
    unsigned short int n;
    int k=0;
    while (cin >> n) {
        if(k!=0) cout << '\n';
        k++;
        cout << "Case " << k << ":\n";
        vector<unsigned short int> v;
        stack<unsigned short int> s;
        priority_queue<unsigned short int> q;
        create_structures(v, s, n);
        buildSolutions(n, v, s, q, 1);
    }
    return 0;
}
// pula dois numeros em vez de um. 2 3 5 7. manda por ultimo colocar 1 e aloca como um maior que deveria. currvar?