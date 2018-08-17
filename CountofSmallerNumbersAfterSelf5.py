class BinaryIndexedTree:
    def __init__(self, n):
        self.sums = [0] * (n + 1)

    def update(self, i, val):
        while i < len(self.sums):
            self.sums[i] += 1
            i += i & -i

    def sum(self, i):
        count = 0
        while i > 0:
            count += self.sums[i]
            i -= i & -i
        return count


class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        hashTable = {v: i for i, v in enumerate(sorted(set(nums)))}

        tree = BinaryIndexedTree(len(hashTable))
        counts = [0] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            counts[i] = tree.sum(hashTable[nums[i]])
            tree.update(hashTable[nums[i]] + 1, 1)
        return counts


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.countSmaller(nums))
