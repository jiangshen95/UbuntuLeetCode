class Solution:
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        sVec = [0] * 10
        gVec = [0] * 10
        bulls = 0
        cows = 0

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                sVec[int(secret[i])] += 1
                gVec[int(guess[i])] += 1
        for i in range(10):
            cows += min(sVec[i], gVec[i])
        return '%dA%dB' % (bulls, cows)


if __name__ == '__main__':
    secret = input()
    guess = input()
    solution = Solution()
    print(solution.getHint(secret, guess))