class Solution:
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        def dfs_cycle(course):
            if visited[course] == 1:
                return False
            if visited[course] == -1:
                return True
            visited[course] = 1
            for to in graph[course]:
                if visited[to] == 1:
                    return False
                elif not dfs_cycle(to):
                    return False
            visited[course] = -1
            order.append(course)
            return True
        graph = {i : set() for i in range(numCourses)}
        for pre in prerequisites:
            graph[pre[1]].add(pre[0])
        visited = [0] * numCourses
        order = []
        for i in range(numCourses):
            if not dfs_cycle(i):
                return []
        order.reverse()
        return order
        
if __name__ == '__main__':
    numCourses = int(raw_input())
    n = int(raw_input())
    prerequisites = []
    for i in range(n):
        pre = list(input())
        prerequisites.append(pre)
    solution = Solution()
    print(solution.findOrder(numCourses, prerequisites))
