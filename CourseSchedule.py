class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = [ [] for _ in range(numCourses)]
        for pre in prerequisites:
            graph[pre[1]].append(pre[0])
        indegree = [0] * numCourses
        for neighbors in graph:
            for neighbor in neighbors:
                indegree[neighbor] += 1
        queue = []
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        count = 0
        while len(queue) > 0:
            t = queue[0]
            queue.pop(0)
            count += 1
            for neighbor in graph[t]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        return count == numCourses
        
if __name__ == '__main__':
    numCourses = int(raw_input())
    n = int(raw_input())
    prerequisites = []
    for i in range(n):
        pre = list(input())
        prerequisites.append(pre)
    solution = Solution()
    print(solution.canFinish(numCourses, prerequisites))
