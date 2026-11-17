
class Solution {
public:
    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& col,
               vector<int>& leftDiagonal,
               vector<int>& rightDiagonal) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            int ld = row + c;
            int rd = row - c + n - 1;

            if (col[c] == 0 &&
                leftDiagonal[ld] == 0 &&
                rightDiagonal[rd] == 0) {

                board[row][c] = 'Q';

                col[c] = 1;
                leftDiagonal[ld] = 1;
                rightDiagonal[rd] = 1;

                solve(row + 1, n, board, ans,
                      col, leftDiagonal, rightDiagonal);

                board[row][c] = '.';

                col[c] = 0;
                leftDiagonal[ld] = 0;
                rightDiagonal[rd] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> leftDiagonal(2 * n - 1, 0);
        vector<int> rightDiagonal(2 * n - 1, 0);

        solve(0, n, board, ans, col,
              leftDiagonal, rightDiagonal);

        return ans;
    }
};
