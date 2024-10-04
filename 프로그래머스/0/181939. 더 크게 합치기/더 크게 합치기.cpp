#include <string>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    answer = stoi(to_string(a) + to_string(b));
    if (stoi(to_string(b) + to_string(a)) > answer) answer = stoi(to_string(b) + to_string(a));
    
    return answer;
}