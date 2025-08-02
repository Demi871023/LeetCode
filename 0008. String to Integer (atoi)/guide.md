# 8. String to Integer (atoi)
tags: [#medium] [#string]

## Problem Description


Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

1. **Whitespace**: Ignore any leading whitespace (" ").
2. **Signedness**: Determine the sign by checking if the next character is $-$ or $+$, assuming positivity if neither present.
3. **Conversion**: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is $0$.
4. **Rounding**: If the integer is out of the 32-bit signed integer range $[-2^{31}, 2^{31} - 1]$, then round the integer to remain in the range. Specifically, integers less than $-2^{31}$ should be rounded to $-2^{31}$, and integers greater than $2^{31} - 1$ should be rounded to $2^{31} - 1$.
Return the integer as the final result.



## Solution

## Key Points


## Code

```cpp
// v1
// runtime: 0ms (beats 100%)
// memory: 9.25mb (beats 23.77%)
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

```

