class Solution:
    def nextGreaterElement(self, nums1: list, nums2: list) -> list:
        m, stack = {}, []
        for num in nums2:
            while stack and stack[-1] < num:
                m[stack.pop()] = num
            stack.append(num)
        result = []
        for num in nums1:
            result.append(m.get(num, -1))
        return result


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.nextGreaterElement(nums1, nums2))
