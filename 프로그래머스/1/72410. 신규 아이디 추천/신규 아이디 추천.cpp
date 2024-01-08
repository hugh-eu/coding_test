#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (char c : new_id) {
        if (c == '-' || ('0' <= c && c <= '9') || c == '_' || ('a' <= c && c <= 'z')) answer += c;
        else if (c == '.' && answer.size() > 0 && answer.at(answer.size() - 1) != '.') answer += c;
        else if ('A' <= c && c <= 'Z') answer += c + 32;
    }
    if (answer.size() > 0 && answer.at(answer.size() - 1) == '.') answer = answer.substr(0, answer.size() - 1);
    if (answer.size() == 0) answer += 'a';
    if (answer.size() < 3) {
        int n = 3 - answer.size();
        char c = answer.at(answer.size() - 1);
        for (int i = 0; i < n; i++) answer += c;
    }
    if (answer.size() > 15) {
        if (answer.at(14) == '.') answer = answer.substr(0, 14);
        else answer = answer.substr(0, 15);
    }
    
    return answer;
}