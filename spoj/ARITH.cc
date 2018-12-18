#include <bits/stdc++.h>
#define expression_length 1005
#define number_length 505

using namespace std;

int max (int a, int b) {
	if (a > b) return a; else return b;
}

bool is_operand (char c) {
	if ( (c == '+') || (c == '-') || (c == '*') ) return true;
	else return false;
}

void upper_output (char* a, char* b, char op) {
	if ( (op == '+') || (op == '-') ) { 
		int a_len = strlen(a);
		int b_len = strlen(b);
		if (a_len > b_len) {
			int gap = a_len - b_len;
			cout << " ";
			cout << a << endl;
			cout << op;
			for (int i = 0; i < gap; i++) cout << " ";
			cout << b << endl;
		} else {
			int gap = b_len - a_len;
			cout << " ";
			for (int i = 0; i < gap; i++) cout << " ";
			cout << a << endl;
			cout << op;
			cout << b << endl;
		}
		int line_len = max(a_len, b_len) + 1;
		for (int i = 0; i < line_len; i++) cout << '-';
		cout << endl;
	}
}

void prec_plus (char *a, char *b) {
	short int a_num[number_length];
	short int b_num[number_length];
	memset(a_num, -1, sizeof(a_num));
	memset(b_num, -1, sizeof(b_num));
	int a_len = strlen(a);
	int b_len = strlen(b);
	for (int i = a_len - 1; i >= 0; i--) a_num[a_len - i - 1] = a[i] - 48;
	for (int i = b_len - 1; i >= 0; i--) b_num[b_len - i - 1] = b[i] - 48;
	int result[number_length];
	memset(result, 0, sizeof(result));
	int result_len = max(a_len, b_len);
	for (int i = 0; i < result_len; i++) {
		int tmp_a, tmp_b;
		if (i > a_len - 1) tmp_a = 0; else tmp_a = a_num[i];
		if (i > b_len - 1) tmp_b = 0; else tmp_b = b_num[i];
		result[i] += tmp_a + tmp_b;
		if (result[i] >= 10) {
			result[i] -= 10;
			result[i + 1] += 1;
		}
	}
	if (result[result_len] > 0) result_len++; else cout << " ";
	for (int i = result_len - 1; i >= 0; i--) cout << result[i];
	cout << endl;
	return;
}

void prec_minus (char *a, char *b) {
	short int a_num[number_length];
	short int b_num[number_length];
	memset(a_num, -1, sizeof(a_num));
	memset(b_num, -1, sizeof(b_num));
	int a_len = strlen(a);
	int b_len = strlen(b);
	for (int i = a_len - 1; i >= 0; i--) a_num[a_len - i - 1] = a[i] - 48;
	for (int i = b_len - 1; i >= 0; i--) b_num[b_len - i - 1] = b[i] - 48;
	int result[number_length];
	memset(result, 0, sizeof(result));
	int result_len = max(a_len, b_len);
	for (int i = 0; i < result_len; i++) {
		int tmp_a, tmp_b;
		if (i > a_len - 1) tmp_a = 0; else tmp_a = a_num[i];
		if (i > b_len - 1) tmp_b = 0; else tmp_b = b_num[i];
		result[i] += tmp_a - tmp_b;
		if (result[i] < 0) {
			result[i] += 10;
			result[i + 1] -= 1;
		}
	}
	cout << " ";
	bool prefix_zero = true;
	for (int i = result_len - 1; i > 0; i--) {
		if (result[i] > 0) prefix_zero = false; 
		if (prefix_zero) cout << " "; else cout << result[i];
	}
	cout << result[0] << endl;
}

void result (char *a, char *b, char op) {
	if ( op == '+' ) prec_plus(a, b);
	if ( op == '-' ) prec_minus(a, b);
}
		


void do_work () {
	char expression[expression_length];
	char a[number_length], b[number_length];
	char op;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	cin >> expression;
	int exp_len = strlen(expression);
	for (int i = 0; i < exp_len; i++) if (is_operand(expression[i])) {
		op = expression[i];
		strncpy(a, expression, i);
		strncpy(b, expression + i + 1, exp_len - i - 1);
		break;
	}
	upper_output(a, b, op);
	result(a, b, op);
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) do_work();
	return 0;
}


