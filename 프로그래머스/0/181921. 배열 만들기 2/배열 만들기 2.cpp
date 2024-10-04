#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; ++i) {
        bool flag = true;
        for (char c : to_string(i)) {
            if (c != '0' && c != '5') {
                flag = false;
                break;
            }
        }
        if (flag) answer.push_back(i);
    }
    
    if (answer.size()) sort(answer.begin(), answer.end());
    else answer.push_back(-1);
    
    return answer;
}