#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    int n = arr.size() / 2 + 1;
    vector<vector<int>> dpMax(n, vector<int>(n, -2147483648));
    vector<vector<int>> dpMin(n, vector<int>(n, 2147483647));

    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n - step; i++) {
            int j = i + step;
            if (step == 0) {
                dpMax[i][j] = stoi(arr[i * 2]);
                dpMin[i][j] = stoi(arr[i * 2]);
            } else {
                for (int k = i; k < j; k++) {
                    if (arr[k * 2 + 1] == "+") {
                        dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] + dpMax[k + 1][j]);
                        dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] + dpMin[k + 1][j]);
                    } else {
                        dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] - dpMin[k + 1][j]);
                        dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] - dpMax[k + 1][j]);
                    }
                }
            }
        }
    }

    return dpMax[0][n - 1];
}