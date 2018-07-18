class Solution:
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls = 0
        cows = 0
        nums = [0] * 10
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                if nums[int(secret[i])] < 0:
                    cows += 1
                if nums[int(guess[i])] > 0:
                    cows += 1
                nums[int(secret[i])] += 1
                nums[int(guess[i])] -= 1
        return '%dA%dB' % (bulls, cows)


if __name__ == '__main__':
    secret = input()
    guess = input()
    solution = Solution()
    print(solution.getHint(secret, guess))