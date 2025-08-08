#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n){
    double phi = (1+ sqrt(5))/2;
    return round(pow(phi, n)/ sqrt(5));
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
