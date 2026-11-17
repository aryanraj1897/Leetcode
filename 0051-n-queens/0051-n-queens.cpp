
class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row, int n, int col,
               int leftDiag, int rightDiag,
               vector<string>& board) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        int mask = (1 << n) - 1;

        int available = mask & ~(col | leftDiag | rightDiag);

        while (available) {

            int bit = available & -available;

            available -= bit;

            int c = __builtin_ctz(bit);

            board[row][c] = 'Q';

            solve(row + 1, n,
                  col | bit,
                  (leftDiag | bit) << 1,
                  (rightDiag | bit) >> 1,
                  board);

            board[row][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        ans.clear();

        vector<string> board(n, string(n, '.'));

        solve(0, n, 0, 0, 0, board);

        return ans;
    }
};
