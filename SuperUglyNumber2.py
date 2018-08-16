class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        uglies = [0] * n
        index = [0] * len(primes)
        val = [1] * len(primes)
        nex = 1
        for i in range(n):
            uglies[i] = nex
            for j in range(len(primes)):
                if val[j] == uglies[i]:
                    val[j] = primes[j] * uglies[index[j]]
                    index[j] += 1
            nex = min(val)
        return uglies[-1]


if __name__ == '__main__':
    n = int(input())
    primes = [int(_) for _ in input().split()]
    solution = Solution()
    print(solution.nthSuperUglyNumber(n, primes))
