class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            int cr = 0, cc = 0, cb = 0;
            unordered_set<int> r, c, b;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {        // For checking Rows
                    r.insert(board[i][j]);
                    if(r.size() != ++cr)        return false;
                }
                if(board[j][i] != '.') {        // For checking Columns
                    c.insert(board[j][i]);
                    if(c.size() != ++cc)        return false;
                }
                if(board[j/3 + 3*(i/3)][j%3 + 3*(i%3)] != '.') {        // For checking 3x3 Boxes
                    b.insert(board[j/3 + 3*(i/3)][j%3 + 3*(i%3)]);
                    if(b.size() != ++cb)        return false;
                }
            }           
        }
        return true;
    }
};