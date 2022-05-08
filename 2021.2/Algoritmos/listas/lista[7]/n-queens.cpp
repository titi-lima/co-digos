#include <iostream>

using std::cin;
using std::cout;

class Tab {
public:
    bool M[8][8];
    int size;
    bool printed;

    Tab(int d) {
        size = d;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                M[i][j] = 0;
            }
        }
        printed = 0;
    }

    bool valid(int l, int i) {
        int j, k;
        for (k = 0; k < size; k++) {
            if (M[l][k]) {
                return false; // checa na horizontal
            }
            if (M[k][i]) return false; // checa na vertical
        }
        for (j = 0, k = 0;; j++, k++) {
            if (l + j < size && k + i < size) {
                if (M[j + l][k + i]) return false; // diagonal superior direita / (++)
            }
            if (l - j >= 0 && i - k >= 0) {
                if (M[l - j][i - k]) return false; // diagonal inferior esquerda  / (--)
            }
            if (l + j < size && i - k >= 0) {
                // cout << "analisando M[" << j+l << "]" << '[' << i-k << "]\n";
                if (M[l + j][i - k]) return false; // diagonal superior esquerda     \ (+-)
            }
            if (l - j >= 0 && k + i < size) {
                if (M[l - j][k + i]) return false; // diagonal inferior direita \ (-+)
            } else if (l + j >= size && l - j <= 0 && k + i >= size && i - k <= 0)
                return true;
        }
    }
    void printMatrix() {
        if (printed)
            cout << '\n';
        else
            printed = true;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (M[i][j]) {
                    if (j == size - 1)
                        cout << 'Q';
                    else
                        cout << "Q\t";
                } else {
                    if (j == size - 1)
                        cout << '-';
                    else
                        cout << "-\t";
                }
            }
            cout << '\n'; // cuidado com presentation error
        }
    }
    bool qns(int l) {
        int i;
        if (l == size) {
            printMatrix();
            return false; // deve vir um return false e uma funcao de print aqui pq eh onde ele acha uma solucao
        } else {
            for (i = 0; i < size; i++) {
                if (valid(l, i)) {
                    M[l][i] = 1;
                    if (qns(l + 1))
                        return true;
                    else
                        M[l][i] = 0;
                }
            }
            return false;
        }
    }
};

int main() {
    int d;
    cin >> d;
    if (d > 8) return 0;
    Tab t(d);
    if (t.size == 1) cout << "Q\n";
    else if (t.size <= 3) cout << "Not Possible\n";
    else t.qns(0);
    return 0;
}