#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) result.push_back(temp);

    return result;
}

int calcMin(string time) {
    vector<string> splitTime = split(time, ':');

    return stoi(splitTime[0]) * 60 + stoi(splitTime[1]);
}

int calcFee(vector<int> &fees, int minutes) {
    int fee = 0;
    minutes -= fees[0];
    fee += fees[1];
    if (minutes > 0) fee += ceil(minutes / (float)fees[2]) * fees[3];

    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, int> totalMins;
    unordered_map<string, int> log;
    for (string r : records) {
        vector<string> splitRecord = split(r, ' ');
        if (splitRecord[2] == "IN") log[splitRecord[1]] = calcMin(splitRecord[0]);
        else {
            totalMins[splitRecord[1]] += calcMin(splitRecord[0]) - log[splitRecord[1]];
            log.erase(splitRecord[1]);
        }
    }
    if (!log.empty()) {
        auto iter = log.begin();
        while (iter != log.end()) {
            totalMins[iter->first] += 1439 - iter->second;
            iter++;
        }
    }
    auto iter = totalMins.begin();
    while (iter != totalMins.end()) {
        answer.push_back(calcFee(fees, iter->second));
        iter++;
    }

    return answer;
}