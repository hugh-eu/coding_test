#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<int> exception;

    sort(lost.begin(), lost.end());
    for (int i = 0; i < lost.size(); i++) {
        if (find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()) {
            answer++;
            reserve.erase(find(reserve.begin(), reserve.end(), lost[i]));
            exception.push_back(i);
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        if (find(exception.begin(), exception.end(), i) == exception.end()) {
            if (find(reserve.begin(), reserve.end(), lost[i] - 1) != reserve.end()) {
                answer++;
                reserve.erase(find(reserve.begin(), reserve.end(), lost[i] - 1));
                continue;
            }
            if (find(reserve.begin(), reserve.end(), lost[i] + 1) != reserve.end()) {
                answer++;
                reserve.erase(find(reserve.begin(), reserve.end(), lost[i] + 1));
            }
        }
    }
    
    return answer;
}