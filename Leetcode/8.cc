#include <bits/stdc++.h>

using namespace std;

class Solution {
public:


	bool is_num (char c) {
		return c >= 48 && c <= 58;
	}
	
	
	bool sanitize (string& str) {
		for (int i = 0; i < str.length(); i++) if (str.at(i) != ' ') { 
			str = str.substr(i, str.length() - i);
			break;
		}
		//cout << str << endl;
		if (str.length() == 0) return false;
		bool sign = false;
		if (str.at(0) == '+') {
			str = str.substr(1, str.length() - 1);
			sign = true;
		}
		if (!str.size()) return false;
		int i = 0;
		bool has_num = false;
		while (i < str.size()) {
			if (sign && str.at(i) == '-' && i == 0) return false;
			if (!sign && str.at(i) == '-' && i == 0) i++;
			if (i >= str.size()) return false;
			if (!has_num && is_num(str.at(i))) has_num = true;
			else if (has_num && !is_num(str.at(i))) {
				str = str.substr(0, i);
				return true;
				break;
			}
			else if (!has_num && !is_num(str.at(i))) return false;
			i++;
		}
		return true;
	}

    int myAtoi(string str) {
		bool valid = sanitize(str);
		if (!valid) return 0;
		cout << str << endl;
		long long num = 0;
		bool negative = str.at(0) == '-';
		for (auto it = str.begin(); it != str.end(); it++) if (*it != '-') {
			num = num * 10 + *it - 48;
			if (!negative && num > INT_MAX) return INT_MAX;
			if (negative && num > -(long)INT_MIN) return INT_MIN;
		}
		return negative ? - num : num;
    }
};

int main () {
	Solution s;
	string str("+-2");
	cout << s.myAtoi(str) << endl;
	return 0;
}
