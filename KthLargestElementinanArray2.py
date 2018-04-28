class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # heap sort
        def maxHeapify(i):
            left = i * 2 + 1
            right = i * 2 + 2
            while left < heapsize:
                if nums[left] > nums[i]:
                    largest = left
                else:
                    largest = i
                if right < heapsize and nums[right] > nums[largest]:
                    largest = right
                if largest != i:
                    nums[i], nums[largest] = nums[largest], nums[i]
                    i = largest
                    left = i * 2 + 1
                    right = i * 2 + 2
                else:
                    break
        
        def buildMaxHeap():
            for i in range(heapsize//2 - 1, -1, -1):
                maxHeapify(i)
            
        heapsize = len(nums)
        buildMaxHeap()
        for i in range(k):
            nums[0], nums[heapsize-1] = nums[heapsize-1], nums[0]
            heapsize -= 1
            maxHeapify(0)
        return nums[heapsize]
        
if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    solution = Solution()
    print(solution.findKthLargest(nums, k))

