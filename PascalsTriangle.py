class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        if numRows<=0:
            return result
        result.append([1])
        for i in range(1, numRows):
            row = [1]
            for j in range(1, i):
                row.append(result[-1][j]+result[-1][j-1])
            row.append(1)
            result.append(row)
        return result
        
if __name__=='__main__':
    numRows = int(raw_input())
    solution = Solution()
    result = solution.generate(numRows)
    print(result)
