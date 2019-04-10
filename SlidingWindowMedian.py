import bisect


class Solution:
    def medianSlidingWindow(self, nums: list, k: int) -> list:
        result = []
        window = sorted(nums[: k])
        for a, b in zip(nums, nums[k:] + [0]):
            result.append((window[k // 2] + window[~(k // 2)]) / 2)
            window.remove(a)
            bisect.insort(window, b)
        return result


if __name__ == '__main__':
    nums = list(int(num) for num in input().split())
    k = int(input())
    solution = Solution()
    print(solution.medianSlidingWindow(nums, k))
