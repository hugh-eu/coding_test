#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (string str : intStrs) {
        if (stoi(str.substr(s, l)) > k) answer.push_back(stoi(str.substr(s, l)));
    }
    
    return answer;
}