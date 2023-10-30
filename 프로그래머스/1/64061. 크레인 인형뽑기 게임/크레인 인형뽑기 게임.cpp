#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    
    for (int i = 0; i < moves.size(); i++) {
        int c = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][c] > 0) {
                if (basket.size() > 0 && basket.back() == board[j][c]) {
                    basket.pop_back();
                    answer += 2;
                } else basket.push_back(board[j][c]);
                board[j][c] = 0;
                break;
            }
        }
        
        
    }
    
    return answer;
}