from collections import deque

i = list(iter(input, ''))
t_depth = len(i)
t = list()
for l in i:
    l = [int(x) for x in l.split()]
    t.extend(l)
# print(t)

max_total = 0
stack = deque()
stack.append((t[0], 1, 0)) # (sum up to row, row, element index)
while len(stack) != 0:
    current_sum, row, elem_idx = stack.pop()
    if row >= t_depth:
        max_total = current_sum if max_total < current_sum else max_total
        # print(current_sum)
        continue
    for i in range(2):
        next_elem_idx = row + elem_idx + i
        next_sum = current_sum + t[next_elem_idx]
        stack.append((next_sum, row+1, next_elem_idx))
print(max_total)