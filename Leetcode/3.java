class Solution {
	public int lengthOfLongestSubstring(String s) {
		HashSet<Character> appr = new HashSet<>();
		String substring = "";
		int lenS = s.length();
		int maxlen = 0;
		for (int i = 0; i < lenS; i++) {
			char c = s.charAt(i);
			if (!appr.contains(c)) {
				substring += c;
				appr.add(c);
			} else {
				int lenSub = substring.length();
				for (int j = 0; j < lenSub; j++) if (c == substring.charAt(j)) {
					substring = substring.substring(j + 1);
					break;
				}
                substring += c;
			}
			if (substring.length() > maxlen) maxlen = substring.length();
			//System.out.println(substring);
		}
		return maxlen;
	}
}
