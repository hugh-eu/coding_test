#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, vector<string>> reporter;

    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (string s : report) {
        vector<string> splitR;
        stringstream ss(s);
        string temp;
        while(getline(ss, temp, ' ')) splitR.push_back(temp);
        reporter[splitR[1]].push_back(splitR[0]);
    }

    for (auto r : reporter) if (r.second.size() >= k) for (string s : r.second) answer[find(id_list.begin(), id_list.end(), s) - id_list.begin()]++;

    return answer;
}