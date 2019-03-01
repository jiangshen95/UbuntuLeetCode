class Solution:
    def fourSumCount(self, A, B, C, D) -> int:
        m = {}
        for a in A:
            for b in B:
                m[a + b] = m.get(a + b, 0) + 1
        count = 0
        for c in C:
            for d in D:
                if -c - d in m:
                    count += m[-c - d]

        return count


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    B = [int(num) for num in input().split()]
    C = [int(num) for num in input().split()]
    D = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.fourSumCount(A, B, C, D))
