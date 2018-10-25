class Solution:
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        max_len = 0
        stack = [0]
        for line in input.splitlines():
            name = line.lstrip('\t')
            deep = len(line) - len(name)
            while deep + 1 < len(stack):
                stack.pop()
            if '.' in name:
                max_len = max(max_len, stack[-1] + len(name))
            else:
                stack.append(stack[-1] + len(name) + 1)
        return max_len


if __name__ == '__main__':
    input = input()
    solution = Solution()
    print(solution.lengthLongestPath(input))
