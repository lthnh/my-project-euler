with open('67/0067_triangle.txt') as f:
    i = f.read().splitlines()
t = list()
for l in i:
    l = [int(x) for x in l.split()] # turn number into negative to accomodate python min_priority_queue
    t.append(l)
# print(t)

for row, vals in enumerate(t[:0:-1], start=-len(t) + 1):
    row = abs(row)
    for idx, val in enumerate(vals[:-1]):
        max_val = max(t[row][idx], t[row][idx+1])
        t[row-1][idx] += max_val
print(t[0][0])

with open('67/0067_triangle.txt') as f:
    prev = list()
    for ln in f:
        prev = [0] + prev + [0]
        curr = map(int, ln.split())
        prev = [max(a, b) + c for a, b, c in zip(prev[1:], prev[:-1], curr)]
print(max(prev))