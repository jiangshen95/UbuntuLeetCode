class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        flips = [(chars[0], 0)] + [(chars[i], i) for i in range(1, len(chars)) if chars[i] != chars[i - 1]] \
                + [(None, len(chars))]
        chunks = [(b[0], a[1] - b[1]) for (a, b) in zip(flips[1:], flips)]
        from functools import reduce
        compressed = reduce(lambda a, b: (a + [b[0]] + (list(str(b[1])) if b[1] > 1 else [])), chunks, [])
        chars[:len(compressed)] = compressed
        return len(compressed)


if __name__ == '__main__':
    chars = input()
    chars = list(chars)
    solution = Solution()
    print(solution.compress(chars))
