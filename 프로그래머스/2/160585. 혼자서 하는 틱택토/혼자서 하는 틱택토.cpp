#include <string>
#include <vector>

using namespace std;

bool checkWin(vector<vector<char>> &testBoard) {
    int o1 = 0, x1 = 0, o2 = 0, x2 = 0;
    for (int i = 0; i < 3; i++) {
        int o3 = 0, x3 = 0, o4 = 0, x4 = 0;
        for (int j = 0; j < 3; j++) {
            if (testBoard[i][j] == 'O') o3++;
            else if (testBoard[i][j] == 'X') x3++;
            if (testBoard[j][i] == 'O') o4++;
            else if (testBoard[j][i] == 'X') x4++;
        }
        if (o3 == 3 || x3 == 3 || o4 == 3 || x4 == 3) return true;
        if (testBoard[i][i] == 'O') o1++;
        else if (testBoard[i][i] == 'X') x1++;
        if (testBoard[i][2-i] == 'O') o2++;
        else if (testBoard[i][2-i] == 'X') x2++;
    }
    if (o1 == 3 || x1 == 3 || o2 == 3 || x2 == 3) return true;
    return false;
}

void review(int &answer, vector<vector<char>> testBoard, vector<pair<int, int>> o, vector<pair<int, int>> x) {
    if (o.empty()) {
        if (x.empty()) answer = 1;
        return;
    }
    for (int i = 0; i < o.size(); i++) {
        testBoard[o[i].first][o[i].second] = 'O';
        if (checkWin(testBoard)) {
            if (o.size() == 1 && x.empty()) {
                answer = 1;
                return;
            } else {
                testBoard[o[i].first][o[i].second] = '.';
                continue;
            }
        }
        if (x.empty()) {
            if (o.size() == 1) answer = 1;
            return;
        }
        for (int j = 0; j < x.size(); j++) {
            testBoard[x[j].first][x[j].second] = 'X';
            if (checkWin(testBoard)) {
                if (o.size() == 1 && x.size() == 1) {
                    answer = 1;
                    return;
                } else {
                    testBoard[x[j].first][x[j].second] = '.';
                    continue;
                }
            }
            vector<pair<int, int>> _o(o);
            vector<pair<int, int>> _x(x);
            _o.erase(_o.begin() + i);
            _x.erase(_x.begin() + j);
            review(answer, testBoard, _o, _x);
            if (answer == 1) return;
            testBoard[x[j].first][x[j].second] = '.';
        }
        testBoard[o[i].first][o[i].second] = '.';
    }
}

int solution(vector<string> board) {
    int answer = 0;

    vector<vector<char>> testBoard(3, vector<char>(3, '.'));
    vector<pair<int, int>> o;
    vector<pair<int, int>> x;

    for (int i = 0; i < board.size(); i++) for (int j = 0; j < board[0].size(); j++) {
        if (board[i].at(j) == 'O') o.push_back(make_pair(i, j));
        else if (board[i].at(j) == 'X') x.push_back(make_pair(i, j));
    }
    
    review(answer, testBoard, o, x);
    
    return answer;
}