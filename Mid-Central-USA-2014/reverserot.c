#include "stdio.h"
#include "string.h"
#define max_string_length 40

void forward(char str[max_string_length], int n) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == '_') str[i] = 91;
		if (str[i] == '.') str[i] = 92;
		str[i] += n;
		if (str[i] > 92) str[i] -= 28;
		if (str[i] == 91) str[i] = '_';
		if (str[i] == 92) str[i] = '.';
	}
	for (int i = len - 1; i >=0; i--) if ((str[i] >= 'A') && (str[i] <= 'Z') || (str[i] == '_') || (str[i] == '.' )) printf("%c", str[i]);
	printf("\n");
}

char str[max_string_length];
int t,n; 

int main () {
	//freopen("reverserot.in", "r", stdin);
	//freopen("reverserot.out", "w", stdout);
	do{
		scanf("%d ",&n);
		if (n != 0) {
			fgets(str, max_string_length, stdin);
			//printf("%d %s", n, str);
			forward(str, n);
		}
	} while (n != 0);
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}

	
