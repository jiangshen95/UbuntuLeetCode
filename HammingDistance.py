class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        count = 0
        n = x ^ y
        while n:
            count += n & 1
            n >>= 1
        return count


if __name__ == '__main__':
    x = int(input())
    y = int(input())
    solution = Solution()
    print(solution.hammingDistance(x, y))
