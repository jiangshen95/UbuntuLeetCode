class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        r = []
        for n in nums:
            if not r or n > r[-1][-1] + 1:
                r.append([n])
            else:
                if(len(r[-1]) == 1):
                    r[-1].append(n)
                else:
                    r[-1][-1] = n
        return ['->'.join(map(str, n)) for n in r]

if __name__ == '__main__':
    nums = list(input())
    solution = Solution()
    print(solution.summaryRanges(nums))
