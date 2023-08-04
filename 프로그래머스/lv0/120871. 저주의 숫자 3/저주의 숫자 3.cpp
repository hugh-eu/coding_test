#include <string>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        int j = 1;
        while ((answer + j) % 3 == 0 || to_string(answer + j).find('3') != string::npos) j++;
        answer += j;
    }
    
    return answer;
}