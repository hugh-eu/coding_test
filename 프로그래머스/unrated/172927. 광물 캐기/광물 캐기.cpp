#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
	return a.second > b.second;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    // 총 곡괭이 수
    int nPicks = 0;
    for (int i : picks) nPicks += i;
    
    // 5개당 우선순위
    map<int, int> fatigueMap;
    for (int i = 0; i < minerals.size(); i++) {
        if (minerals[i] == "diamond") fatigueMap[i / 5] += 25;
        else if (minerals[i] == "iron") fatigueMap[i / 5] += 5;
        else fatigueMap[i / 5] += 1;
    }
    vector<pair<int, int>> fatigueVec(fatigueMap.begin(), fatigueMap.end());
    if (nPicks >= fatigueVec.size()) sort(fatigueVec.begin(), fatigueVec.end(), compare);
    else sort(fatigueVec.begin(), fatigueVec.begin() + nPicks, compare);  // 곡괭이가 더 적을경우, 순서대로 채굴하기 때문에 곡괭이 수 범위만 우선순위 내림차순 정렬

    // 상위 곡괭이 부터 선택하여, 우선순위 적용하여 채굴
    int p;
    for (int i = 0; i < fatigueVec.size(); i++) {
        if (picks[0] > 0) {
            p = 0;
            picks[0]--;
        } else if (picks[1] > 0) {
            p = 1;
            picks[1]--;
        } else if (picks[2] > 0) {
            p = 2;
            picks[2]--;
        } else {
            break;
        }
        for (int j = 0; j < 5; j++) {
            if (fatigueVec[i].first * 5 + j < minerals.size()) {
                if (minerals[fatigueVec[i].first * 5 + j] == "diamond") {
                    if (p == 0) answer += 1;
                    else if (p == 1) answer += 5;
                    else answer += 25;
                } else if (minerals[fatigueVec[i].first * 5 + j] == "iron") {
                    if (p == 0) answer += 1;
                    else if (p == 1) answer += 1;
                    else answer += 5;
                } else {
                    if (p == 0) answer += 1;
                    else if (p == 1) answer += 1;
                    else answer += 1;
                }
            }
        }
    }

    return answer;
}