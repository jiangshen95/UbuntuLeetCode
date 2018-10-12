import itertools


class Solution:
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        norep = [num for num, _ in itertools.groupby(nums)]
        print(list(itertools.groupby(nums)))
        triples = zip(norep, norep[1:], norep[2:])
        return sum(a > b < c or a < b > c for a, b, c in triples) + len(norep[:2])


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.wiggleMaxLength(nums))
