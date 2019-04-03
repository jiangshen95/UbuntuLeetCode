class Solution:
    def findComplement(self, num: int) -> int:
        i = 1
        while i <= num:
            i <<= 1
        return (i - 1) ^ num


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.findComplement(num))
