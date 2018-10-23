#include "stdio.h"
#include "string.h"

const int max_string_length = 310;

int main () {
	char str[max_string_length];
	fgets(str, sizeof(str), stdin);
	int len = strlen(str);
	int ans = 0;
	char per[3] = "PER";
	for (int i = 0; i < len - 1; i++) {
		char tmp = str[i];
		if ((i % 3 == 0) && (tmp != per[0])) ans++;
		else if ((i % 3 == 1) && (tmp != per[1])) ans++;
		else if ((i % 3 == 2) && (tmp != per[2])) ans++;
	}
	printf("%d",ans);
	return 0;
}
