class Solution:
    def findComplement(self, num: int) -> int:
        return num ^ ((1 << num.bit_length()) - 1)


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.findComplement(num))
