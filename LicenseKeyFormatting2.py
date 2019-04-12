class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace('-', '').upper()
        l = len(S)
        s1 = l % K if l % K else K
        result = S[: s1]
        while s1 < l:
            result += '-' + S[s1: s1 + K]
            s1 += K
        return result


if __name__ == '__main__':
    S = input()
    K = int(input())
    solution = Solution()
    print(solution.licenseKeyFormatting(S, K))
