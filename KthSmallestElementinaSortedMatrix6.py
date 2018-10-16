class Solution:
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        def pick(a, k):
            if k == 1:
                return min(a)
            groups = (a[i: i + 5] for i in range(0, len(a), 5))
            medians = [sorted(group)[len(group) // 2] for group in groups]
            pivot = pick(medians, len(medians) // 2 + 1)
            smaller = [x for x in a if x < pivot]
            if k <= len(smaller):
                return pick(smaller, k)
            k -= len(smaller) + a.count(pivot)
            return pivot if k < 1 else pick([x for x in a if x > pivot], k)

        def biselect(index, k1, k2):
            n = len(index)
            print(index)
            def A(i, j):
                return matrix[index[i]][index[j]]

            if n <= 2:
                nums = sorted(A(i, j) for i in range(n) for j in range(n))
                return nums[k1], nums[k2]

            index_ = index[::2] + index[n - 1 + n % 2:]
            k1_ = k1 // 4
            k2_ = n + 1 + k2 // 4 if n % 2 == 0 else (k2 + 2 * n + 1) // 4
            a, b = biselect(index_, k1_, k2_)

            ra_less = rb_less = 0
            ja, jb = n, n
            L = []
            for i in range(n):
                while ja > 0 and A(i, ja - 1) >= a:
                    ja -= 1
                while jb > 0 and A(i, jb - 1) >= b:
                    jb -= 1
                ra_less += ja
                rb_less += jb
                L.extend(A(i, j) for j in range(ja, jb))

            x = a if k1 < ra_less else pick(L, k1 - ra_less + 1) if k1 < rb_less else b
            y = a if k2 < ra_less else pick(L, k2 - ra_less + 1) if k2 < rb_less else b

            return x, y

        n = len(matrix)
        start = max(k - n * n + n - 1, 0)
        k -= n * n - (n - start) ** 2
        return biselect(list(range(start, min(start + k, n))), k - 1, k - 1)[0]


if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append([int(num) for num in input().split()])
    k = int(input())
    solution = Solution()
    print(solution.kthSmallest(matrix, k))
