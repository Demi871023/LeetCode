class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int len = s.length();
        bool isNegative = false;
        int result = 0;
        while(i < len && s[i] == ' ') {
            i++;
        }

        if (i < len && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') { isNegative = true; }
            i++;
        }

        while(i < len && (s[i] <= int('9') && s[i] >= int('0'))) {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + digit;
            i++;
        }

        return isNegative ? -1 * result : result;
    }
};