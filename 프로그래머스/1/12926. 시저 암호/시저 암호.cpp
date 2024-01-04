#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (65 <= c && c <= 90) {
            int i = c;
            i += n;
            i -= 65;
            i = 65 + i % 26;
            c = i;
            answer += c;
        } else if (97 <= c && c <= 122) {
            int i = c;
            i += n;
            i -= 97;
            i = 97 + i % 26;
            c = i;
            answer += c;
        } else answer += c;
    }
    
    return answer;
}