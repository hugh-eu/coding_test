#include <string>

using namespace std;

int solution(string number) {
    int sum = 0;
    for (char c : number) sum += c - 48;
    return sum % 9;
}