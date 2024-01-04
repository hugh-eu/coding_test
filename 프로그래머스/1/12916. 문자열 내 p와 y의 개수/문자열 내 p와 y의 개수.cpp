#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int p = 0, y = 0;
    
    for (char c : s) {
        if (c == 80 || c == 112) p++;
        if (c == 89 || c == 121) y++;
    }

    return p == y;
}