#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

void process_oil(int i, int j, vector<vector<int>> &land) {
    int qty = 0;
    queue<pair<int, int>> q;
    vector<int> vr = {-1, 1, 0, 0};
    vector<int> vc = {0, 0, -1, 1};
    map<int, pair<int, int>> tops;
    
    land[i][j] = -1;
    q.push(make_pair(i, j));
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        
        q.pop();
        ++qty;
        
        for (int k = 0; k < 4; ++k) {
            if (
                0 <= r + vr[k] && r + vr[k] < land.size() && 
                0 <= c + vc[k] && c + vc[k] < land[0].size() && 
                land[r+vr[k]][c+vc[k]] == 1
            ) {
                land[r+vr[k]][c+vc[k]] = -1;
                q.push(make_pair(r+vr[k], c+vc[k]));
            }
        }
        
        if (r-1 < 0) {
            if (tops.count(c) == 0) tops[c] = make_pair(r, c);
            else if (tops[c].first > r) tops[c] = make_pair(r, c);
        } else if (land[r-1][c] == 0) {
            if (tops.count(c) == 0) tops[c] = make_pair(r-1, c);
            else if (tops[c].first > r-1) tops[c] = make_pair(r-1, c);
        }
    }
    
    for (auto &iter : tops) {
        land[iter.second.first][iter.second.second] = qty;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    for (int i = 0; i < land.size(); ++i) for (int j = 0; j < land[0].size(); ++j) {
        if (land[i][j] == 1) process_oil(i, j, land);
    }
    
    for (int j = 0; j < land[0].size(); ++j) {
        int sum_oil = 0;
        for (int i = 0; i < land.size(); ++i) {
            if (land[i][j] != -1) sum_oil += land[i][j];
        }
        if (answer < sum_oil) answer = sum_oil;
    }
    
    return answer;
}