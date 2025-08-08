#include <bits/stdc++.h>
using namespace std;
using M = vector<vector<long long>>;
M mul(M a, M b) {
    return {{a[0][0]*b[0][0]+a[0][1]*b[1][0], a[0][0]*b[0][1]+a[0][1]*b[1][1]},
            {a[1][0]*b[0][0]+a[1][1]*b[1][0], a[1][0]*b[0][1]+a[1][1]*b[1][1]}};
}
M pow(M a, int n) {
    M r = {{1,0},{0,1}};
    while(n) {
        if(n&1) r = mul(r,a);
        a = mul(a,a);
        n >>= 1;
    }
    return r;
}
long long fib(int n) {
    if(n==0) return 0;
    M f = {{1,1},{1,0}};
    return pow(f,n-1)[0][0];
}
int main() {
    int n; cin >> n;
    cout << fib(n) << endl;
}
