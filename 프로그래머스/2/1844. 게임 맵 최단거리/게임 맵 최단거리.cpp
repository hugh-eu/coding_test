#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    vector<vector<int>> track(maps.size(), vector<int>(maps[0].size(), 0));
    queue<vector<int>> q;
    
    track[0][0] = 1;
    q.push({0, 0, 1});
    
    while (!q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int n = q.front()[2];
        q.pop();
        if (r > 0 && maps[r - 1][c] == 1 && track[r - 1][c] == 0) {
            if (r - 1 == maps.size() - 1 && c == maps[0].size() - 1) return n + 1;
            track[r - 1][c] = 1;
            q.push({r - 1, c, n + 1});
        }
        if (r < maps.size() - 1 && maps[r + 1][c] == 1 && track[r + 1][c] == 0) {
            if (r + 1 == maps.size() - 1 && c == maps[0].size() - 1) return n + 1;
            track[r + 1][c] = 1;
            q.push({r + 1, c, n + 1});
        }
        if (c > 0 && maps[r][c - 1] == 1 && track[r][c - 1] == 0) {
            if (r == maps.size() - 1 && c - 1 == maps[0].size() - 1) return n + 1;
            track[r][c - 1] = 1;
            q.push({r, c - 1, n + 1});
        }
        if (c < maps[0].size() - 1 && maps[r][c + 1] == 1 && track[r][c + 1] == 0) {
            if (r == maps.size() - 1 && c + 1 == maps[0].size() - 1) return n + 1;
            track[r][c + 1] = 1;
            q.push({r, c + 1, n + 1});
        }
    }
    
    return -1;
}