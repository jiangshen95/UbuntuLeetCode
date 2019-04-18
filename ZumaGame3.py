class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def removeConsecutive(b):
            j = 0
            for i in range(len(b) + 1):
                if i < len(b) and b[i] == b[j]:
                    continue
                if i - j >= 3:
                    return removeConsecutive(b[: j] + b[i:])
                j = i
            return b

        def helper(b, h):
            b = removeConsecutive(b)
            if not b:
                return 0
            result = 100
            for i in range(len(h)):
                j = 0
                while j < len(b):
                    k = b.find(h[i], j)
                    if k == -1:
                        break
                    if k < len(b) - 1 and b[k] == b[k + 1]:
                        t = self.findMinStep(b[: k] + h[i] + b[k:], h[:i] + h[i + 1:])
                        if t != -1:
                            result = min(result, t + 1)
                    elif i > 0 and h[i] == h[i - 1]:
                        t = self.findMinStep(b[: k] + 2 * h[i] + b[k:], h[:i - 1] + h[i + 1:])
                        if t != -1:
                            result = min(result, t + 2)
                    j = k + 1
            return -1 if result == 100 else result

        return helper(board, ''.join(sorted(list(hand))))


if __name__ == '__main__':
    board = input()
    hand = input()
    solution = Solution()
    print(solution.findMinStep(board, hand))
