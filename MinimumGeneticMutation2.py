class Solution:
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        if not bank:
            return -1
        queue = [start]
        visited = []
        gens = ['A', 'G', 'C', 'T']
        step = 0
        while queue:
            size = len(queue)
            for i in range(size):
                t = queue.pop(0)
                if t == end:
                    return step
                visited.append(t)
                for j in range(len(t)):
                    for gen in gens:
                        trans = t[: j] + gen + t[j + 1:]
                        if trans != t and trans in bank and trans not in visited:
                            queue.append(trans)
            step += 1
        return -1


if __name__ == '__main__':
    start = input()
    end = input()
    bank = [gens for gens in input().split()]
    solution = Solution()
    print(solution.minMutation(start, end, bank))
