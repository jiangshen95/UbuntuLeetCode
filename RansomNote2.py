import collections


class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        print(collections.Counter(ransomNote))
        return not collections.Counter(ransomNote) - collections.Counter(magazine)


if __name__ == '__main__':
    ransomNote = input()
    magazine = input()
    solution = Solution()
    print(solution.canConstruct(ransomNote, magazine))
