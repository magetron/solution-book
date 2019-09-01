class Solution {
	public int romanToInt(String s) {
		//int stage = 0;
		s += " ";
		int lenS = s.length();
		int ans = 0;
		for (int i = 0; i < lenS; i++) {
			char c = s.charAt(i);
			switch (c) {
				case 'M':
					//stage = 1;
					ans += 1000;
					break;
				case 'D':
					//stage = 1;
					ans += 500;
					break;
				case 'C':
					if (s.charAt(i + 1) == 'D') {
						i++;
						ans += 400;
					} else if (s.charAt(i + 1) == 'M') {
						i++;
						ans += 900;
					} else ans += 100;
					break;
				case 'L':
					ans += 50;
					break;
				case 'X':
					if (s.charAt(i + 1) == 'L') {
						i++;
						ans += 40;
					} else if (s.charAt(i + 1) == 'C') {
						i++;
						ans += 90;
					} else ans += 10;
					break;
				case 'V':
					ans += 5;
					break;
				case 'I':
					if (s.charAt(i + 1) == 'V') {
						i++;
						ans += 4;
					} else if (s.charAt(i + 1) == 'X') {
						i++;
						ans += 9;
					} else ans += 1;
					break;
			}
		}
		return ans;
	}
}
