class Solution:
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        return pow(a, int(''.join(map(str, b))), 1337)


if __name__ == '__main__':
    a = int(input())
    b = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.superPow(a, b))
