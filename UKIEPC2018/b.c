#include "stdio.h"
#include "string.h"
#define max_b 50
#define max_s 50

int m,b,s;
int b_s[max_b][max_s];
int a_s[max_s];
int ans = 0;
char tmp;


void init() {
	memset(b_s, 0, sizeof(b_s));
	memset(a_s, 0, sizeof(a_s));
	return;
}


int main () {
	init();
	scanf("%d %d %d", &m, &b, &s);
	m--;	
	for (int i = 0; i < b; i++) {
		scanf("%c", &tmp);	
		for (int j = 0; j < s; j++) { 
			scanf("%c", &tmp);
			b_s[i][j] = tmp - '0';
		}
	}

	for (int i = 0; i < b; i++) if (b_s[i][m])
		for (int j = 0; j < s; j++) if (b_s[i][j]) a_s[j] = 1;
	

	for (int j = 0; j < s; j++) if ((a_s[j]) && (j != m)) ans++;

	printf("%d\n",ans);
	return 0;
}
