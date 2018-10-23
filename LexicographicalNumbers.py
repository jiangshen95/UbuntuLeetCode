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
            helper(v * 10, n)
            if v % 10 < 9:
                helper(v + 1, n)
        result = []
        helper(1, n)
        return result


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lexicalOrder(n))
