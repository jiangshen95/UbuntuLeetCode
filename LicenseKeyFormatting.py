class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace('-', '').upper()[::-1]
        return '-'.join(S[i: i + K] for i in range(0, len(S), K))[::-1]


if __name__ == '__main__':
    S = input()
    K = int(input())
    solution = Solution()
    print(solution.licenseKeyFormatting(S, K))
