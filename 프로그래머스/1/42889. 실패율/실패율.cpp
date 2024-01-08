#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    if (((double)v1[0] / (v1[1] > 0 ? v1[1] : 1) > (double)v2[0] / (v2[1] > 0 ? v2[1] : 1)) || 
        ((double)v1[0] / (v1[1] > 0 ? v1[1] : 1) == (double)v2[0] / (v2[1] > 0 ? v2[1] : 1) && v1[2] < v2[2])) return true;
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<vector<int>> failureRate(N, vector<int>(3));

    for (int i = 0; i < N; i++) failureRate[i][2] = i + 1;
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 0; j < stages[i]; j++) {
            if (j == N) break;
            failureRate[j][1]++;
            if (j == stages[i] - 1) failureRate[j][0]++;
        }
    }
    sort(failureRate.begin(), failureRate.end(), compare);
    for (int i = 0; i < failureRate.size(); i++) answer.push_back(failureRate[i][2]);

    return answer;
}