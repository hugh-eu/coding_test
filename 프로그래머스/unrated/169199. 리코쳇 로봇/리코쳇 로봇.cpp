#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(vector<string> &board, int xStart, int yStart) {
    vector<string> visitedPoint;
    visitedPoint.push_back(to_string(xStart) + "/" + to_string(yStart));
    queue<vector<int>> q;
    q.push({xStart, yStart, 0});
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if (x > 0 && board[x - 1][y] != 'D') {
            int i = 1;
            while (x - i > 0 && board[x - i][y] != 'D') i++;
            int tempX = x - i + (board[x - i][y] == 'D' ? 1 : 0);
            if (board[tempX][y] == 'G') return cnt + 1;
            if (find(visitedPoint.begin(), visitedPoint.end(), to_string(tempX) + "/" + to_string(y)) == visitedPoint.end()) {
                visitedPoint.push_back(to_string(tempX) + "/" + to_string(y));
                q.push({tempX, y, cnt + 1});
            }
        }
        if (x < board.size() - 1 && board[x + 1][y] != 'D') {
            int i = 1;
            while (x + i < board.size() - 1 > 0 && board[x + i][y] != 'D') i++;
            int tempX = x + i - (board[x + i][y] == 'D' ? 1 : 0);
            if (board[tempX][y] == 'G') return cnt + 1;
            if (find(visitedPoint.begin(), visitedPoint.end(), to_string(tempX) + "/" + to_string(y)) == visitedPoint.end()) {
                visitedPoint.push_back(to_string(tempX) + "/" + to_string(y));
                q.push({tempX, y, cnt + 1});
            }
        }
        if (y > 0 && board[x][y - 1] != 'D') {
            int i = 1;
            while (y - i > 0 && board[x][y - i] != 'D') i++;
            int tempY = y - i + (board[x][y - i] == 'D' ? 1 : 0);
            if (board[x][tempY] == 'G') return cnt + 1;
            if (find(visitedPoint.begin(), visitedPoint.end(), to_string(x) + "/" + to_string(tempY)) == visitedPoint.end()) {
                visitedPoint.push_back(to_string(x) + "/" + to_string(tempY));
                q.push({x, tempY, cnt + 1});
            }
        }
        if (y < board[x].size() - 1 && board[x][y + 1] != 'D') {
            int i = 1;
            while (y + i < board[x].size() - 1 && board[x][y + i] != 'D') i++;
            int tempY = y + i - (board[x][y + i] == 'D' ? 1 : 0);
            if (board[x][tempY] == 'G') return cnt + 1;
            if (find(visitedPoint.begin(), visitedPoint.end(), to_string(x) + "/" + to_string(tempY)) == visitedPoint.end()) {
                visitedPoint.push_back(to_string(x) + "/" + to_string(tempY));
                q.push({x, tempY, cnt + 1});
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int xStart, yStart;

    for (int i = 0; i < board.size(); i++) {
        if (board[i].find('R') != string::npos) {
            xStart = i;
            yStart = board[i].find('R');
            break;
        }
    }

    return bfs(board, xStart, yStart);
}