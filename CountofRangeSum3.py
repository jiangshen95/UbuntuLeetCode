class Solution:
    class SegmentNode:
        def __init__(self, low, up):
            self.low = low
            self.up = up
            self.count = 0
            self.left = None
            self.right = None

    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        def buildSegmentTree(l, r):
            if l > r:
                return None
            root = self.SegmentNode(sums[l], sums[r])
            if l == r:
                return root
            mid = l + (r - l) // 2
            root.left = buildSegmentTree(l, mid)
            root.right = buildSegmentTree(mid + 1, r)
            return root

        def updateSegmentTree(root, num):
            if not root:
                return
            if root.low <= num <= root.up:
                root.count += 1
                updateSegmentTree(root.left, num)
                updateSegmentTree(root.right, num)

        def getCount(root, low, up):
            if not root:
                return 0
            elif root.low >= low and root.up <= up:
                return root.count
            elif root.low > up or root.up < low:
                return 0
            else:
                return getCount(root.left, low, up) + getCount(root.right, low, up)

        sums = []
        sum = 0
        for num in nums:
            sum += num
            sums.append(sum)
        sums = list(set(sums))
        sums.sort()

        root = buildSegmentTree(0, len(sums) - 1)

        count = 0
        for i in range(len(nums) - 1, -1, -1):
            updateSegmentTree(root, sum)
            sum -= nums[i]
            count += getCount(root, sum + lower, sum + upper)

        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    lower = int(input())
    upper = int(input())
    solution = Solution()
    print(solution.countRangeSum(nums, lower, upper))
