import sys

input = sys.stdin.readline
n = int(input())
for k in range(n):
    mn = 10**6
    m = int(input())
    ma = sorted(list(map(int, input().split())))
    for i in range(0, m, 2):
        c = ma[i] - ma[i + 1]
        if c < mn:
            mn = c
    print(abs(mn))

