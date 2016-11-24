import math


def dist(a, b):
    return math.hypot(a[0] - b[0], a[1] - b[1])


def R(a, b, c):
    theta = math.acos((a * a + b * b - c * c) / 2 * a * b)
    return (c / math.sin(theta)) / 2


def main():
    N = int(input())
    for i in range(N):
        inputs = list(map(float, input().split()))
        p = [(x, y) for (x, y) in zip(inputs[::2], inputs[1::2])]

        print(R(dist(p[0], p[1]), dist(p[1], p[2]), dist(p[2], p[0])))


if __name__ == '__main__':
    main()
