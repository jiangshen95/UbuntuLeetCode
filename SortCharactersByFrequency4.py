class Solution:
    def frequencySort(self, s: str) -> str:
        import collections
        return ''.join([char * times for char, times in collections.Counter(s).most_common()])


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.frequencySort(s))
