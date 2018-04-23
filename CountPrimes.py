class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<3:
            return 0
        nums = [1] * n
        nums[0] = 0
        nums[1] = 0
        for i in range(2, int(n ** 0.5) + 1):
            if nums[i] == 1:
                for j in range(i * i, n, i):
                    nums[j] = 0
        return sum(nums)
        
if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.countPrimes(n))
