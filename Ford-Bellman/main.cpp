#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printProgressTable(vector<vector<int>>& distances) {
    cout << "-------------------------------" << endl;
    cout << "|       |   A    |   B    |   C    |   D    |" << endl;
    cout << "-------------------------------" << endl;
    char nodes[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < distances.size(); ++i) {
        cout << "|   " << nodes[i] << "   |";
        for (int j = 0; j < distances[i].size(); ++j) {
            if (distances[i][j] == INT_MAX)
                cout << "  INF  |";
            else
                cout << "  " << distances[i][j] << "  |";
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
}

void bellmanFord(vector<vector<pair<int, int>>>& graph, int start) {
    int V = graph.size();
    vector<vector<int>> distances(V, vector<int>(V, INT_MAX));

    for (int i = 0; i < V; ++i)
        distances[i][i] = 0;

    for (int u = 0; u < V; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            distances[u][v] = weight;
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX && distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    printProgressTable(distances);
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, -201}, {2, -102}, {3, 99}},  // A
        {{2, 99}},                         // B
        {},                                // C
        {{1, -300}}                        // D
    };
    int start_node = 0; // Start from node A
    bellmanFord(graph, start_node);
    return 0;
}
