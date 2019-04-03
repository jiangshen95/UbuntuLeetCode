class Solution:
    def findComplement(self, num: int) -> int:
        mask = ~0
        while mask & num:
            mask <<= 1
        return ~mask & ~num


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.findComplement(num))
