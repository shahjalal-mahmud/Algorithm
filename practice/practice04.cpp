#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int forward(int n, vector<vector<pair<int, int>>>& graph, vector<int>& parent) {
    vector<int> cost(n, INF);
    cost[0] = 0;
    for (int u = 0; u < n; u++) {
        for(auto edge: graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if(cost[u] != INF && cost[v] > cost[u] + w) {
                cost[v] = cost[u] + w;
                parent[v] = u;
            }
        }
    }
    return cost[n-1];
}
void printPath(vector<int>& parent, int src, int des) {
    vector<int> path;
    int curr = src;
    while (curr != des) {
        path.push_back(curr);
        curr = parent[curr];
        if(curr == -1) {
            cout << "Path not found" << endl;
            return;
        }
    }
    path.push_back(des);
    cout << "The Path: ";
    for(auto n: path) {
        cout << n << " ";
    }
    cout << endl;
}
int main() {
    int n, edges;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> parent(n, -1);
    cout << "Enter number of edges: ";
    cin >> edges;
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        cout << "Edge " << i+1 << ": ";
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cout << "\nGraph structure:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " -> ";
        for(auto edge : graph[i]) {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }
        cout << endl;
    }
    int minCost = forward(n, graph, parent);
    cout << "\nMinimum cost from node 0 to node " << n-1 << ": " << minCost << endl;
    printPath(parent, n-1, 0);
    return 0;
}