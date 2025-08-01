#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // A large number to represent infinity

void floydWarshall(int n, vector<vector<int>> &graph) {
    // Distance matrix initially same as graph
    vector<vector<int>> dist = graph;

    // Floyd-Warshall DP
    for (int k = 0; k < n; k++) { // Intermediate node
        for (int i = 0; i < n; i++) { // Source
            for (int j = 0; j < n; j++) { // Destination
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print the shortest distance matrix
    cout << "All-Pairs Shortest Paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    // Adjacency matrix representation
    vector<vector<int>> graph = {
        {0,     5,   INF, 10},
        {INF,   0,     3, INF},
        {INF, INF,    0,   1},
        {INF, INF,  INF,   0}
    };

    floydWarshall(n, graph);
    return 0;
}
