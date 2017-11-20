class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        matrix = []
        lo = n*n+1
        while lo>1:
            lo, hi = lo-len(matrix), lo
            matrix = [list(range(lo, hi))] + list(zip(*matrix[::-1]))
            #matrix[::-1] 将matrix中的元素倒过来 [[1,2],[3,4],[5,6]] -> [[5,6],[3,4],[1,2]]
        return matrix
        
if __name__=='__main__':
    n=int(input())
    solution=Solution()
    matrix=solution.generateMatrix(n)
    print(matrix)
