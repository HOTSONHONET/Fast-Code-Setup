import string


if __name__ == "__main__":
    letters = string.ascii_lowercase
    for i in range(26):
        print("{'", letters[i], "',", i + 1, "},")

    # tcs = int(input())
    # for _ in range(tcs):
    #     n = int(input())
    #     s = input()
    #     i = n - 1
    #     letters = string.ascii_lowercase
    #     print(letters)
    #     ans = ""
    #     while(i >= 0):
    #         if(s[i] == '0'):
    #             ans += letters[int(s[i-2:i]) - 1]
    #             i -= 3
    #         else:
    #             ans += letters[int(s[i]) - 1]
    #             i -= 1
    #     ans = ans[::-1]
    #     print(ans)
