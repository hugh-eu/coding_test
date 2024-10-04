#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        65 <= str[i] && str[i] <= 90 ? cout << (char)(str[i] + 32) : cout << (char)(str[i] - 32);
    }
    return 0;
}