#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> scores = {0, 0, 0};
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == v1[i % v1.size()]) scores[0]++;
        if (answers[i] == v2[i % v2.size()]) scores[1]++;
        if (answers[i] == v3[i % v3.size()]) scores[2]++;
    }
    int h = *max_element(scores.begin(), scores.end());
    for (int i = 0; i < scores.size(); i++) if (scores[i] == h) answer.push_back(i + 1);

    return answer;
}