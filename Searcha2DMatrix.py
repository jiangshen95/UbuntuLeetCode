class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n == 0:
            return False
        l = 0
        r = m*n-1
        while l<=r:
            mid = (l+r)//2
            if matrix[mid//n][mid%n]>target:
                r = mid-1
            elif matrix[mid//n][mid%n]<target:
                l = mid+1
            else:
                break
        return matrix[mid//n][mid%n]==target
        
if __name__=='__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        raw = list(input())
        matrix.append(raw)
    target = int(input())
    solution = Solution()
    print(solution.searchMatrix(matrix, target))
