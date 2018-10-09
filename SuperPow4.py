class Solution:
    def getLoop(self, a):
        index = []
        sets = [False] * 1337
        rem = a % 1337
        while not sets[rem]:
            sets[rem] = True
            index.append(rem)
            rem = (rem * a) % 1337
        return index

    def modBy(self, b, m):
        digit = int(''.join(map(str, b)))
        return digit % m

    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        a %= 1337
        index = self.getLoop(a)
        rem = self.modBy(b, len(index))
        return index[rem - 1]


if __name__ == '__main__':
    a = int(input())
    b = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.superPow(a, b))
