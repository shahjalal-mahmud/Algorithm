#include <iostream>
using namespace std;

pair<long long, long long> fibPair(int n) {
    if (n == 0)
        return make_pair(0LL, 1LL);
    
    pair<long long, long long> p = fibPair(n >> 1);
    long long a = p.first;
    long long b = p.second;
    
    long long c = a * (2 * b - a);
    long long d = a * a + b * b;
    
    if (n & 1)
        return make_pair(d, c + d);  // F(n), F(n+1)
    else
        return make_pair(c, d);      // F(n), F(n+1)
}

long long fastDoublingFib(int n) {
    return fibPair(n).first;
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        cout << "Fibonacci(" << n << ") = " << fastDoublingFib(n) << endl;
    }

    return 0;
}
