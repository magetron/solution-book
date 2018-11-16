n_max = 201;
ans = [[0 for i in range (n_max)] for j in range(n_max)];

def answer(n):
    dp(n);
    #print(ans);
    return ans[n][n] - 1;

def dp(n):
    ans[1][1] = 1;
    ans[2][2] = 1;

    for i in range (3, n + 1):
        for j in range (1, i + 1):
            if i == j:
                ans[i][j] = ans[i][j - 1] + 1;
            elif i - j >= j:
                ans[i][j] = ans[i][j - 1] + ans[i - j][j - 1];
            elif i - j < j:
                ans[i][j] = ans[i][j - 1] + ans[i - j][i - j];

#print(answer(3));
#print(answer(200));

