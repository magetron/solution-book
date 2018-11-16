#include "stdio.h"
#include "string.h"
#define max_string_length 1005


void do_work(int case_num) {
	char str[max_string_length];
	fgets(str, max_string_length, stdin);
	int len = strlen(str);
	int start_loc = len - 2;
	int end_loc = len - 2;
	printf("Case #%d: ", case_num + 1);
	for (int i = len - 2; i >= 0; i--) {
		if ((str[i] == ' ') || (i == 0)) {
			if (i == 0) end_loc = i; else end_loc = i + 1;
			for (int j = end_loc; j <= start_loc; j++) printf("%c", str[j]);
			start_loc = i - 1;
			printf(" ");
		}
	}
	printf("\n");
}

int n;

int main () {
	freopen("reverse.in", "r", stdin);
	freopen("reverse.ans", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) do_work(i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

