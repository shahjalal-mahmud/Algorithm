#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;
int backward(int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> cost(n, INF);
    cost[n - 1] = 0; 
    vector<vector<pair<int, int>>> pred(n);
    for (int u = 0; u < n; u++) {
        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            pred[v].emplace_back(u, w);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (auto edge : pred[i]) {
            int u = edge.first;
            int w = edge.second;
            if (cost[i] != INF) {
                cost[u] = min(cost[u], w + cost[i]);
            }
        }
    }
    return cost[0];
}
int main() {
    int n = 8;
    vector<vector<pair<int, int>>> graph(n);
    graph[0] = {{1, 1}, {2, 2}, {3, 5}};
    graph[1] = {{4, 4}, {5, 11}, {6, 9}};
    graph[2] = {{4, 9}, {5, 5}, {6, 16}};
    graph[3] = {{6, 2}, {7, 5}};
    graph[4] = {{7, 18}};
    graph[5] = {{7, 13}};
    graph[6] = {{7, 2}};
    int minCost = backward(n, graph);
    cout << "Minimum cost (Backward DP): " << minCost << endl;
    return 0;
}