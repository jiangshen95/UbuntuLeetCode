class Solution:
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        if not s:
            return None
        if s[0] != '[':
            return NestedInteger(int(s))

        stack = []
        cur = None
        l = 0
        for i in range(len(s)):
            if s[i] == '[':
                if cur:
                    stack += [cur]
                cur = NestedInteger()
                l = i + 1
            elif s[i] == ']':
                if l < i:
                    cur.add(NestedInteger(int(s[l: i])))
                if stack:
                    stack[-1].add(cur)
                    cur = stack[-1]
                    stack.pop()
                l = i + 1
            elif s[i] == ',':
                if s[i - 1] != ']':
                    num = int(s[l: i])
                    cur.add(NestedInteger(num))
                l = i + 1
        return cur
