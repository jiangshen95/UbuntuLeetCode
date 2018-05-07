class Solution:
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        bottom = max(B, F)
        top = max(min(D, H), bottom)
        left = max(A, E)
        right = max(min(C, G), left)
        return (C - A) * (D - B) + (G - E) * (H - F) - (top - bottom) * (right - left)
        
if __name__ == '__main__':
    a, b, c, d, e, f, g, h = list(input())
    solution = Solution()
    print(solution.computeArea(a, b, c, d, e, f, g, h))
