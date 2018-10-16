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
                return nums[k1 - 1], nums[k2 - 1]

            index_ = index[::2] + index[n - 1 + n % 2:]
            k1_ = n + 1 + (k1 + 3) // 4 if n % 2 == 0 else (k1 + 2 * n) // 4 + 1
            k2_ = (k2 + 3) // 4
            a, b = biselect(index_, k1_, k2_)
            print(k1_, k2_)

            ra_less = rb_more = 0
            L = []
            jb = n
            ja = n
            for i in range(n):
                while jb > 0 and A(i, jb - 1) > b:
                    jb -= 1
                while ja > 0 and A(i, ja - 1) >= a:
                    ja -= 1
                ra_less += ja
                rb_more += n - jb
                L.extend(A(i, j) for j in range(jb, ja))
            print(L)
            x = a if ra_less <= k1 - 1 else b if k1 + rb_more - n * n <= 0 else \
                pick(L, k1 + rb_more - n * n)
            y = a if ra_less <= k2 - 1 else b if k2 + rb_more - n * n <= 0 else \
                pick(L, k2 + rb_more - n * n)
            return x, y

        n = len(matrix)
        start = max(k - n * n + n - 1, 0)
        k -= n * n - (n - start) ** 2
        return biselect(list(range(start, min(start + k, n))), k, k)[0]


if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append([int(num) for num in input().split()])
    k = int(input())
    solution = Solution()
    print(solution.kthSmallest(matrix, k))
