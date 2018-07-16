class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        if len(words) != len(pattern):
            return False
        map1 = {}
        map2 = {}
        for i in range(len(words)):
            if pattern[i] not in map1:
                map1[pattern[i]] = i
            if words[i] not in map2:
                map2[words[i]] = i
            if map1[pattern[i]] != map2[words[i]]:
                return False
        return True


if __name__ == '__main__':
    pattern = input()
    str = input()
    solution = Solution()
    print(solution.wordPattern(pattern, str))
