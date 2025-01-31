#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for (char c : my_string) {
        if (find(letter.begin(), letter.end(), c) == letter.end()) {
            answer += c;
        }
    }
    return answer;
}