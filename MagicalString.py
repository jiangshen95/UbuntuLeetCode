class Solution:
    def magicalString(self, n: int) -> int:
        s = [1]
        i, result = 0, 0
        while len(s) < n:
            if s[i] == 1:
                result += 1
                s.append(3 ^ s[-1])
            else:
                s.append(s[-1])
                s.append(3 ^ s[-1])
            i += 1
        return s[: n].count(1)


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.magicalString(n))
