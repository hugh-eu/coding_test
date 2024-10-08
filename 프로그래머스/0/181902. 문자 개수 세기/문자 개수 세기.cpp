#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    
    for (char c : my_string) {
        if (65 <= c && c <= 90) ++answer[c-65];
        else ++answer[c-71];
    }
    
    return answer;
}