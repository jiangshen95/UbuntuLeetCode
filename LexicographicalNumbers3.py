class Solution:
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = []
        cur = 1
        for i in range(n):
            result.append(cur)
            if cur * 10 <= n:
                cur *= 10
            elif cur % 10 < 9 and cur < n:
                cur += 1
            else:
                while cur % 10 == 9 or cur == n:
                    cur //= 10
                cur += 1
        return result


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lexicalOrder(n))
