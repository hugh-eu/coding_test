#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int l = min(n, m);
    int g = max(n, m);

    int i = g;
    while (l % i != 0 || g % i != 0) i--;
    answer.push_back(i);

    int j = 1;
    while ((g * j) % l != 0) j++;
    answer.push_back(g * j);
    
    return answer;
}