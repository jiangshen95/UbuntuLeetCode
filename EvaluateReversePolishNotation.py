class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for token in tokens:
            if token in ["+", "-", "*", "/"]:
                b, a = stack.pop(), stack.pop()
                if token == "+":
                    stack.append(a+b)
                elif token == "-":
                    stack.append(a-b)
                elif token == "*":
                    stack.append(a*b)
                elif token == "/":
                    stack.append(int(float(a)/b))  # stack.append(a//b) 得到的结果不同，6/(-132) 前者得到的结果是0, 而后者结果室-1
            else:
                stack.append(int(token))
        return stack[-1]
        
if __name__=='__main__':
    n = int(raw_input())
    tokens = []
    for i in range(n):
        s = raw_input()
        tokens.append(s)
    
    solution = Solution()
    print(solution.evalRPN(tokens))
