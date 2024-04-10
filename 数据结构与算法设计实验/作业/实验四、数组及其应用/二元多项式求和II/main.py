n = int(input())
poly1 = []
for _ in range(n):
    x, y, coef = map(int, input().split())
    poly1.append((x, y, coef))

m = int(input())
poly2 = []
for _ in range(m):
    x, y, coef = map(int, input().split())
    poly2.append((x, y, coef))

result = sorted(poly1 + poly2, key=lambda x: (x[0], x[1]))

i = 0
while i < len(result):
    x, y, coef = result[i]
    if i + 1 < len(result) and result[i+1][0] == x and result[i+1][1] == y:
        coef += result[i+1][2]
        result.pop(i+1)
    if coef != 0:
        result[i] = (x, y, coef)
        i += 1
    else:
        result.pop(i)

for x, y, coef in result:
    print(x, y, coef)
