#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for (int i = 0; i < number.size(); i++) {
        for (int j = i; j < number.size(); j++) {
            if (i != j) {
                for (int k = j; k < number.size(); k++) {
                    if (i != k && j != k && number[i] + number[j] + number[k] == 0) answer++;
                }
            }
        }
    }
    
    return answer;
}