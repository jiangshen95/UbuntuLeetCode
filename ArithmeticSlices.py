class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        count = 0
        for i in range(0, len(A) - 2):
            d = A[i + 1] - A[i]
            for j in range(i + 2, len(A)):
                if A[j] - A[j - 1] == d:
                    count += 1
                else:
                    break
        return count


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.numberOfArithmeticSlices(A))
