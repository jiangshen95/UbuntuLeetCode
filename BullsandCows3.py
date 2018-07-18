import operator


class Solution:
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls = sum(map(operator.eq, secret, guess))
        both = sum(min(secret.count(x), guess.count(x)) for x in set(guess))
        return '%dA%dB' % (bulls, both - bulls)


if __name__ == '__main__':
    secret = input()
    guess = input()
    solution = Solution()
    print(solution.getHint(secret, guess))