class Solution:
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def helper(v, n):
            if v <= n:
                result.append(v)
            else:
                return
            for i in range(10):
                helper(v * 10 + i, n)
        result = []
        for i in range(1, 10):
            helper(i, n)
        return result


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lexicalOrder(n))
