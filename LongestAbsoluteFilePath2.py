class Solution:
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        lines = input.splitlines()
        max_len = 0
        path = [0] * (len(lines) + 1)
        for line in lines:
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
