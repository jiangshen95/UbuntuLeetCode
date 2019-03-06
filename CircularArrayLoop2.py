class Solution:
    def circularArrayLoop(self, nums) -> bool:
        def getIndex(i):
            return ((i + nums[i]) % n + n) % n

        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                continue
            j = i
            k = getIndex(i)
            while nums[i] * nums[k] > 0 and nums[getIndex(k)] * nums[i] > 0:
                if j == k:
                    if j == getIndex(j):
                        break
                    return True
                j = getIndex(j)
                k = getIndex(getIndex(k))

            j = i
            next = getIndex(j)
            while nums[j] * nums[next] > 0:
                next = getIndex(j)
                nums[j] = 0
                j = next
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.circularArrayLoop(nums))
