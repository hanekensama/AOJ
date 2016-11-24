def dfs(n, s, i):
    pass


def main():
    while True:
        n, s = map(int, input().split())
        if n == 0: break
        print(dfs(n, s, 9))

    return 0


if __name__ == '__main__':
    main()
