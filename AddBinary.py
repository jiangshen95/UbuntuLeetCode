class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(b)>len(a):
            return self.addBinary(b, a)
        i = len(a)-1
        j = len(b)-1
        carry = 0
        while i>=0 or j>=0:
            if j>=0:
                carry += int(a[i])+int(b[j])
            else:
                carry += int(a[i])
            a = a[:i] + str(carry%2) + a[i+1:]
            carry //= 2
            i -= 1
            j -= 1
        if carry:
            a = '1' + a
        return a
        
if __name__=='__main__':
    a = raw_input()
    b = raw_input()
    solution = Solution()
    print(solution.addBinary(a, b))
            
