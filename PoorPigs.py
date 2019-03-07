class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        pigs = 0
        while (minutesToTest // minutesToDie + 1) ** pigs < buckets:
            pigs += 1
        return pigs


if __name__ == '__main__':
    buckets = int(input())
    minutesToDie = int(input())
    minutesToTest = int(input())
    solution = Solution()
    print(solution.poorPigs(buckets, minutesToDie, minutesToTest))
