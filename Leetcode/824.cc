class Solution {
public:
    
    inline bool is_vowel (char c) {
        return (c == 'a' || c== 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c== 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
    string toGoatLatin(string S) {
        string ans;
        int i = 0;
        int c = 0;
        while (i < S.length()) {
            int j = i + 1;
            while (j < S.length() && S[j] != ' ') j++;
            string word = S.substr(i, j - i);
            c++;
            if (is_vowel(word[0])) {
                word += "ma";
            } else {
                char schar = word[0];
                word.erase(word.begin());
                word.push_back(schar);
                word += "ma";
            }
            for (int k = 0; k < c; k++) word.push_back('a');
            ans += word + " ";
            i = j + 1;
            //cout << ans << endl;
        }
        ans.pop_back();
        return ans;
    }
};
