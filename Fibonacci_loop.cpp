#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n){
    if(n<=1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <=n; i++)
    {
        int temp = a+b;
        a = b;
        b = temp;
    }
    return b;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;
    return 0;
}