#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    queue<vector<int>> q;
    bool usedNum[1000001] = {false,};

    q.push({x, 0});
    usedNum[x] = true;

    while (!q.empty()) {
        int num = q.front()[0];
        int attempts = q.front()[1];
        q.pop();

        if (num == y) return attempts;

        if (num + n <= y && !usedNum[num + n]) {
            q.push({num + n, attempts + 1});
            usedNum[num + n] = true;
        }
        if (num * 2 <= y && !usedNum[num * 2]) {
            q.push({num * 2, attempts + 1});
            usedNum[num * 2] = true;
        }
        if (num * 3 <= y && !usedNum[num * 3]) {
            q.push({num * 3, attempts + 1});
            usedNum[num * 3] = true;
        }
    }

    return -1;
}