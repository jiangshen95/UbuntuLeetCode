class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        import math
        return math.ceil(math.log(buckets, minutesToTest // minutesToDie + 1))


if __name__ == '__main__':
    buckets = int(input())
    minutesToDie = int(input())
    minutesToTest = int(input())
    solution = Solution()
    print(solution.poorPigs(buckets, minutesToDie, minutesToTest))
