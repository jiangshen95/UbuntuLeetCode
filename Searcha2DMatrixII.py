class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0:
            return False
        if len(matrix[0]) == 0:
            return False
        m = len(matrix)
        n = len(matrix[0])

        raw = 0
        col = n - 1
        while raw < m and col >= 0:
            if matrix[raw][col] == target:
                return True
            elif matrix[raw][col] > target:
                col -= 1
            else:
                raw += 1
        return False

if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        str_in = input()
        raw = [int(num) for num in str_in.split()]
        matrix.append(raw)
    target = int(input())
    solution = Solution()
    print(solution.searchMatrix(matrix, target))
