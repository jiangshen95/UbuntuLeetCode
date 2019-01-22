class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if not s or len(s) < len(p):
            return []
        m = [0] * 128
        for ch in p:
            m[ord(ch)] += 1

        result = []
        left, right = 0, 0
        cnt = len(p)
        while right < len(s):
            m[ord(s[right])] -= 1
            if m[ord(s[right])] >= 0:
                cnt -= 1
            right += 1
            if cnt == 0:
                result.append(left)
            if right - left >= len(p):
                m[ord(s[left])] += 1
                if m[ord(s[left])] > 0:
                    cnt += 1
                left += 1
        return result


if __name__ == '__main__':
    s = input()
    p = input()
    solution = Solution()
    print(solution.findAnagrams(s, p))
