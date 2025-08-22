#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int backward(int n, vector<vector<pair<int, int>>>& graph, vector<int>& parent){
    vector<int> cost(n, INF);
    cost[n-1] = 0;
    vector<vector<pair<int, int>>> pred(n);
    for (int u = 0; u < n; u++)
    {
        for(auto edge : graph[u]){
            int v = edge.first;
            int w = edge.second;
            pred[v].emplace_back(u, w);
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        for(auto edge : pred[i]){
            int u = edge.first;
            int w = edge.second;
            if (cost[i] != INF && cost[u]> cost[i]+w)
            {
                cost[u] = cost[i] + w;
                parent[u] = i;
            }
        }
    }
    return cost[0];
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
    cout<<"The Path: ";
    for(auto n : path){
        cout<<n<<" ";
    }
    cout<<endl;
}
int main() {
    int n, edge;
    cout<<"Enter nodes: ";
    cin>>n;
    cout<<"Enter edges: ";
    cin>>edge;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> parent(n, -1);
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cout<<"Edge "<<i+1<<": ";
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }
    cout<<"The Structure: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Node "<<i+1<<": ";
        for(auto edge : graph[i]){
            cout<<"("<<edge.first<<", "<<edge.second<<") ";
        }
        cout<<endl;
    }
    int minCost = backward(n, graph, parent);
    cout<<"Cost: "<<minCost<<endl;
    printPath(parent, 0, n-1);
    return 0;
}