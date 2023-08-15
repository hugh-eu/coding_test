#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string tempAnswer = "";
    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i] / 2; j++) tempAnswer += to_string(i);
    }
    answer += tempAnswer + '0';
    reverse(tempAnswer.begin(), tempAnswer.end());
    answer += tempAnswer;

    return answer;
}