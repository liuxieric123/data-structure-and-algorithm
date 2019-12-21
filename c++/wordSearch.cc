class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board[0].size() == 0 || board.size() == 0 || word.size() == 0)
            return false;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (judge(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool judge(vector<vector<char>>& board, string word, int i, int j, int idx) {
        int row = board.size();
        int col = board[0].size();
        if (idx >= word.size()) return true;
        if (i < 0 || i >= row || j < 0 || j >= col
            || word[idx] != board[i][j]) return false;
        board[i][j] = '\0';
        bool find = judge(board, word, i-1, j, idx+1) || judge(board, word, i+1, j, idx+1)
            || judge(board, word, i, j-1, idx+1) || judge(board, word, i, j+1, idx+1);
        board[i][j] = word[idx];
        return find;

    }
};