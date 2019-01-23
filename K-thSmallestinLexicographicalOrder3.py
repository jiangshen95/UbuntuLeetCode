class Solution:
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def getDepth(n):
            depth = 0
            while n > 0:
                n //= 10
                depth += 1
            return depth

        def getFullTreeNum(depth):
            count, step = 0, 1
            while depth > 0:
                count += step
                step *= 10
                depth -= 1
            return count

        def getMinChild(prefix, depth):
            while depth > 0:
                prefix *= 10
                depth -= 1
            return prefix

        def getMaxChild(prefix, depth):
            while depth > 0:
                prefix *= 10
                prefix += 9
                depth -= 1
            return prefix

        def helper(n, k, prefix, depth):
            num1 = getFullTreeNum(depth)
            num2 = getFullTreeNum(depth - 1)
            for i in range(1 if prefix == 0 else 0, 10):
                if n >= getMaxChild(prefix * 10 + i, depth - 1):
                    num = num1
                elif n < getMinChild(prefix * 10 + i, depth - 1):
                    num = num2
                else:
                    num = num2 + (n - getMinChild(prefix * 10 + i, depth - 1) + 1)
                if k <= num:
                    if k == 1:
                        return prefix * 10 + i
                    else:
                        return helper(n, k - 1, prefix * 10 + i, depth - 1)
                else:
                    k -= num
            return 0
        return helper(n, k, 0, getDepth(n))


if __name__ == '__main__':
    n = int(input())
    k = int(input())
    solution = Solution()
    print(solution.findKthNumber(n, k))
