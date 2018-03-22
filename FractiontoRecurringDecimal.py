class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return "0"
        
        symbol = ""
        
        if (numerator < 0 or denominator < 0) and (not (numerator < 0 and denominator < 0)):
            symbol = "-"
            
        number = ""
        decimal = ""
        
        numerator = long(abs(numerator))       #numerator = abs(numerator) in python3
        denominator = long(abs(denominator))
        
        if numerator > denominator:
            number = str(long(numerator/denominator))   #number = str(numerator//denominator) in python3
        if number == "":
            number = "0"
        
        numerator = long(numerator%denominator)
        dic = {numerator : 0}
        
        while numerator:
            next_numerator = numerator * 10

            decimal += str(long(next_numerator/denominator))
            numerator = next_numerator % denominator
            
            if numerator in dic:
                decimal = decimal[0:dic[numerator]] + '(' +decimal[dic[numerator]:] + ')'
                break
            dic[numerator] = len(decimal)
            
        if decimal == "":
            return symbol + number
        else:
            return symbol + number + '.' + decimal
            
if __name__=='__main__':
    numerator = int(raw_input())
    denominator = int(raw_input())
    solution = Solution()
    print(solution.fractionToDecimal(numerator, denominator))
