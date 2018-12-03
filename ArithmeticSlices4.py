class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def slices(i):
            if i < 2:
                return 0
            ap = 0
            nonlocal result
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                ap = 1 + slices(i - 1)
                # result[0] += ap
                result += ap
            else:
                slices(i - 1)
            return ap
        # result = [0]
        result = 0
        slices(len(A) - 1)
        # return result[0]
        return result


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.numberOfArithmeticSlices(A))
