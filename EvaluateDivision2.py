class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        class Node:
            def __init__(self):
                self.parent = self
                self.value = 0

        def findParent(node):
            if node.parent == node:
                return node
            node.parent = findParent(node.parent)
            return node.parent

        def unionNodes(node1, node2, value):
            parent1, parent2 = findParent(node1), findParent(node2)
            ratio = node2.value * value / node1.value
            for k, n in m.items():
                if findParent(n) == parent1:
                    n.value *= ratio
            parent1.parent = parent2

        m = {}
        for i, equation in enumerate(equations):
            if equation[0] not in m and equation[1] not in m:
                m[equation[0]] = Node()
                m[equation[1]] = Node()
                m[equation[1]].value = 1
                m[equation[0]].value = values[i]
                m[equation[0]].parent = m[equation[1]]
            elif equation[0] not in m:
                m[equation[0]] = Node()
                m[equation[0]].value = m[equation[1]].value * values[i]
                m[equation[0]].parent = m[equation[1]]
            elif equation[1] not in m:
                m[equation[1]] = Node()
                m[equation[1]].value = m[equation[0]].value / values[i]
                m[equation[1]].parent = m[equation[0]]
            else:
                unionNodes(m[equation[0]], m[equation[1]], values[i])

        result = [-1] * len(queries)
        for i, query in enumerate(queries):
            if query[0] not in m or query[1] not in m or findParent(m[query[0]]) != findParent(m[query[1]]):
                continue
            result[i] = m[query[0]].value / m[query[1]].value

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
