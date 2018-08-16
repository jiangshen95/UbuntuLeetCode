import heapq

class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        q, uglies = [], [1]
        for i in range(len(primes)):
            heapq.heappush(q, (primes[i], 0, primes[i]))
        while len(uglies) < n:
            x, i, p = q[0]
            uglies.append(x)
            while q and q[0][0] == x:
                x, i, p = heapq.heappop(q)
                heapq.heappush(q, (p * uglies[i + 1], i + 1, p))
        return uglies[-1]


if __name__ == '__main__':
    n = int(input())
    primes = [int(_) for _ in input().split()]
    solution = Solution()
    print(solution.nthSuperUglyNumber(n, primes))
