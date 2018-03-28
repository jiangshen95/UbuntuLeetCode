class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        
        count = 0
        start = 0
        while count < n:
            pre = nums[start]
            next = (start + k) % n
            while next != start:
                temp = nums[next]
                nums[next] = pre
                pre = temp
                next = (next + k) % n
                count += 1
            nums[start] = pre
            count += 1
            start += 1

if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    solution = Solution()
    solution.rotate(nums, k)
    print(nums)
