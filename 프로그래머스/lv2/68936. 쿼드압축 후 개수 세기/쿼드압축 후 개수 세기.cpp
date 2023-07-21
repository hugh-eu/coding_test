#include <string>
#include <vector>

using namespace std;

void quad(vector<vector<int>> &arr, int n, int rStart, int cStart, vector<int> &answer) {
    int nStart = arr[rStart][cStart];
    for (int i = rStart; i < rStart + n; i++) {
        for (int j = cStart; j < cStart + n; j++) {
            if (arr[i][j] != nStart) {
                quad(arr, n / 2, rStart, cStart, answer);
                quad(arr, n / 2, rStart, cStart + (n / 2), answer);
                quad(arr, n / 2, rStart + (n / 2), cStart, answer);
                quad(arr, n / 2, rStart + (n / 2), cStart + (n / 2), answer);
                return;
            }
            if (i == rStart + n - 1 && j == cStart + n - 1) {
                answer[nStart]++;
            }
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0, 0};

    int n = arr.size();
    quad(arr, n, 0, 0, answer);

    return answer;
}