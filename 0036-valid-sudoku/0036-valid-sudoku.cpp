class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         vector<unordered_set<int>> rows(9);
    vector<unordered_set<int>> cols(9);
    vector<unordered_set<int>> boxes(9);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch != '.') {
                int num = ch - '0';
                int boxIndex = (i / 3) * 3 + j / 3;
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false;
                }
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
    }
    
    return true;
    }
};