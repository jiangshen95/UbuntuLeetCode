# Time Limit Exceeded
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        i, j = 0, 0
        count1, count2 = 1, 0
        flag = False
        while i < len(s1) and j < len(s2):
            if s1[i] == s2[j]:
                j += 1
                flag = True
            i += 1
            if i == len(s1) and flag and 0 < j < len(s2):
                i = 0
                count1 += 1
            if j == len(s2):
                j = 0
                count2 += 1
                flag = False
            if count1 > n1:
                return count2 // n2
        return int(n1 / count1 * count2 / n2)


if __name__ == '__main__':
    s1 = input()
    n1 = int(input())
    s2 = input()
    n2 = int(input())
    solution = Solution()
    print(solution.getMaxRepetitions(s1, n1, s2, n2))
