class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        temp = [0] * (n + 1)
        for citation in citations:
            if citation >= n:
                temp[n] += 1
            else:
                temp[citation] += 1
        count = 0
        for i in range(n, -1, -1):
            count += temp[i]
            if count >= i:
                return i
        return 0


if __name__ == '__main__':
    citations = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.hIndex(citations))
