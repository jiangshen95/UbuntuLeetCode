class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        def searchMatrix(begin1, end1, begin2, end2):
            if begin1 > end1 or begin2 > end2 or begin1 < 0 or begin2 < 0 or end1 >= m or end2 >= n:
                return False
            if begin1 == end1 and begin2 == end2:
                return matrix[begin1][begin2] == target
            mid1 = (begin1 + end1) // 2
            mid2 = (begin2 + end2) // 2
            if matrix[mid1][mid2] < target:
                return searchMatrix(mid1 + 1, end1, mid2 + 1, end2) or \
                       searchMatrix(mid1 + 1, end1, begin2, mid2) or \
                       searchMatrix(begin1, mid1, mid2 + 1, end2)
            elif matrix[mid1][mid2] > target:
                return searchMatrix(begin1, mid1 - 1, begin2, mid2 - 1) or \
                       searchMatrix(begin1, mid1 - 1, mid2, end2) or \
                       searchMatrix(mid1, end1, begin2, mid2 - 1)
            else:
                return True

        if len(matrix) == 0:
            return False
        if len(matrix[0]) == 0:
            return False
        m = len(matrix)
        n = len(matrix[0])
        return searchMatrix(0, m - 1, 0, n - 1)

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
