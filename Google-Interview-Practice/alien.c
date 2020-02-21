#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define max_word_length 20
#define max_string_length 500
#define max_dict_length 5005
#define max_char_num 26

char dict[max_dict_length][max_word_length];
int l, d, n;

int read_dict(int case_num) {
	fgets(dict[case_num], max_word_length, stdin);
	//printf("%d: %s\n", case_num, dict[case_num]);
	return 0;
}

int do_work(int case_num) {
	printf("Case #%d: ", case_num + 1);
	char str[max_string_length];
	fgets(str, max_string_length, stdin);
	//printf("%s\n", str);
	short int pos[max_word_length][max_char_num];
	memset(pos, 0, sizeof(pos));
	int len = strlen(str);
	int loc = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			int j = i + 1;
			do {
				//printf("%c\n",str[j]);
				pos[loc][str[j] - 'a'] = 1;
				j++;
			} while (str[j] != ')');
			i = j;
		} else if ((str[i] >= 'a') && (str[i] <= 'z')) pos[loc][str[i] - 'a'] = 1;
		loc ++;
	}
	int ans = 0;
	for (int i = 0; i < d; i++) {
		int same = 1;
		for (int j = 0; j < l; j++) if (!pos[j][dict[i][j] - 'a']) {
			same = 0;
			break;
		}
		if (same) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

int main () {
	freopen("alien.in", "r", stdin);
	freopen("alien.ans", "w", stdout);
	scanf("%d %d %d\n", &l, &d, &n);
	for (int i = 0; i < d; i++) read_dict(i);
	for (int i = 0; i < n; i++) do_work(i);
	return 0;
}
