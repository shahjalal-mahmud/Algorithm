#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int forward(int n, vector<vector<pair<int, int>>>& graph, vector<int>& parent){
    vector<int> cost(n, INF);
    cost[0] = 0;
    for (int u = 0; u < n; u++){
        for(auto edge : graph[u]){
            int v = edge.first;
            int w = edge.second;
            if (cost[u] != INF && cost[v]>cost[u]+w)
            {
                cost[v]=cost[u]+w;
                parent[v]=u;
            }
        }
    }
    return cost[n-1];
}
void printPath(vector<int>& parent, int src, int des){
    vector<int> path;
    int curr = src;
    while (curr != des)
    {
        path.push_back(curr);
        curr = parent[curr];
        if (curr == -1)
        {
            cout<<"Not Found"<<endl;
            return;
        }
    }
    path.push_back(des);
    cout<<"The path: ";
    for(auto n : path){
        cout<<n<<" ";
    }
    cout<<endl;
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
    vector<int> parent(n, -1);
    int minCost = forward(n, graph, parent);
    cout << "Cost: " << minCost << endl;
    printPath(parent, n - 1, 0);
    return 0;
}