class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # return ['FizzBuzz' if i % 5 == 0 and i % 3 == 0 else 'Fizz' if i % 3 == 0
        #         else 'Buzz' if i % 5 == 0 else str(i) for i in range(1, n + 1)]
        # return ['Fizz' * (not i % 3) + 'Buzz' * (not i % 5) or str(i) for i in range(1, n + 1)]
        return ['FizzBuzz'[i % -3 & -4: i % -5 & 8 ^ 12] or str(i) for i in range(1, n + 1)]


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.fizzBuzz(n))
