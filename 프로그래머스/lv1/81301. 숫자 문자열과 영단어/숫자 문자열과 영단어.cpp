#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {    
    string answer = "";
    string word = "";
    
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (char c : s) {
        if (48 <= c && c <= 57) answer += c;
        else {
            word += c;
            if (find(numbers.begin(), numbers.end(), word) != numbers.end()) {
                answer += to_string(find(numbers.begin(), numbers.end(), word) - numbers.begin());
                word = "";
            }
        }
    }
    
    
    return stoi(answer);
}