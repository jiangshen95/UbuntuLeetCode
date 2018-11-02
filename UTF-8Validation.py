class Solution:
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        count = 0
        for num in data:
            num = num & 0xFF
            mask = 0x80
            frontOnes = 0
            while num & mask:
                frontOnes += 1
                mask >>= 1
            if frontOnes > 4:
                return False
            if count == 0:
                if frontOnes == 1:
                    return False
                elif frontOnes > 1:
                    count = frontOnes - 1
            else:
                if frontOnes != 1:
                    return False
                count -= 1
        return count == 0


if __name__ == '__main__':
    data = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.validUtf8(data))
