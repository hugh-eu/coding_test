#include <string>
#include <vector>
#include <numeric>

using namespace std;

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 1;
    for (int i : arr)
        answer = lcm(answer, i);
    return answer;
}