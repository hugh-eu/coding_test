#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    answer += my_string.substr(0, s);
    answer += overwrite_string;
    if (s + overwrite_string.size() < my_string.size()) answer += my_string.substr(s + overwrite_string.size());
    
    return answer;
}