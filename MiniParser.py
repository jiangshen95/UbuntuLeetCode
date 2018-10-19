class Solution:
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        result = NestedInteger()
        stack = [result]

        i = 0
        while i < len(s):
            if s[i] == '[':
                if i != 0:
                    stack[-1].add(NestedInteger())
                    stack += stack[-1].getList()[-1:]
            elif s[i] == ']':
                stack.pop()
            elif s[i] != ',':
                j = i
                while j < len(s) and s[j] in '-0123456789':
                    j += 1
                num = int(s[i: j])
                if j == len(s):
                    stack[-1].setInteger(num)
                else:
                    stack[-1].add(NestedInteger(num))
                i = j - 1
            i += 1
        return result
