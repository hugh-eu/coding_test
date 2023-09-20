#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {    
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    int days = 30 * (a - 1);
    
    if (a == 2) days++;
    else if (2 < a && a <= 8) days += a / 2 - 1;
    else days += (a + 1) / 2 - 1;
    days += b - 1;
    
    return week[(days + 5) % 7];
}