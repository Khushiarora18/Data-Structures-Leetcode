class Solution {
private:
    // Helper function to check if it's safe to place a queen at (i, j)
    bool isSafe(vector<vector<int>>& board, int i, int j, int n) {
        for (int row = 0; row < i; row++) {
            if (board[row][j]) {
                return false;  // There's already a queen in the same column
            }
        }
        
        int x = i, y = j;
        while (x >= 0 && y < n) {
            if (board[x][y]) {
                return false;  // There's a queen on the diagonal from top-left to bottom-right
            }
            x--;
            y++;
        }
        
        x = i;
        y = j;
        while (x >= 0 && y >= 0) {
            if (board[x][y]) {
                return false;  // There's a queen on the diagonal from top-right to bottom-left
            }
            x--;
            y--;
        }
        
        return true;  // It's safe to place a queen at (i, j)
    }

    // Helper function to solve the N-Queens problem using backtracking
    bool nQueen(vector<vector<int>>& board, int i, int n) {
        if (i == n) {
            // The board is filled, and we've successfully placed queens
            // Print the board and add it to the results
            vector<string> solution;
            for (int row = 0; row < n; row++) {
                string rowStr = "";
                for (int col = 0; col < n; col++) {
                    rowStr += (board[row][col] == 1) ? "Q" : ".";
                }
                solution.push_back(rowStr);
            }
            result.push_back(solution);
            return true;
        }
        
        for (int j = 0; j < n; j++) {
            if (isSafe(board, i, j, n)) {
                board[i][j] = 1;  // Place a queen at (i, j)
                bool isPlaced = nQueen(board, i + 1, n);  // Try placing the next queen
                board[i][j] = 0;  // Backtrack and remove the queen
            }
        }
        return false;
    }

public:
    // Public function to solve N-Queens and return the results
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));  // Initialize an empty board
        nQueen(board, 0, n);  // Start solving from the first row (row 0)
        return result;
    }
private:
    vector<vector<string>> result;  // Store the results for N-Queens solutions
};
