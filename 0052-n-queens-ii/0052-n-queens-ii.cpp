class Solution {
private:
    // Helper function to solve the N-Queens problem using backtracking
    int help(vector<bool>& col, vector<bool>& diag, vector<bool>& noDiag, int row) {
        int n = col.size();
        int count = 0;

        // Base case: If we've successfully placed queens in all rows, return 1
        if (row == n) {
            return 1;
        }

        // Try placing a queen in each column of the current row
        for (int column = 0; column < n; column++) {
            // Check if it's safe to place a queen in this position
            if (!col[column] && !diag[row + column] && !noDiag[row - column + n - 1]) {
                // Place a queen and mark the corresponding columns and diagonals
                col[column] = diag[row + column] = noDiag[row - column + n - 1] = true;

                // Recursively try to place queens in the next row
                count += help(col, diag, noDiag, row + 1);

                // Backtrack by removing the queen and resetting the marks
                col[column] = diag[row + column] = noDiag[row - column + n - 1] = false;
            }
        }
        
        return count;
    }

public:
    // Public function to count the total number of solutions for N-Queens
    int totalNQueens(int n) {
        vector<bool> col(n, false);          // Tracks whether a column is occupied
        vector<bool> diag(2 * n - 1, false);  // Tracks main diagonals
        vector<bool> noDiag(2 * n - 1, false);  // Tracks anti-diagonals

        // Call the helper function to start solving from the first row (row 0)
        return help(col, diag, noDiag, 0);
    }
};
