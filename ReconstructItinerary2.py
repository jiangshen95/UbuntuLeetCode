class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        m = {}
        for tick in tickets:
            if tick[0] in m:
                m[tick[0]].append(tick[1])
            else:
                m[tick[0]] = [tick[1]]
        for k in m.keys():
            m[k].sort()

        result = []
        stack = ['JFK']

        while stack:
            t = stack[-1]
            if t in m and m[t]:
                stack.append(m[t][0])
                m[t].pop(0)
            else:
                result = [t] + result
                stack.pop()
        return result


if __name__ == '__main__':
    tickets = []
    n = int(input())
    for _ in range(n):
        tickets.append([a for a in input().split()])
    solution = Solution()
    print(solution.findItinerary(tickets))
