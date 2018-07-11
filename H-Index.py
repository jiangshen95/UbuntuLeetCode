class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        l = len(citations)
        for n in citations:
            if l <= n:
                return l
            else:
                l -= 1
        return 0

if __name__ == '__main__':
    citations = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.hIndex(citations))
