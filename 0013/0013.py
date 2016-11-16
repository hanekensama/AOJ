import sys


def main():
    stack = []
    for x in sys.stdin:
        x = int(x)
        if x:
            stack.append(x)
        else:
            print(stack.pop())


if __name__ == '__main__':
    main()
