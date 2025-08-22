#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
void APSP(int n, vector<vector<int>>& graph){
    vector<vector<int>> dist = graph;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    cout<<"APSP: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j] == INF){
                cout<<"INF\t";
            }else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}
int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0,     5,   INF, 10},
        {INF,   0,     3, INF},
        {INF, INF,    0,   1},
        {INF, INF,  INF,   0}
    };
    APSP(n, graph);
    return 0;
}