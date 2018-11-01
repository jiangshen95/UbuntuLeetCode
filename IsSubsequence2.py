class Solution:
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def binarySearch(nums, target):
            l, r = 0, len(nums) - 1
            while l <= r:
                mid = l + (r - l) // 2
                if nums[mid] >= target:
                    r = mid - 1
                else:
                    l = mid + 1
            return l

        m = {}
        for i, ch in enumerate(t):
            if ch not in m:
                m[ch] = []
            m[ch].append(i)
        # for i in range(len(t)):
        #     if t[i] not in m:
        #         m[t[i]] = []
        #     m[t[i]].append(i)

        pre = 0
        for ch in s:
            if ch not in m:
                return False
            index = binarySearch(m[ch], pre)
            if index >= len(m[ch]):
                return False
            pre = m[ch][index] + 1
        return True


if __name__ == '__main__':
    s = input()
    t = input()
    solution = Solution()
    print(solution.isSubsequence(s, t))
