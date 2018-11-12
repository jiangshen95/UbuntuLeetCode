class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        def calcEquation(start, end, visited):
            if start == end:
                return 1
            for x, y in m[start]:
                if end == x:
                    return y
            for x, y in m[start]:
                if x not in visited:
                    visited.append(x)
                    t = calcEquation(x, end, visited)
                    if t != -1:
                        return y * t
            return -1
        m = {}
        for i, equation in enumerate(equations):
            if equation[0] not in m:
                m[equation[0]] = []
            if equation[1] not in m:
                m[equation[1]] = []
            m[equation[0]].append((equation[1], values[i]))
            m[equation[1]].append((equation[0], 1 / values[i]))

        result = [-1] * len(queries)
        for i, query in enumerate(queries):
            if query[0] in m and query[1] in m:
                result[i] = calcEquation(query[0], query[1], [])

        return result


if __name__ == '__main__':
    n = int(input())
    equations = []
    for _ in range(n):
        equations.append([x for x in input().split()])
    values = [float(v) for v in input().split()]
    m = int(input())
    queries = []
    for _ in range(m):
        queries.append([x for x in input().split()])

    solution = Solution()
    print(solution.calcEquation(equations, values, queries))
