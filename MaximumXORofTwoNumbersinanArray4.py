class Solution:
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def getMaxXor(set0, set1, pos):
            if not set0 or not set1 or pos < 0:
                return 0
            set00, set01, set10, set11 = [], [], [], []
            for n in set0:
                if (n & (1 << pos)) > 0:
                    set01.append(n)
                else:
                    set00.append(n)
            for n in set1:
                if (n & (1 << pos)) > 0:
                    set11.append(n)
                else:
                    set10.append(n)
            if not set00 and not set10:
                return getMaxXor(set0, set1, pos - 1)
            elif not set01 and not set11:
                return getMaxXor(set0, set1, pos - 1)
            else:
                maxValue1 = getMaxXor(set00, set11, pos - 1)
                maxValue2 = getMaxXor(set01, set10, pos - 1)
                return (1 << pos) + max(maxValue1, maxValue2)

        set0 = []
        set1 = []
        maxValue = 0
        for i in range(31, -1, -1):
            for num in nums:
                if (num & (1 << i)) > 0:
                    set1.append(num)
                else:
                    set0.append(num)
            if set0 and set1:
                maxValue = 1 << i
                break
            else:
                set0.clear()
                set1.clear()
        return maxValue + getMaxXor(set0, set1, i - 1)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findMaximumXOR(nums))
