class Solution {
public:
    
    vector<int> pre;
    
    int find (int x) {
        int cpy = x;
        while (pre[x] != x) {
            x = pre[x];
        }
        while (pre[cpy] != x) {
            int tmp = pre[cpy];
            pre[cpy] = x;
            cpy = tmp;
        }
        return x;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        if (!m) return 0;
        pre = vector<int>(m);
        for (int i = 0; i < m; i++) pre[i] = i;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) if (M[i][j] == 1) {
                int x = find(i);
                int y = find(j);
                pre[x] = y;
            }
        int ans = 0;
        for (int i = 0; i < m; i++) if (pre[i] == i) ans++;
        return ans;
    }
};
