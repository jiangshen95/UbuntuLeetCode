class Solution:
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = ['zero', 'two', 'four', 'six', 'eight', 'one', 'three', 'five', 'seven', 'nine']
        nums = ['0', '2', '4', '6', '8', '1', '3', '5', '7', '9']
        keys = ['z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i']
        m = {}
        for c in s:
            if c not in m:
                m[c] = 1
            else:
                m[c] += 1

        result = []
        for i in range(10):
            if keys[i] in m and m[keys[i]] > 0:
                cnt = m[keys[i]]
                result += cnt * [nums[i]]
                for c in words[i]:
                    m[c] -= cnt
        result.sort()
        return ''.join(result)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.originalDigits(s))
