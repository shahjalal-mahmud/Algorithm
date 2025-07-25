#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int backward(int n, vector<vector<pair<int, int>>> &graph, vector<int> &parent)
{
    vector<int> cost(n, INF);
    cost[n - 1] = 0;
    vector<vector<pair<int, int>>> pred(n);
    for (int u = 0; u < n; u++)
    {
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            pred[v].emplace_back(u, w);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto edge : pred[i])
        {
            int u = edge.first;
            int w = edge.second;
            if (cost[i] != INF && cost[u] > w + cost[i])
            {
                cost[u] = w + cost[i];
                parent[u] = i;
            }
        }
    }
    return cost[0];
}
void printPath(const vector<int> &parent, int src, int des)
{
    vector<int> path;
    int curr = src;
    while (curr != des)
    {
        path.push_back(curr);
        curr = parent[curr];
        if (curr == -1)
        {
            cout << "No parernt Found." << endl;
            return;
        }
    }
    path.push_back(des);
    cout << "path: ";
    for (auto node : path)
    {
        cout << node << "->";
    }
    cout << endl;
}
int main()
{
    int n = 8;
    vector<vector<pair<int, int>>> graph(n);
    graph[0] = {{1, 1}, {2, 2}, {3, 5}};
    graph[1] = {{4, 4}, {5, 11}, {6, 9}};
    graph[2] = {{4, 9}, {5, 5}, {6, 16}};
    graph[3] = {{6, 2}, {7, 5}};
    graph[4] = {{7, 18}};
    graph[5] = {{7, 13}};
    graph[6] = {{7, 2}};

    vector<int> parent(n, -1); // To store the path
    int minCost = backward(n, graph, parent);

    cout << "\n✅ Minimum cost (Backward DP): " << minCost << endl;
    printPath(parent, 0, n - 1);
    return 0;
}