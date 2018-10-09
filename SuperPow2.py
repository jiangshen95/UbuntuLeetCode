class Solution:
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        return pow(a, b.pop(), 1337) * pow(self.superPow(a, b), 10, 1337) % 1337 if b else 1


if __name__ == '__main__':
    a = int(input())
    b = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.superPow(a, b))
