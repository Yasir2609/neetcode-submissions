class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Row check
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;

            for (char c : board[i]) {
                if (c == '.') continue;

                if (seen.count(c))
                    return false;

                seen.insert(c);
            }
        }

        // Column check
        for (int col = 0; col < m; col++) {
            unordered_set<char> seen;

            for (int row = 0; row < n; row++) {
                char c = board[row][col];

                if (c == '.') continue;

                if (seen.count(c))
                    return false;

                seen.insert(c);
            }
        }

        // 3x3 Grid check
        for (int startRow = 0; startRow < 9; startRow += 3) {
            for (int startCol = 0; startCol < 9; startCol += 3) {

                unordered_set<char> seen;

                for (int i = startRow; i < startRow + 3; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        char c = board[i][j];

                        if (c == '.') continue;

                        if (seen.count(c))
                            return false;

                        seen.insert(c);
                    }
                }
            }
        }

        return true;
    }
};