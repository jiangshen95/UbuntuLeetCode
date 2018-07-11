class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        l = len(citations)
        left, right = 0, l - 1
        while left <= right:
            mid = (left + right) // 2
            if l - mid > citations[mid]:
                left = mid + 1
            else:
                right = mid - 1
        return l - left

if __name__ == '__main__':
    citations = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.hIndex(citations))