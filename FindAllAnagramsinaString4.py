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
        m1 = [0] * 128
        for ch in p:
            m[ord(ch)] += 1

        result = []
        left, right = 0, 0
        cnt = len(p)
        while right < len(s):
            if m1[ord(s[right])] < m[ord(s[right])]:
                cnt -= 1
                m1[ord(s[right])] += 1
                right += 1
            else:
                if m[ord(s[right])] == 0:
                    left = right + 1
                    right += 1
                    m1 = [0] * 128
                    cnt = len(p)
                else:
                    m1[ord(s[left])] -= 1
                    cnt += 1
                    left += 1
            if cnt == 0:
                result.append(left)

        return result


if __name__ == '__main__':
    s = input()
    p = input()
    solution = Solution()
    print(solution.findAnagrams(s, p))
