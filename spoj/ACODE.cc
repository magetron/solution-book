#include <bits/stdc++.h>
#define max_string_length 5005

using namespace std;

char str[max_string_length];

bool is_zero (char *str) {
	if ( (str[0] == '0') && (str[1] == '\n') ) return true;
	else return false;
}

bool not_zero (char c) {
	if ( (c >= '1') && (c <= '9') ) return true;
	else return false;
}

bool is_alphabet (char a, char b) {
	int tmp = ( a - 48 ) * 10 + ( b - 48 );
	if ( (tmp >= 10) && (tmp <= 26) ) return true;
	else return false;
}

void do_work () {
	do {
		fgets(str, max_string_length, stdin);
		if ( !is_zero(str) ) {
			int len = strlen(str);
			len--; //fgets picks up '\n'
			int ans[max_string_length];
			memset(ans, 0, sizeof(ans));
			ans[0] = 1;
			ans[1] = 1;
			for (int i = 2; i <= len; i++) {
				if ( not_zero(str[i - 1]) ) ans[i] = ans[i - 1];
				if ( not_zero(str[i - 2]) && is_alphabet(str[i - 2], str[i - 1]) ) ans[i] += ans[i - 2];
				//cout << "str[ " << i - 1 << " ] = " << str[i - 1] << endl;
				//cout << "ans[ " << i << " ] = " << ans[i] << endl; 
			}
			cout << ans[len] << endl;
		}
	} while ( !is_zero(str) );
}


int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("ACODE.in", "r", stdin);
	memset(str, 0, sizeof(str));
	do_work();
	//fclose(stdin);
	return 0;
}

