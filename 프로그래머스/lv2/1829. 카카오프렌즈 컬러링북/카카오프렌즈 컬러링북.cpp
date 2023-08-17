#include <vector>
#include <queue>

using namespace std;

void bfs(int &number_of_area, int &max_size_of_one_area, vector<vector<int>> &picture, vector<vector<int>> &visit, int r, int c) {
    int color = picture[r][c];
    int cntSize = 0;
    queue<vector<int>> q;
    q.push({r, c});
    visit[r][c] = 1;
    while (!q.empty()) {
        cntSize++;
        int i = q.front()[0];
        int j = q.front()[1];
        if (i > 0 && picture[i - 1][j] == color && visit[i - 1][j] == 0) {
            q.push({i - 1, j});
            visit[i - 1][j] = 1;
        }
        if (i < picture.size() - 1 && picture[i + 1][j] == color && visit[i + 1][j] == 0) {
            q.push({i + 1, j});
            visit[i + 1][j] = 1;
        }
        if (j > 0 && picture[i][j - 1] == color && visit[i][j - 1] == 0) {
            q.push({i, j - 1});
            visit[i][j - 1] = 1;
        }
        if (j < picture[0].size() - 1 && picture[i][j + 1] == color && visit[i][j + 1] == 0) {
            q.push({i, j + 1});
            visit[i][j + 1] = 1;
        }
        q.pop();
    }
    number_of_area++;
    if (max_size_of_one_area < cntSize) max_size_of_one_area = cntSize;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<int>> visit(picture.size(), vector<int>(picture[0].size()));
    for (int r = 0; r < picture.size(); r++) {
        for (int c = 0; c < picture[0].size(); c++) {
            if (picture[r][c] > 0 && visit[r][c] == 0) bfs(number_of_area, max_size_of_one_area, picture, visit, r, c);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}