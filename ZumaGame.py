class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def findMinStep(b):
            if not b:
                return 0
            count, result = 1, 100
            for i in range(1, len(b) + 1, 1):
                if i < len(b) and b[i] == b[i - 1]:
                    count += 1
                else:
                    if count >= 3:
                        t = findMinStep(b[: i - count] + b[i:])
                        if t != -1:
                            result = min(result, t)
                    else:
                        need = 3 - count
                        if b[i - 1] in m and m[b[i - 1]] >= need:
                            m[b[i - 1]] -= need
                            t = findMinStep(b[: i - count] + b[i:])
                            if t != -1:
                                result = min(result, t + need)
                            m[b[i - 1]] += need
                    count = 1
            return -1 if result == 100 else result

        m = {}
        for c in hand:
            m[c] = m.get(c, 0) + 1

        return findMinStep(board)


if __name__ == '__main__':
    board = input()
    hand = input()
    solution = Solution()
    print(solution.findMinStep(board, hand))
