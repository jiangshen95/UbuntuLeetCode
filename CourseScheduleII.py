class Solution:
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        graph = {i : set() for i in range(numCourses)}
        for pre in prerequisites:
            graph[pre[1]].add(pre[0])
        indegree = [0] * numCourses
        for neighbors in graph:
            for neighbor in graph[neighbors]:
                indegree[neighbor] += 1
        queue = []
        order = []
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        while len(queue) > 0:
            t = queue[0]
            queue.pop(0);
            order.append(t)
            for to in graph[t]:
                indegree[to] -= 1
                if indegree[to] == 0:
                    queue.append(to)
        return order if len(order) == numCourses else []
        
if __name__ == '__main__':
    numCourses = int(raw_input())
    n = int(raw_input())
    prerequisites = []
    for i in range(n):
        pre = list(input())
        prerequisites.append(pre)
    solution = Solution()
    print(solution.findOrder(numCourses, prerequisites))
