#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n1 = arr1.size();
    int n2 = arr1[0].size();
    vector<vector<int>> answer(n1, vector<int>(n2));
    
    for (int i = 0; i < n1; i++) for (int j = 0; j < n2; j++) answer[i][j] = arr1[i][j] + arr2[i][j];
    
    return answer;
}