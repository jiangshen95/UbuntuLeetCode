class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        code = [0]
        for i in range(n):
            code += [x + pow(2, i) for x in reversed(code)]
        return code
        
if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    code = solution.grayCode(n)
    print(code)
