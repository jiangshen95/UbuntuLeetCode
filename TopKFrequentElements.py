class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        m = {}
        for num in nums:
            if num in m:
                m[num] += 1
            else:
                m[num] = 1
        bucket = [[] for _ in range(len(nums) + 1)]
        for key, value in m.items():
            bucket[value].append(key)
        result = []
        for i in range(len(nums), 0, -1):
            for n in bucket[i]:
                result.append(n)
                if len(result) == k:
                    return result
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    k = int(input())
    solution = Solution()
    print(solution.topKFrequent(nums, k))
