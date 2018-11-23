class Solution:
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        blocks = [[]]
        for p in sorted(people, key=lambda p: (-p[0], p[1])):
            index = p[1]
            for i, block in enumerate(blocks):
                m = len(block)
                if index <= m:
                    break
                index -= m
            block.insert(index, p)
            if m * m > len(people):
                blocks.insert(i + 1, block[m // 2:])
                del block[m // 2:]
        return [p for block in blocks for p in block]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    people = [[nums[i], nums[i + 1]] for i in range(0, len(nums), 2)]
    print(people)
    solution = Solution()
    print(solution.reconstructQueue(people))
