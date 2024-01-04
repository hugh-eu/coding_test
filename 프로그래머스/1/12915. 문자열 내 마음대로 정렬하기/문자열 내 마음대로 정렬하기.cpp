#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<string> temp;
    
    for (int i = 97; i <= 122; i++) {
        for (string s : strings) if (s.at(n) == i) temp.push_back(s);
        sort(temp.begin(), temp.end());
        for (string s : temp) answer.push_back(s);
        temp.clear();
    }
    
    return answer;
}