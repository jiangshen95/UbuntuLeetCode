class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l <= r:
            mid1 = l + (r - l) // 3
            mid2 = r - (r - l) // 3
            res1 = guess(mid1)
            res2 = guess(mid2)
            if res1 == 0:
                return mid1
            elif res2 == 0:
                return mid2
            elif res1 == -1:
                r = mid1 - 1
            elif res2 == 1:
                l = mid2 + 1
            else:
                l = mid1 + 1
                r = mid2 - 1
        return -1
