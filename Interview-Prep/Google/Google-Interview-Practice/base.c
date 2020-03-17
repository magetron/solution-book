#include "stdio.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define max_string_length 65

int hash(char c) {
	if ((c >= 'a') && (c <= 'z')) return (c - 'a');
	else if ((c >= '0') && (c <= '9')) return (c - '0' + 26);
	return 0;
}


void do_work(int case_num) {
	char str[max_string_length];
	fgets(str, max_string_length, stdin);
	int len = strlen(str) - 1;
	short int hash_map[36][2];
	for (int i = 0; i < 36; i++) {
		hash_map[i][0] = 0;
		hash_map[i][1] = -1;
	}
	for (int i = 0; i < len; i++) hash_map[hash(str[i])][0] = 1;
	int base = 0;
	for (int i = 0; i < 36; i++) {
		if (hash_map[i][0]) base++;
		//printf("%d ", hash_map[i][0]);
	}
	if (base == 1) base = 2;
	//printf("\n");
	//printf("base = %d\n", base);
	hash_map[hash(str[0])][1] = 1;
	int assign_number = -1;
	for (int i = 1; i < len; i++) if (hash_map[hash(str[i])][1] == -1) {
		assign_number++;
		hash_map[hash(str[i])][1] = assign_number;
		if (assign_number == 0) assign_number = 1;
	}
	//for (int i = 0; i < 36; i++) printf("%d ", hash_map[i][1]);
	//printf("\n");
	long long power = 1;
	long long ans = 0;
	for (int i = len - 1; i >= 0; i--) {
		ans = ans + power * hash_map[hash(str[i])][1];
		power = power * base;
	}
	printf("Case #%d: %lld\n", case_num + 1, ans);
	return;
}


int t;

int main () {
	freopen("base.in", "r", stdin);
	freopen("base.ans", "w", stdout);
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) do_work(i);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
