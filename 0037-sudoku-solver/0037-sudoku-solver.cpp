class Solution {
    private:
    bool isValid(vector<vector<char>>&board, int row, int col, char x){
        for(int i=0; i<9; i++){
            if(board[i][col] == x) return false;
            if(board[row][i] == x) return false;

            if(board[3*(row/3)+ i/3][3*(col/3)+i%3]==x) return false;
        }
        return true;
    }
    bool place(vector<vector<char>>&board){
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c<= '9'; c++){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            if(place(board) == true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        place(board);
        
    }
};