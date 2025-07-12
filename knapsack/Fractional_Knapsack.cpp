#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;
    for (auto item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return totalValue;
}

int knapsack01(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int boundedKnapsack(int W, vector<int>& wt, vector<int>& val, vector<int>& count, int n) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < count[i]; k++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
    }
    return dp[W];
}

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= w)
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> val(n), wt(n), count(n);
    vector<Item> items;

    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " value and weight: ";
        cin >> val[i] >> wt[i];
        items.push_back({val[i], wt[i]});
    }

    cout << "Enter count for each item (for bounded knapsack):\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " count: ";
        cin >> count[i];
    }

    cout << "\nResults:\n";
    cout << "1. Fractional Knapsack (Greedy): " << fractionalKnapsack(W, items) << endl;
    cout << "2. 0/1 Knapsack (DP): " << knapsack01(W, wt, val, n) << endl;
    cout << "3. Bounded Knapsack: " << boundedKnapsack(W, wt, val, count, n) << endl;
    cout << "4. Unbounded Knapsack: " << unboundedKnapsack(W, wt, val, n) << endl;

    return 0;
}
