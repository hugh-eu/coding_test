#include <string>
#include <algorithm>

using namespace std;

int change_string_to_sec(string &s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}

string change_sec_to_string(int i) {
    return 
        (to_string(i / 60).length() == 2 ? to_string(i / 60) : "0" + to_string(i / 60)) 
        + ":" 
        + (to_string(i % 60).length() == 2 ? to_string(i % 60) : "0" + to_string(i % 60));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_len_sec = change_string_to_sec(video_len);
    int pos_sec = change_string_to_sec(pos);
    int op_start_sec = change_string_to_sec(op_start);
    int op_end_sec = change_string_to_sec(op_end);
    
    if (op_start_sec <= pos_sec && pos_sec <= op_end_sec) pos_sec = op_end_sec;
    
    for (string &command : commands) {
        if (command == "prev") {
            pos_sec = max(0, pos_sec - 10);
        } else if (command == "next") {
            pos_sec = min(pos_sec + 10, video_len_sec);
        }
        if (op_start_sec <= pos_sec && pos_sec <= op_end_sec) pos_sec = op_end_sec;
    }
    
    return change_sec_to_string(pos_sec);
}