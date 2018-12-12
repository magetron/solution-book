#include <bits/stdc++.h>
#define expression_length 1005
#define number_length 505

using namespace std;


bool is_operand (char c) {
	if ( (c == '+') || (c == '-') || (c == '*') ) return true;
	else return false;
}

void do_work () {
	char expression[expression_length];
	char a[number_length], b[number_length];
	cin >> expression;
	int exp_len = strlen(expression);
	for (int i = 0; i < exp_len; i++) if (is_operand(expression[i])) {
		strncpy(a, expression, i);
		strncpy(b, expression + i + 1, exp_len - i);
	}
	cout << a << endl;
	cout << b << endl;
}
	


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) do_work();
	return 0;
}


