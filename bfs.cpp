#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 6;
void bfs(vector<vector<int>>& matrix, int start) {
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor = 0; neighbor < N; ++neighbor) {
            if (matrix[node][neighbor] != 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    cout << "BFS starting from node 0:" << endl;
    bfs(matrix, 0);
    return 0;
}
