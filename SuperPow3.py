class Solution:
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        result = 1
        for i in range(len(b) - 1, -1, -1):
            result = result * pow(a, b[i], 1337) % 1337
            a = pow(a, 10, 1337)
        return result


if __name__ == '__main__':
    a = int(input())
    b = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.superPow(a, b))
