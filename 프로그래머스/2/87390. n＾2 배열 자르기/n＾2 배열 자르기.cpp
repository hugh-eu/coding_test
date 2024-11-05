#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long l = left; l <= right; ++l) {
        answer.push_back(max(l / n, l % n) + 1);
    }
    
    return answer;
}