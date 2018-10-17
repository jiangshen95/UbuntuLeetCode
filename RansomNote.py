class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        letters = {}
        for c in magazine:
            if c not in letters:
                letters[c] = 0
            letters[c] += 1
        for c in ransomNote:
            if c not in letters or letters[c] <= 0:
                return False
            letters[c] -= 1
        return True


if __name__ == '__main__':
    ransomNote = input()
    magazine = input()
    solution = Solution()
    print(solution.canConstruct(ransomNote, magazine))
