class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        j, index = 0, 0
        for i in range(len(chars) + 1):
            if i == len(chars) or chars[i] != chars[j]:
                count = i - j
                if count > 0:
                    chars[index], index = chars[j], index + 1
                    if count > 1:
                        digits = str(count)
                        for digit in digits:
                            chars[index], index = digit, index + 1
                j = i
        print(chars)
        return index


if __name__ == '__main__':
    chars = input()
    chars = list(chars)
    solution = Solution()
    print(solution.compress(chars))
