class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums) == 0 or k <= 0:
            return []
        deque = []
        result = []

        for i in range(len(nums)):
            while len(deque) > 0 and deque[0] < i - k + 1:
                deque.pop(0)
            while len(deque) > 0 and nums[deque[-1]] < nums[i]:
                deque.pop()
            deque.append(i)
            if i >= k - 1:
                result.append(nums[deque[0]])
        return result

if __name__ == '__main__':
    str_in = input()
    nums = [int(num) for num in str_in.split()]
    k = int(input())
    solution = Solution()
    print(solution.maxSlidingWindow(nums, k))
