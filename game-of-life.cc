class Solution {
public:
    
    vector<pair<int, int>> dir{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (!n) return;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dir[k].first;
                    int y = j + dir[k].second;
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) cnt++; 
                }
                if (board[i][j] == 1) {
                    if (cnt < 2) board[i][j] = 2;
                    else if (cnt > 3) board[i][j] = 2;
                } else if (board[i][j] == 0) {
                    if (cnt == 3) board[i][j] = 3;
                }
            }
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) if (board[i][j] == 2) board[i][j] = 0; else if (board[i][j] == 3) board[i][j] = 1;
        return;
    }
};
