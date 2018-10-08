class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        l, r = 0, num
        while l <= r:
            mid = (l + r) >> 1
            if mid * mid == num:
                return True
            elif mid * mid < num:
                l = mid + 1
            else:
                r = mid - 1
        return False


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.isPerfectSquare(num))
