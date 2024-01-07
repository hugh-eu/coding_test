#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int nIdx = phone_number.size() - 4;

    for (int i = 0; i < nIdx; i++) answer += '*';
    answer += phone_number.substr(nIdx, 4);
    
    return answer;
}