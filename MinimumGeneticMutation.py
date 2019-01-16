class Solution:
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        def canTranslate(s1, s2):
            count = 0
            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    count += 1
                if count > 1:
                    return False
            return count == 1

        if not bank:
            return -1
        queue = [start]
        visited = []
        step = 0
        while queue:
            size = len(queue)
            for i in range(size):
                t = queue.pop(0)
                if t == end:
                    return step
                visited.append(t)
                for gens in bank:
                    if gens not in visited and canTranslate(t, gens):
                        print(gens)
                        queue.append(gens)
            step += 1
        return -1


if __name__ == '__main__':
    start = input()
    end = input()
    bank = [gens for gens in input().split()]
    solution = Solution()
    print(solution.minMutation(start, end, bank))
