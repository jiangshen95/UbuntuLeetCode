class Solution:
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        def getEng(num):
            if num == 0:
                return []
            elif num < 20:
                return [less_twenty[num]]
            elif num < 100:
                return [tens[num // 10 - 2]] + getEng(num % 10)
            else:
                return [less_twenty[num // 100], 'Hundred'] + getEng(num % 100)
        if num == 0:
            return 'Zero'
        less_twenty = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
						"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                        "Seventeen", "Eighteen", "Nineteen"]
        tens = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        units = ["Thousand", "Million", "Billion"]

        words = []
        i = 0

        while num > 0:
            if num % 1000 > 0:
                if i > 0:
                    words = getEng(num % 1000) + [units[i - 1]] + words
                else:
                    words = getEng(num % 1000)
            i += 1
            num //= 1000
        return ' '.join(words)

if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.numberToWords(num))
