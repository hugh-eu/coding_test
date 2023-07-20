#include <string>
#include <vector>

using namespace std;

void toh(vector<vector<int>> &answer, int n, int departure, int via, int dest) {
    if (n == 1) {
        vector<int> v;
        v.push_back(departure);
        v.push_back(dest);
        answer.push_back(v);
    } else {
        toh(answer, n - 1, departure, dest, via);
        vector<int> v;
        v.push_back(departure);
        v.push_back(dest);
        answer.push_back(v);
        toh(answer, n - 1, via, departure, dest);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    toh(answer, n, 1, 2, 3);

    return answer;
}