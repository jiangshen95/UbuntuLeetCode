class Solution:
    def validIPAddress(self, IP: str) -> str:
        import re
        ipv4 = re.compile(r'^((\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])$')
        ipv6 = re.compile(r'^(([0-9a-fA-F]{1,4}):){7}([0-9a-fA-F]{1,4})$')
        if re.match(ipv4, IP):
            return 'IPv4'
        elif re.match(ipv6, IP):
            return 'IPv6'
        else:
            return 'Neither'


if __name__ == '__main__':
    IP = input()
    solution = Solution()
    print(solution.validIPAddress(IP))
