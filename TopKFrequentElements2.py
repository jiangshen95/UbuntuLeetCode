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
        q = []
        for key, value in m.items():
            q.append((value, key))
        q.sort(key=lambda l: l[0], reverse=True)
        print(q)
        result = []
        for i in range(k):
            result.append(q[i][1])
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    k = int(input())
    solution = Solution()
    print(solution.topKFrequent(nums, k))
