#include <bits/stdc++.h>
#define max_string_length 405

using namespace std;

stack <char> ops;

bool is_alphabet (char c) {
	if ( (c >= 'a') && (c <= 'z') ) return true;
	else return false;
}

int is_operator (char c) {
	switch ( c ) { 
		case '+' :
			return 1; break;
		case '-' :
			return 2; break;
		case '*' :
			return 3; break;
		case '/' :
			return 4; break;
		case '^' :
			return 5; break;
		default :
			return 0;
	}
}

bool is_left_bracket (char c) {  
	if (c == '(') return true;
	else return false;
}

bool is_right_bracket (char c) {
	if (c == ')') return true;
	else return false;
}

// Dijkstra's Shunting-Yard Algo

void do_work () {
	char str[max_string_length];
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i ++) {
		if (is_alphabet(str[i])) cout << str[i];
		else if (is_operator(str[i])) {
			char top = ops.top();
			while ( (is_operator(top) > is_operator(str[i])) && ( top != '(' ) ) {
				cout << ops.top();
				ops.pop();
				top = ops.top();
			}
			ops.push(str[i]);
		}
		else if (is_left_bracket(str[i])) ops.push(str[i]);
		else if (is_right_bracket(str[i])) {
			while ( !(is_left_bracket(ops.top())) )   {
				cout << ops.top();
				ops.pop();
			}
			ops.pop();
		}
	}
	while (! ops.empty() ) {
		cout << ops.top();
		ops.pop();
	}
	cout << endl;
}

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) do_work();
	return 0;
}
	
