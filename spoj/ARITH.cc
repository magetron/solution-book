#include <bits/stdc++.h> 
#define expression_length 1005
#define number_length 505

using namespace std;

bool is_operator (char c) {
	if ( (c == '+') || (c == '-') || (c == '*') ) return true; else return false;
}

int max (int a, int b) {
	if (a > b) return a; else return b;
}

void print_expression(short int *a, int a_len, short int *b, int b_len, char op) {
	short int result[expression_length];
	memset(result, 0, sizeof(result));
	int max_len = max(a_len, b_len);
	int result_len = max_len;
	switch ( op ) {
		case '+':
			for (int i = 0; i < max_len; i++) {
				result[i] += a[i] + b[i];
				if (result[i] >= 10) {
					result[i] -= 10;
					result[i + 1] ++;
				}
			}
			if (result[result_len] > 0) result_len ++;
			// test result output
			//for (int i = result_len - 1; i >= 0; i--) cout << result[i];
			//cout << endl;
			if (result_len > max(a_len, b_len + 1)) cout << ' ';
			for (int i = 0; i < b_len + 1 - a_len; i++) cout << ' ';
			for (int i = a_len - 1; i >= 0; i--) cout << a[i];
			cout << endl;
			if (result_len > max(a_len, b_len + 1)) cout << ' ';
			for (int i = 0; i < a_len - b_len - 1; i++) cout << ' ';
			cout << op;
			for (int i = b_len - 1; i >= 0; i--) cout << b[i];
			cout << endl;
			if (result_len > max(a_len, b_len + 1)) cout << '-';
			for (int i = 0; i < max(a_len, b_len + 1); i++) cout << '-';
			cout << endl;
			if ( (result_len == max_len) && (b_len + 1 > a_len) ) cout << ' ';
			for (int i = result_len - 1; i >= 0; i--) cout << result[i];
			cout << endl;
			break;
		case '-':
			for (int i = 0; i < max_len; i++) {
				result[i] += a[i] - b[i];
				if (result[i] < 0) {
					result[i] += 10;
					result[i + 1] --;
				}
			}
			if (result[result_len - 1] == 0) result_len --;
			if (result_len < 1) result_len = 1;
			// test result output
			//for (int i = result_len - 1; i >= 0; i--) cout << result[i];
			//cout << endl;
			for (int i = 0; i < b_len + 1 - a_len; i++) cout << ' ';
			for (int i = a_len - 1; i >= 0; i--) cout << a[i];
			cout << endl;
			for (int i = 0; i < a_len - b_len - 1; i++) cout << ' ';
			cout << op;
			for (int i = b_len - 1; i >= 0; i--) cout << b[i];
			cout << endl;
			for (int i = 0; i < max(a_len, b_len + 1); i++) cout << '-';
			cout << endl;
			if ( result_len < max(a_len, b_len + 1) ) cout << ' ';
			for (int i = result_len - 1; i >= 0; i--) cout << result[i];
			cout << endl;
			break;
	}
}

void do_work () {
	char expression[expression_length];
	cin >> expression;
	cout << "expression = " << expression << endl;
	int exp_len = strlen(expression);
	char op;
	short int a[number_length], b[number_length];
	char a_str[number_length], b_str[number_length];
	memset(a_str, 0, sizeof(a_str));
	memset(b_str, 0, sizeof(b_str));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < exp_len; i++) if (is_operator(expression[i])) {
		op = expression[i];
		strncpy(a_str, expression, i);
		strncpy(b_str, expression + i + 1, exp_len - i - 1);
		break;
	}
	int a_len = strlen(a_str);
	int b_len = strlen(b_str);
	for (int i = a_len - 1; i >= 0; i--) a[a_len - i - 1] = a_str[i] - 48;
	for (int i = b_len - 1; i >= 0; i--) b[b_len - i - 1] = b_str[i] - 48;
	// check string to number conversion
	//for (int i = a_len - 1; i >= 0; i--) cout << a[i];
	//cout << endl;
	//for (int i = b_len - 1; i >= 0; i--) cout << b[i];
	//cout << endl;
	print_expression(a, a_len, b, b_len, op);
	cout << endl;
}



int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	freopen("ARITH.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) do_work();
	fclose(stdin);
	return 0;
}
