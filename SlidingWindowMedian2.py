from heapq import heappop, heappush


class Solution:
    def medianSlidingWindow(self, nums: list, k: int) -> list:
        result = []
        small, large = [], []
        for i, n in enumerate(nums[: k]):
            heappush(small, (-n, i))
        for i in range(k // 2):
            heappush(large, (-small[0][0], small[0][1]))
            heappop(small)

        for i in range(k, len(nums) + 1, 1):
            result.append((large[0][0] - small[0][0]) / 2 if k % 2 == 0 else -small[0][0] / 1.0)
            if i == len(nums):
                break
            if nums[i] >= -small[0][0]:
                heappush(large, (nums[i], i))
                if nums[i - k] <= -small[0][0]:
                    heappush(small, (-large[0][0], large[0][1]))
                    heappop(large)
            else:
                heappush(small, (-nums[i], i))
                if nums[i - k] >= -small[0][0]:
                    heappush(large, (-small[0][0], small[0][1]))
                    heappop(small)
            while small and small[0][1] <= i - k:
                heappop(small)
            while large and large[0][1] <= i - k:
                heappop(large)

        return result


if __name__ == '__main__':
    nums = list(int(num) for num in input().split())
    k = int(input())
    solution = Solution()
    print(solution.medianSlidingWindow(nums, k))
