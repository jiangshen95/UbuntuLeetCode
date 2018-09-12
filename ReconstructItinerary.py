class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        def dfs(pg):
            while pg in m and m[pg]:
                t = m[pg][0]
                m[pg].pop(0)
                dfs(t)
            result.append(pg)
        m = {}
        for tick in tickets:
            if tick[0] in m:
                m[tick[0]].append(tick[1])
            else:
                m[tick[0]] = [tick[1]]
        for k in m.keys():
            m[k].sort()

        result = []
        dfs('JFK')
        result.reverse()
        return result


if __name__ == '__main__':
    tickets = []
    n = int(input())
    for _ in range(n):
        tickets.append([a for a in input().split()])
    solution = Solution()
    print(solution.findItinerary(tickets))
