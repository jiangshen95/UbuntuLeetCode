class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        needDiffCount = {}
        s = A.copy()
        result = 0
        for i in range(1, n):
            if A[i] in needDiffCount:
                for key, value in needDiffCount[A[i]].items():
                    need = A[i] + key
                    result += value
                    if need in s:
                        if need not in needDiffCount:
                            needDiffCount[need] = {}
                        needDiffCount[need][key] = needDiffCount[need].get(key, 0) + value
            for j in range(i):
                diff = A[i] - A[j]
                need = A[i] + diff
                if need in s:
                    if need not in needDiffCount:
                        needDiffCount[need] = {}
                    needDiffCount[need][diff] = needDiffCount[need].get(diff, 0) + 1
            s.remove(A[i])
        return result


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.numberOfArithmeticSlices(A))
