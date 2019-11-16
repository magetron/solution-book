#include "stdio.h"
#include "stdlib.h"
#define MAX_LEN 500000

// A C G T

int f (char ch) {
	switch (ch) {
		case 'A' : return 0; break;
		case 'C' : return 1; break;
		case 'G' : return 2; break;
		case 'T' : return 3; break;
	}
	return 0;
}

short int valid (int *arr, int std) {
	for (int i = 0; i < 4; i++) if (arr[i] > std) return 0;
	return 1;
}

short int check (int h, int t, int len, int **dict) {
	int *arr = malloc(sizeof(int) * 4);
	if (h == 0)  
		for (int i = 0; i < 4; i++) arr[i] = dict[len - 1][i] - dict[t][i];
	else
		for (int i = 0; i < 4; i++) arr[i] = dict[len - 1][i] - dict[t][i] + dict[h - 1][i];
	//for (int i = 0; i < 4; i++) printf("%d ", arr[i]);
	//printf("\n");
	return valid(arr, len / 4);
}

int minlen (int *arr, int std) {
	int sum = 0;
	for (int i = 0; i < 4; i++) if (arr[i] > std) sum += arr[i] - std;
	return sum;
}



int main () {
	freopen("b.in", "r", stdin);
	int len;
	scanf("%d\n", &len);
	char *str = malloc(sizeof(char) * MAX_LEN);
	fgets(str, MAX_LEN, stdin);
	int **dict = malloc(sizeof(int *) * len); 
	dict[0] = malloc(sizeof(int) * 4);
	dict[0][0] = 0;
	dict[0][1] = 0;
	dict[0][2] = 0;
	dict[0][3] = 0;
	dict[0][f(str[0])]++;
	int head = -1;
	int std = len / 4;
	for (int i = 1; i < len; i++) {
		dict[i] = malloc(sizeof(int) * 4);
		for (int j = 0; j < 4; j++) dict[i][j] = dict[i - 1][j];
		dict[i][f(str[i])]++;
		//for (int j = 0; j < 4; j++) printf("%d ", dict[i - 1][j]);
		//printf("\n");
		if (head == -1 && !valid(dict[i], std)) head = i;
	}
	printf("%d\n", head);
	int tail = -1;
	for (int i = len - 2; i >= 0; i--) {
		int *cur = malloc(sizeof(int) * 4);
		for (int j = 0; j < 4; j++) cur[j] = dict[len - 1][j] - dict[i][j];
		if (tail == -1 && !valid(cur, std)) {
			tail = i;
			break;
		}
		free(cur);
	}
	printf("%d\n", tail);
	int min_len = minlen(dict[len - 1], std);
	printf("%d\n", min_len);
	int h = head;
	int t = tail;
	if (t - h + 1 < min_len) h -= min_len - (t - h + 1);
	while (h >= 0) {
		//printf("min_len = %d\n", min_len);
		while (h <= head && t >= tail) {
			//printf("%d %d\n", h, t);
			if (check(h, t, len, dict)) {
				printf("%d", t - h + 1);
				return 0;
			}
			h++;
			t++;
		}
		min_len++;
		h = head - (min_len - (tail - head + 1));
		t = tail;
		//printf("\n");
	}
	fclose(stdin);
	return 0;
}

