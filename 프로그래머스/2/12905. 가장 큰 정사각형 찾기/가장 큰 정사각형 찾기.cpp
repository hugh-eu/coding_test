#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) for (int j = 0; j < board[i].size(); j++) {
        board[i][j] 
                = board[i][j] 
                + (i - 1 >= 0 ? board[i-1][j] : 0) 
                + (j - 1 >= 0 ? board[i][j-1] : 0) 
                - (i - 1 >= 0 && j - 1 >= 0 ? board[i-1][j-1] : 0);
    }
    
    int maxLenSide = min({board.size(), board[0].size(), (unsigned long)sqrt(board[board.size()-1][board[0].size()-1])});

    for (int lenSide = maxLenSide; lenSide > 0; lenSide--) {
        for (int rowStart = 0; rowStart <= board.size() - lenSide; rowStart++) for (int colStart = 0; colStart <= board[0].size() - lenSide; colStart++) {
            int rowEnd = rowStart + lenSide - 1;
            int colEnd = colStart + lenSide - 1;
            if (pow(lenSide, 2) 
                    == board[rowEnd][colEnd] 
                    - (rowStart - 1 >= 0 ? board[rowStart-1][colEnd] : 0) 
                    - (colStart - 1 >= 0 ? board[rowEnd][colStart-1] : 0) 
                    + (rowStart - 1 >= 0 && colStart - 1 >= 0 ? board[rowStart-1][colStart-1] : 0)) {
                return pow(lenSide, 2);
            }
        }
    }

    return 0;
}