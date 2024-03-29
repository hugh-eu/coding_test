#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.rbegin(), score.rend());
    for (int i = 1; i <= score.size() / m; i++) answer += score.at(m * i - 1) * m;

    return answer;
}