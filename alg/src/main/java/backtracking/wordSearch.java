package backtracking;

public class wordSearch {
    public boolean solution (int [][] board, String word) {
        if (board == null || board[0].length == 0 || board.length == 0) return false;
        int m = board.length, n = board[0].length;
        boolean [][] visited = new boolean[m][n];
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean exist(int [][] board, boolean [][] visited, String word, int i, int j, int idx) {
        if (idx == word.length()) return true;
        if (i < 0 || i > board.length || j < 0 || j > board[0].length || 
        visited[i][j] == true || word.charAt(idx) != board[i][j]) {
            return false;
        }
        visited[i][j] = true;
        boolean exi = (exist(board, visited, word, i-1, j, idx+1) || exist(board, visited, word, i+1, j, idx+1) 
        || exist(board, visited, word, i, j-1, idx+1) || exist(board, visited, word, i, j+1, idx+1));
        visited[i][j] = false;
        return exi;
    }
}