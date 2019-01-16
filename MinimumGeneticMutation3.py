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

        def minMutation(start, end):
            if start == end:
                return 0
            step = len(bank) + 1
            for i, gens in enumerate(bank):
                if not visited[i] and canTranslate(gens, start):
                    visited[i] = True
                    temp = minMutation(gens, end)
                    if temp != -1:
                        step = min(step, temp)
                    visited[i] = False
            return -1 if step == len(bank) + 1 else step + 1

        visited = [False] * len(bank)
        return minMutation(start, end)


if __name__ == '__main__':
    start = input()
    end = input()
    bank = [gens for gens in input().split()]
    solution = Solution()
    print(solution.minMutation(start, end, bank))
