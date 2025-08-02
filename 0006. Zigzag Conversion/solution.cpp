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