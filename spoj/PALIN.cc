#include <bits/stdc++.h>
#define max_string_length 1000005

using namespace std;

int max (int a, int b) {
	if (a > b) return a; else return b;
}

bool bigger (char *a, char *b) {
	int len = strlen(a);
	for (int i = 0; i < len; i++)
		if (a[i] > b[i]) return true;
		else if (a[i] < b[i]) return false;
	return false;
}

bool is_number (char a) {
	if ( (a >= '0') && (a <= '9') ) return true; else return false;
}


bool escape_flag = false;

void plus_one (char *a, int full_length) {
	int len = strlen(a);
	for (int i = len - 1; i >= 0; i--) {
		a[i] ++;
		if (is_number(a[i])) return;
		else a[i] -= 10;
	}
	cout << 1;
	for (int i = 0; i < full_length - 1; i++) cout << 0;
	cout << 1 << endl;
	escape_flag = true;
}



void do_work () {
	char raw_str[max_string_length], str[max_string_length], palin_str[max_string_length], half_str[max_string_length];
	memset(raw_str, 0, sizeof(raw_str));
	memset(str, 0, sizeof(str));
	memset(palin_str, 0, sizeof(palin_str));
	memset(half_str, 0, sizeof(half_str));
	cin >> raw_str;
	int raw_len = strlen(raw_str);
	int p = -1;
	for (int i = 0; i < raw_len; i++) if (raw_str[i] != '0') {
		p = i;
		break;
	} 
	if (p != -1) strncpy(str, raw_str + p, raw_len - p); else {
		str[0] = '0';
		str[1] = '\0';
	}
	//cout << str << endl;
	escape_flag = false;
	int len = strlen(str);
	int half_len = len / 2;
	bool is_even_length = false;
	if (len % 2 == 0) is_even_length = true;
	for (int i = 0; i < half_len; i++) {
		half_str[i] = str[i];
		palin_str[i] = str[i];
		palin_str[len - i - 1] = str[i];
	}
	if (!is_even_length) {
		palin_str[half_len] = str[half_len];
		half_str[half_len] = str[half_len];
	}
	//cout << palin_str << endl;
	//cout << half_str << endl;
	if (bigger(palin_str, str)) cout << palin_str << endl; 
	else {
		plus_one(half_str, len);
		//cout << len << endl;
		//cout << half_str << endl;
		if (!escape_flag) {
			//half_len = strlen(half_str);
			memset(palin_str, 0, sizeof(palin_str));
			//cout << half_len << endl;
			for (int i = 0; i < half_len; i++) {
				//cout << palin_str << endl;
				palin_str[i] = half_str[i];
				palin_str[len - i - 1] = half_str[i];
			}
			if (!is_even_length) palin_str[half_len] = half_str[half_len];
			cout << palin_str << endl;
		}
	}
}



int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) do_work();
	return 0;
}	
