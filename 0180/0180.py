import heapq

def createGraph(n, m):
    adjacency = [[] for i in range(n)]
    for i in range(m):
        a, b, cost = map(int, input().split())
        adjacency[a].append((b, cost))
        adjacency[b].append((a, cost))

    return adjacency

def solve(n, m):
    adjacency = createGraph(n, m)
    cost = 0
    h = []
    heapq.heappush(h, 0)
    while h:
        pass



def main():
    while True:
        n, m = map(int, input().split())
        print(solve(n, m))

if __name__ == '__main__':
    main()
