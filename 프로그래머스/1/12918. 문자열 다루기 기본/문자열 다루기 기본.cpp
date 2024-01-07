#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size() == 4 || s.size() == 6) {
        for (char c : s) {
            if ('0' <= c && c <= '9') continue;
            else return false;
        }
        return true;
    } else return false;
}