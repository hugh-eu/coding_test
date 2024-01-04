#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (65 <= c && c <= 90) answer += 65 + (c + n - 65) % 26;
        else if (97 <= c && c <= 122) answer += 97 + (c + n - 97) % 26;
        else answer += c;
    }
    
    return answer;
}