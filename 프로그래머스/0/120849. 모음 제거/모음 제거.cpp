#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    for (char c : my_string) {
        if (find(vowel.begin(), vowel.end(), c) == vowel.end()) {
            answer += c;
        }
    }
    return answer;
}