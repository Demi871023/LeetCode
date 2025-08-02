# 6. Zigzag Conversion
tags: [#medium][#string]

## Problem Description


The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)


```plaintext
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: "PAHNAPLSIIGYIR"


## Solution

## Key Points


## Code

```cpp
// v1
// runtime: 21ms (beats 18.67%)
// memory: 28.13mb (beats 8.34%)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;
        
        vector<string> rowString(numRows);
        int curRow = 0;
        bool goDown = false;

        for(char c: s) {
            rowString[curRow] = rowString[curRow] + c;
            if (curRow == 0 || curRow == numRows - 1) {
                goDown = !goDown;
            }
            curRow = curRow + (goDown ? 1 : -1);
        }

        string result;
        for(string row: rowString) {
            result = result + row;
        }

        return result;
    }
};

```

