class Solution:
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        # words = ['zero', 'two', 'four', 'six', 'eight', 'one', 'three', 'five', 'seven', 'nine']
        # nums = ['0', '2', '4', '6', '8', '1', '3', '5', '7', '9']
        # keys = ['z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i']
        m = [0] * 128
        for c in s:
            m[ord(c)] += 1

        nums = [0] * 10
        nums[0] = m[ord('z')]
        nums[2] = m[ord('w')]
        nums[4] = m[ord('u')]
        nums[6] = m[ord('x')]
        nums[8] = m[ord('g')]
        nums[1] = m[ord('o')] - nums[0] - nums[2] - nums[4]
        nums[3] = m[ord('h')] - nums[8]
        nums[5] = m[ord('f')] - nums[4]
        nums[7] = m[ord('s')] - nums[6]
        nums[9] = m[ord('i')] - nums[6] - nums[8] - nums[5]

        result = ""
        for i in range(10):
            result += nums[i] * str(i)
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.originalDigits(s))
