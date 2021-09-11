t = int(input())

def fibo(x):
    if x <= 0:
        return 0
    if x == 1:
        return 1
    if d[x] != 0:
        return d[x]

    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]

for _ in range(t):
    d = [0] * 41
    x = int(input())

    if x == 0:
        print(1, 0)
    elif x == 1:
        print(0, 1)
    elif x == 2:
        print(1, 1)
    else:
        fibo(x)
        print(d[x - 1], d[x])
