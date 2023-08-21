#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<int> cntReported(id_list.size(), 0);
    map<string, vector<string>> reporter;

    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (string r : report) {
        vector<string> splitR;
        stringstream ss(r);
        string temp;
        while(getline(ss, temp, ' ')) splitR.push_back(temp);
        reporter[splitR[1]].push_back(splitR[0]);
        cntReported[find(id_list.begin(), id_list.end(), splitR[1]) - id_list.begin()]++;
    }

    for (int i = 0; i < cntReported.size(); i++) if (cntReported[i] >= k) for (string id : reporter[id_list[i]]) answer[find(id_list.begin(), id_list.end(), id) - id_list.begin()]++;

    return answer;
}