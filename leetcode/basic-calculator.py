class Solution:
    def calculate(self, s: str) -> int:
        res, sign, num = 0, 1, 0
        stack = []

        for ch in s:
            if ch == ' ':
                continue

            if '0' <= ch <= '9':
                num = num * 10 + (ord(ch) - ord('0'))
                continue

            res += sign * num
            num = 0

            if ch in '+-':
                sign = 1 if ch == '+' else -1
            elif ch == '(':
                stack.append((res, sign))
                res, sign = 0, 1
            elif ch == ')':
                prev_res, prev_sign = stack.pop()
                res = prev_res + prev_sign * res
        
        return res + num * sign