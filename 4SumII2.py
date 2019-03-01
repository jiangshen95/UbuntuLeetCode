class Solution:
    def fourSumCount(self, A, B, C, D) -> int:
        from collections import Counter
        AB = Counter(a + b for a in A for b in B)
        return sum(AB[-c - d] for c in C for d in D)


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    B = [int(num) for num in input().split()]
    C = [int(num) for num in input().split()]
    D = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.fourSumCount(A, B, C, D))
