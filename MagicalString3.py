class Solution:
    def magicalString(self, n: int) -> int:
        def gen():
            for x in 1, 2, 2:
                yield x
            for i, x in enumerate(gen()):
                print("---", i, x)
                if i > 1:
                    for _ in range(x):
                        yield i % 2 + 1
        x = gen()
        for i in range(n):
            print(x.send(None))

        # import itertools
        # return sum(x & 1 for x in itertools.islice(gen(), n))


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.magicalString(n))
