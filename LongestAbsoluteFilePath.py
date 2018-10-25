class Solution:
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        max_len = 0
        path = {0: 0}
        for line in input.splitlines():
            name = line.lstrip('\t')
            deep = len(line) - len(name)
            if '.' in name:
                max_len = max(max_len, path[deep] + len(name))
            else:
                path[deep + 1] = path[deep] + len(name) + 1
        return max_len


if __name__ == '__main__':
    input = input()
    solution = Solution()
    print(solution.lengthLongestPath(input))
