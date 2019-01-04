class Solution:
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        class TreeNode:
            def __init__(self):
                self.next = [None, None]

        root = TreeNode()
        for num in nums:
            cur = root
            for i in range(31, -1, -1):
                t = (num >> i) & 1
                if not cur.next[t]:
                    cur.next[t] = TreeNode()
                cur = cur.next[t]

        result = 0
        for num in nums:
            cur = root
            temp = 0
            for i in range(31, -1, -1):
                t = (num >> i) & 1
                if cur.next[t ^ 1]:
                    temp |= 1 << i
                    cur = cur.next[t ^ 1]
                else:
                    cur = cur.next[t]
            result = max(result, temp)

        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findMaximumXOR(nums))
