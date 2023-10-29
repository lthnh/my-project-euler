from queue import PriorityQueue
from math import inf

with open('0067_triangle.txt') as f:
    i = f.read().splitlines()
t_depth = len(i)
t = list()
for l in i:
    l = [-int(x) for x in l.split()] # turn number into negative to accomodate python min_priority_queue
    t.extend(l)

min_sum = [inf for _ in range(t_depth-1)]
prio_queue = PriorityQueue()
prio_queue.put_nowait((t[0], 1, 0)) # (sum up to row, row, element index)
while not prio_queue.empty():
    current_sum, row, elem_idx = prio_queue.get_nowait()
    for i in range(2):
        if row < t_depth:
            next_elem_idx = row + elem_idx + i
            next_sum = current_sum + t[next_elem_idx]
            if (next_sum < min_sum[row-1]):
                min_sum[row-1] = next_sum
            prio_queue.put_nowait((next_sum, row+1, next_elem_idx))
print(-min_sum[-1])