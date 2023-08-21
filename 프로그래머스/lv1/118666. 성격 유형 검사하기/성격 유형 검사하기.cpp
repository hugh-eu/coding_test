#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<char> category = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    vector<int> point = {0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < survey.size(); i++) point[find(category.begin(), category.end(), survey[i][0]) - category.begin()] += (4 - choices[i]);
    for (int i = 0; i < point.size(); i += 2) answer += point[i] >= point[i + 1] ? category[i] : category[i + 1];

    return answer;
}