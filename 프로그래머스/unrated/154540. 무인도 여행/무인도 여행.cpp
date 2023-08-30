#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<int>> scanned(maps.size(), vector<int>(maps[0].size()));

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i].at(j) != 'X' && scanned[i][j] == 0) {
                scanned[i][j] = 1;
                int days = 0;
                queue<vector<int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int x = q.front()[0];
                    int y = q.front()[1];
                    q.pop();
                    days += maps[x].at(y) - '0';
                    if (x > 0 && scanned[x - 1][y] == 0) {
                        if (maps[x - 1].at(y) != 'X') {
                            scanned[x - 1][y] = 1;
                            q.push({x - 1, y});
                        }
                    }
                    if (x < maps.size() - 1 && scanned[x + 1][y] == 0) {
                        if (maps[x + 1].at(y) != 'X') {
                            scanned[x + 1][y] = 1;
                            q.push({x + 1, y});
                        }
                    }
                    if (y > 0 && scanned[x][y - 1] == 0) {
                        if (maps[x].at(y - 1) != 'X') {
                            scanned[x][y - 1] = 1;
                            q.push({x, y - 1});
                        }
                    }
                    if (y < maps[0].size() - 1 && scanned[x][y + 1] == 0) {
                        if (maps[x].at(y + 1) != 'X') {
                            scanned[x][y + 1] = 1;
                            q.push({x, y + 1});
                        }
                    }
                }
                answer.push_back(days);
            }
        }
    }

    if (answer.size() > 0) sort(answer.begin(), answer.end());
    else answer.push_back(-1);

    return answer;
}