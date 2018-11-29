class Solution:
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def valid(value):
            s = 0
            count = 1
            for num in nums:
                if s + num > value:
                    count += 1
                    if count > m:
                        return False
                    s = 0
                s += num
            return True

        left, right = 0, 0
        for num in nums:
            left = max(left, num)
            right += num

        # while left < right:
        while left <= right:
            mid = left + (right - left) // 2
            if valid(mid):
                right = mid - 1
                # right = mid
            else:
                left = mid + 1
        return left


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    m = int(input())
    solution = Solution()
    print(solution.splitArray(nums, m))
