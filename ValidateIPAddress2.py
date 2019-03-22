class Solution:
    def validIPAddress(self, IP: str) -> str:
        def isValidIPv4Section(section):
            try:
                return str(int(section)) == section and 0 <= int(section) <= 255
            except:
                return False

        def isValidIPv6Section(section):
            if not section or len(section) > 4:
                return False
            try:
                return int(section, 16) >= 0 and section[0] != '-'
            except:
                return False

        if '.' in IP:
            sections = IP.split('.')
            if len(sections) != 4:
                return 'Neither'
            if all(isValidIPv4Section(section) for section in sections):
                return 'IPv4'
            else:
                return 'Neither'
        else:
            sections = IP.split(':')
            if len(sections) != 8:
                return 'Neither'
            if all(isValidIPv6Section(section) for section in sections):
                return 'IPv6'
            else:
                return 'Neither'


if __name__ == '__main__':
    IP = input()
    solution = Solution()
    print(solution.validIPAddress(IP))
