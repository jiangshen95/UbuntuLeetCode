class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        transitionTable = [
            [-1, 0, 3, 1, 2, -1],
            [-1, 8, -1, 1, 4, 5],
            [-1, -1, -1, 4, -1, -1],
            [-1, -1, -1, 1, 2, -1],
            [-1, 8, -1, 4, -1, 5],
            [-1, -1, 6, 7, -1, -1],
            [-1, -1, -1, 7, -1, -1],
            [-1, 8, -1, 7, -1, -1],
            [-1, 8, -1, -1, -1, -1],
        ]
        statu = 0
        #INVALID=0, SPACE=1, SIGN=2, DIGIT=3, DOT=4, EXPONENT=5;
        for i in s:
            if i==' ':
                statu = transitionTable[statu][1]
            elif i=='+' or i=='-':
                statu = transitionTable[statu][2]
            elif i.isdigit():
                statu = transitionTable[statu][3]
            elif i=='.':
                statu = transitionTable[statu][4]
            elif i=='e' or i=='E':
                statu = transitionTable[statu][5]
            else:
                statu = transitionTable[statu][0]
            if statu == -1:
                return False
        return statu==1 or statu==4 or statu==7 or statu==8
            
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.isNumber(s))

