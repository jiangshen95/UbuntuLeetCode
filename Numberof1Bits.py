class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n > 0:
            count += n & 1
            n >>= 1
        return count
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.hammingWeight(n))
