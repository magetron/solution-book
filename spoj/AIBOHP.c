#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_string_length 6105


int max (int a, int b) {
	return a > b ? a : b;
}

int lcs (char *strx, char * stry, int m, int n) {
	int ans[m + 1][n + 1];
	for (int i = 0; i <=m ; i++) 
		for (int j = 0; j <= n; j++) 
			if ( (i == 0) || (j == 0) ) ans[i][j] = 0;
			else if ( strx[i - 1] == stry[j - 1] )
				ans[i][j] = ans[i - 1][j - 1] + 1;
			else ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
	return ans[m][n];
}


void do_work () {
	char str[max_string_length];
	fgets(str, max_string_length, stdin);
	int len = strlen(str) - 1;
	char rev_str[max_string_length];
	for (int i = len - 1; i >= 0; i--) rev_str[len - 1 - i] = str[i];
	rev_str[len] = '\0';
	//printf("%s %d %s %d\n", str, len, rev_str, strlen(rev_str));
	printf("%d\n", len - lcs(str, rev_str, len, len));
	//printf("-------\n");
	return;
}


int main () {
	//freopen("AIBOHP.in", "r", stdin);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) do_work();
	//fclose(stdin);
	return 0;
}
