#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    int mode = 0;
    
    for (int i = 0; i < code.size(); ++i) {
        if (!mode) {
            if (code[i] != '1') {
                if (i % 2 == 0) ret += code[i];
            } else mode = 1;
        } else {
            if (code[i] != '1') {
                if (i % 2 == 1) ret += code[i];
            } else mode = 0;
        }
    }
    
    return ret.size() > 0 ? ret : "EMPTY";
}