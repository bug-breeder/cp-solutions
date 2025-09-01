// (1-(4+35 - (2 - 1 ) +2)-(3-2))+(6+8)
// "- (3 + ( 4 + 5))"


class Solution {
private:
    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    
public:
    int calculate(string s) {
        int64_t curResult = 0;
        int64_t sign = 1, curNum = 0;
        stack<pair<int64_t, int64_t>> opStack;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ') {
                continue;
            }

            if (isDigit(ch)) {
                curNum = curNum * 10 + (ch - '0');
                continue;
            }

            curResult += sign * curNum;
            curNum = 0;

            if (ch == '+' || ch == '-') {
                sign = (ch == '+' ? 1: -1);
            } else if (ch == ')') {
                auto [lastNum, lastOp] = opStack.top(); 
                opStack.pop();
                curResult = lastNum + lastOp * curResult;
            } else if (ch == '(') {
                opStack.push({curResult, sign});
                curResult = 0;
                sign = 1;
            }
        }

        return curResult + curNum * sign;
    }
};