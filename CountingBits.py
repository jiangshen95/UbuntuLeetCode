class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        bits = [0] * (num + 1)
        offset = 1
        for i in range(1, num + 1):
            if i == offset * 2:
                offset *= 2
            bits[i] = bits[i - offset] + 1
        return bits


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.countBits(num))
