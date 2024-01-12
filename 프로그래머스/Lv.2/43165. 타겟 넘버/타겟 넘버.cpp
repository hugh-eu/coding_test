#include <string>
#include <vector>

#include <iostream>

using namespace std;

void dfs(vector<int> &numbers, int &target, int &numsSize, int &answer, int sumValue, int i) {
    if (i == numsSize) {
        if (sumValue == target) answer++;
    } else {
        dfs(numbers, target, numsSize, answer, sumValue + numbers[i], i + 1);
        dfs(numbers, target, numsSize, answer, sumValue - numbers[i], i + 1);
    }
}

int solution(vector<int> numbers, int target) {
    int numsSize = numbers.size();    
    int answer = 0;
    int sumValue = 0;
    int i = 0;

    dfs(numbers, target, numsSize, answer, sumValue, i);
    
    return answer;
}