#include <string>
#include <vector>
#include <queue>

using namespace std;

void findRoute(vector<string> &maps, vector<vector<int>> &visited, queue<pair<pair<int, int>, int>> &q, int column, int row, int n) {
    if (column > 0 && maps[column - 1].at(row) != 'X' && visited[column - 1][row] == 0) {
        visited[column - 1][row] = 1;
        q.push(make_pair(make_pair(column - 1, row), n + 1));
    }
    if (column < maps.size() - 1 && maps[column + 1].at(row) != 'X' && visited[column + 1][row] == 0) {
        visited[column + 1][row] = 1;
        q.push(make_pair(make_pair(column + 1, row), n + 1));
    }
    if (row > 0 && maps[column].at(row - 1) != 'X' && visited[column][row - 1] == 0) {
        visited[column][row - 1] = 1;
        q.push(make_pair(make_pair(column, row - 1), n + 1));
    }
    if (row < maps[0].size() - 1 && maps[column].at(row + 1) != 'X' && visited[column][row + 1] == 0) {
        visited[column][row + 1] = 1;
        q.push(make_pair(make_pair(column, row + 1), n + 1));
    }
}

int solution(vector<string> maps) {
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size()));
    queue<pair<pair<int, int>, int>> q;
    
    bool flagStart = false;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i].at(j) == 'S') {
                flagStart = true;
                visited[i][j] = 1;
                q.push(make_pair(make_pair(i, j), 0));
                break;
            }
        }
        if (flagStart) break;
    }

    while (!q.empty()) {
        int column = q.front().first.first;
        int row = q.front().first.second;
        int n = q.front().second;
        q.pop();

        if (maps[column].at(row) == 'L') {
            visited = vector<vector<int>>(maps.size(), vector<int>(maps[0].size()));
            q = queue<pair<pair<int, int>, int>>();

            visited[column][row] = 1;
            q.push(make_pair(make_pair(column, row), n));

            while (!q.empty()) {
                column = q.front().first.first;
                row = q.front().first.second;
                n = q.front().second;
                q.pop();
                
                if (maps[column].at(row) == 'E') return n;
                
                findRoute(maps, visited, q, column, row, n);
            }
        }
        
        findRoute(maps, visited, q, column, row, n);
    }
    
    return -1;
}