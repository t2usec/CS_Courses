n = int(input())
poly1 = {}
for _ in range(n):
    x, y, coef = map(int, input().split())
    poly1[(x, y)] = poly1.get((x, y), 0) + coef

m = int(input())
poly2 = {}
for _ in range(m):
    x, y, coef = map(int, input().split())
    poly2[(x, y)] = poly2.get((x, y), 0) + coef

result = {}
for key, value in poly1.items():
    result[key] = result.get(key, 0) + value
for key, value in poly2.items():
    result[key] = result.get(key, 0) + value

sorted_result = sorted(result.items())
for (x, y), coef in sorted_result:
    if coef != 0:
        print(x, y, coef)
