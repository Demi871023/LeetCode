class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < len ; i++) {
            // odd, such as "aba"
            pair<int, int> oddP = findPalindromeIndex(i, i, s);
            if (oddP.second - oddP.first > end - start) {
                start = oddP.first;
                end = oddP.second;
            }
            // even, such as "abba"
            pair<int, int> evenP = findPalindromeIndex(i, i+1, s);
            if (evenP.second - evenP.first > end - start) {
                start = evenP.first;
                end = evenP.second;
            }
        }

        return s.substr(start, end - start + 1);
    }
private:
    pair<int, int> findPalindromeIndex(int left, int right, const string& s) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left+1, right-1};
    }
};