class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        '''
        s = pattern
        t = str.split()
        return map(s.find, s) == map(t.index, t)
        '''
        f = lambda s: map({}.setdefault, s, range(len(s)))
        return f(pattern) == f(str.split())


if __name__ == '__main__':
    pattern = input()
    str = input()
    solution = Solution()
    print(solution.wordPattern(pattern, str))
