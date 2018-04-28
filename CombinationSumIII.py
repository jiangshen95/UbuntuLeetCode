class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def combination(nums, num, sumof):
            if len(nums) == k:
                if sumof == n:
                    result.append(nums)
                return
            for i in range(num + 1, min(9, n - sumof) + 1):
                combination(nums + [i], i, sumof + i)
                
        result = []
        nums = []
        combination(nums, 0, 0)
        return result

if __name__ == '__main__':
    k = int(raw_input())
    n = int(raw_input())
    solution = Solution()
    print(solution.combinationSum3(k, n))            
