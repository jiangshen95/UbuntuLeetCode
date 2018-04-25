class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        def dfs_cycle(course):
            if visited[course] == 1:
                return False
            if visited[course] == -1:
                return True
            visited[course] = 1
            for i in graph[course]:
                if visited[i] == 1:
                    return False
                elif not dfs_cycle(i):
                    return False
            visited[course] = -1
            return True
            
        graph = [ [] for _ in range(numCourses)]
        for pre in prerequisites:
            graph[pre[1]].append(pre[0])
        visited = [0] * numCourses
        
        for i in range(numCourses):
            if not dfs_cycle(i):
                return False
        return True
        
if __name__ == '__main__':
    numCourses = int(raw_input())
    n = int(raw_input())
    prerequisites = []
    for i in range(n):
        pre = list(input())
        prerequisites.append(pre)
    solution = Solution()
    print(solution.canFinish(numCourses, prerequisites))
