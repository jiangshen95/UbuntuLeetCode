class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        row = [1]
        for i in range(1, rowIndex+1):
            row += [0]
            for j in range(i, 0, -1):
                row[j] += row[j-1]
        return row
        
if __name__=='__main__':
    rowIndex = int(raw_input())
    solution = Solution()
    print(solution.getRow(rowIndex))
