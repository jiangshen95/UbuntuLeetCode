class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        count, result = 0, 0
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                count += 1
            else:
                result += count * (1 + count) // 2
                count = 0
        result += count * (1 + count) // 2
        return result


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.numberOfArithmeticSlices(A))
