#include <string>
#include <vector>

using namespace std;

string get_binary(int i) {
    string s = "";
    while (i >= 1) {
        s = to_string(i % 2) + s;
        i = i / 2;
    }
    return s;
}

int solution(int n) {
    string binary_n = get_binary(n);
    int num_of_1_n = 0;
    for (char c : binary_n) if (c == '1') ++num_of_1_n;
    
    int i = n + 1;
    while (true) {
        string binary_i = get_binary(i);
        int num_of_1_i = 0;
        for (char c : binary_i) if (c == '1') ++num_of_1_i;
        if (num_of_1_i == num_of_1_n) return i;
        ++i;
    }
}