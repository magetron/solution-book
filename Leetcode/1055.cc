class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < target.length()) {
            //cout << i << " " << source[i] << " " << j << " " << target[j] << endl;
            //cout << ans << endl;
            if (source[i] == target[j]) {
                i++;
                if (j != target.length() - 1 && i == source.length()) {
                    i = 0;
                    ans++;
                }
                j++;
            } else {
                int orgi = i;
                while (i < source.length() && source[i] != target[j]) i++;
                if (i == source.length()) {
                    i = 0;
                    ans++;
                    while (i < orgi && source[i] != target[j]) i++;
                    if (i == orgi) return -1;
                }
            }
        }
        return ans + 1;
    }
};
