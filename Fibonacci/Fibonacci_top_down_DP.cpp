#include <iostream>
#include <vector>
using namespace std;

vector<int> memo(1000, -1);  // Memoization table initialized with -1

int fibonacci(int n) {
    if (n <= 1) return n;  // Base case
    if (memo[n] != -1) return memo[n];  // Return cached value if it exists
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);  // Compute and store the value
    return memo[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
