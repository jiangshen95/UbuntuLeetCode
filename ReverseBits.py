class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        result = 0
        for i in range(32):
            result <<= 1
            #result |= n%2
            result |= n & 1
            n >>= 1
        return result
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.reverseBits(n))
