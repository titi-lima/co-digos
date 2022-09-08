#include <iostream>
#include <string>

using std::cin;
using std::cout;

bool next(std::string n) {
    for(unsigned short int k=0; k<8; k++) {
        n[k] = n[k+1];
    }
    if(cin >> n[8]) return true;
    return false;
}

bool isPalindrome(std::string *n) {
    for(unsigned short int k=0; k<9; k++) {
        if(n[k] != n[8-k]) return false;
    }
    return true;
}

bool isPrime(std::string s) {
    long int n = std::stol(s, nullptr);
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    // Using concept of prime number
    // can be represented in form of
    // (6*n + 1) or(6*n - 1) hence
    // we have to go for every multiple of 6 and
    // prime number would always be 1 less or 1 more than
    // the multiple of 6.
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

void printResult(std::string n) {
    return;
}

int main() {
    std::string n[10];
    for (unsigned short int k = 0; k < 9; k++) cin >> n[k];
    while(next(n)) {
        if(!isPalindrome(n)) continue;
        if(isPrime(n)) break;
    }
    printResult(n);
    return 0;
}