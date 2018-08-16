"""
Time Limit Exceeded
"""
class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        uglies = [1]
        index = [0] * len(primes)
        while len(uglies) < n:
            val = 2147483647
            where = 0
            for i in range(len(primes)):
                if primes[i] * uglies[index[i]] < val:
                    val = primes[i] * uglies[index[i]]
                    where = i
            index[where] += 1
            if val > uglies[-1]:
                uglies.append(val)
        return uglies[-1]


if __name__ == '__main__':
    n = int(input())
    primes = [int(_) for _ in input().split()]
    solution = Solution()
    print(solution.nthSuperUglyNumber(n, primes))
