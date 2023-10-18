#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string temp = "";

    int i = 0;
    while (true) {
        if (pow(3, i + 1) > n) break;
        else i++;
    }
    for (int j = i; j >= 0; j--) {
        temp += to_string(n / (int)pow(3, j));
        n = n % (int)pow(3, j);
    }

    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) answer += (temp.at(i) - '0') * (int)pow(3, temp.size() - 1 - i);

    return answer;
}