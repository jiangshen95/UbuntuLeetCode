class Solution:
    def reversePairs(self, nums: list) -> int:

        def update(i):
            while i < len(bit):
                bit[i] += 1
                i += (i & -i)

        def getSum(i):
            sum = 0
            while i > 0:
                sum += bit[i]
                i -= (i & -i)
            return sum

        def binarySearch(target):
            left, right = 0, len(v) - 1
            while left <= right:
                mid = (left + right) // 2
                if v[mid] >= target:
                    right = mid - 1
                else:
                    left = mid + 1
            return left

        v = sorted(nums)
        m = {}
        bit = [0] * (len(nums) + 1)
        for i, n in enumerate(v):
            m[n] = i + 1

        result = 0
        for num in nums[::-1]:
            result += getSum(binarySearch(num / 2.0))
            update(m[num])
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.reversePairs(nums))
