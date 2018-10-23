class Solution:
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        top = 1
        while top * 10 <= n:
            top *= 10

        def mycmp(a):
            while a < top:
                a *= 10
            return a
        return sorted(range(1, n + 1), key=mycmp)


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lexicalOrder(n))
