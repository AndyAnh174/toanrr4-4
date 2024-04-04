#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>>& graph) {
    int V = graph.size();

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

void print_matrix(const vector<vector<int>>& matrix) {
    int V = matrix.size();
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (matrix[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> graph = {
        {0, 1, 0, 99},
        {INF, 0, 99, INF},
        {INF, INF, 0, INF},
        {INF, -300, INF, 0}
    };


    floyd_warshall(graph);


    print_matrix(graph);

    return 0;
}
