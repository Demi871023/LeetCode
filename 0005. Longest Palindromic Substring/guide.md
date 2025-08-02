# 5. Longest Palindromic Substring
tags: [#medium] [#two_pointers] [#string] [#dynamic_programming]

## Problem Description


Given a string s, return the longest palindromic substring in s.
> palindromic substring: A substring is a contiguous non-empty sequence of characters within a string.

## Example
**Example 1**
```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```
***Example 2**
```
Input: s = "cbbd"
Output: "bb"
```


## Solution

## Key Points
* Expand Around Center $time: O(n^2), space: O(1)$
* （C++11/14）：Using pair to handle two return value.
```
pair<int, int> p = func(parameter);
start = p.first;
end = p.second;
```
* （C++17）：Using "Structured Binding" to handle
```
auto [start, end] = func((parameter));
```

## Code

```cpp
// v1
// runtime: 43ms (beats 52.13%)
// memory: 9.28mb (beats 92.64%)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < len ; i++) {
            pair<int, int> oddP = findPalindromeIndex(i, i, s);
            if (oddP.second - oddP.first > end - start) {
                start = oddP.first;
                end = oddP.second;
            }
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
```

