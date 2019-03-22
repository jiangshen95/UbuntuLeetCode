class Solution:
    def validIPAddress(self, IP: str) -> str:
        def isValidIPv4Section(section):
            if not section or len(section) > 3:
                return False
            if len(section) > 1 and section[0] == '0':
                return False
            if not section.isdigit():
                return False
            if int(section) > 255:
                return False
            return True

        def isValidIPv6Section(section):
            if not section or len(section) > 4:
                return False
            for ch in section:
                if ch not in '0123456789abcdefABCDEF':
                    return False
            return True

        if '.' in IP:
            sections = IP.split('.')
            if len(sections) != 4:
                return 'Neither'
            for section in sections:
                if not isValidIPv4Section(section):
                    return 'Neither'
            return 'IPv4'
        else:
            sections = IP.split(':')
            if len(sections) != 8:
                return 'Neither'
            for section in sections:
                if not isValidIPv6Section(section):
                    return 'Neither'
            return 'IPv6'


if __name__ == '__main__':
    IP = input()
    solution = Solution()
    print(solution.validIPAddress(IP))
