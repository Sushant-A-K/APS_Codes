#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 6;
void dfs(vector<vector<int>>& matrix, int start){
    vector<bool> visited(N, false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for (int neighbor = 0; neighbor < N; ++neighbor){
            if (matrix[node][neighbor] != 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
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
    cout << "DFS starting from node 0:" << endl;
    dfs(matrix, 0);
    return 0;
}
