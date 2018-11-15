class Solution:
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        s = []
        for d in num:
            while s and k > 0 and d < s[-1]:
                s.pop()
                k -= 1
            s.append(d)
        res = ''.join(s[: -k]) if k > 0 else ''.join(s)
        return res.lstrip('0') or '0'
        # return ''.join(s[: -k or None]).lstrip('0') or '0'


if __name__ == '__main__':
    num = input()
    k = int(input())
    solution = Solution()
    print(solution.removeKdigits(num, k))
