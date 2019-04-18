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

        board = removeConsecutive(board)
        if not board:
            return 0
        result = 100
        s = set()
        for i in range(len(hand)):
            if hand[i] in s:
                continue
            s.add(hand[i])
            for j in range(len(board)):
                if board[j] == hand[i]:
                    t = self.findMinStep(board[: j] + hand[i] + board[j:], hand[:i] + hand[i + 1:])
                    if t != -1:
                        result = min(result, t + 1)
        return -1 if result == 100 else result


if __name__ == '__main__':
    board = input()
    hand = input()
    solution = Solution()
    print(solution.findMinStep(board, hand))
