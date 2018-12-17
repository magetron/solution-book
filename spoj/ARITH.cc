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
	}
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
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) do_work();
	return 0;
}


