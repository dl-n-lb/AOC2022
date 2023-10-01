from itertools import *
from functools import *

def compare_list(left, right):
    if left is None:
        return -1
    if right is None:
        return 1
    if type(left) is int and type(right) is int:
        if left == right:
            return 0
        return 1 if (left > right) else -1
    elif type(left) is list and type(right) is list:
        for l, r in zip_longest(left, right):
            if compare_list(l, r) != 0:
                return compare_list(l, r)
        return 0
    else:
        l = [left] if type(left) is int else left
        r = [right] if type(right) is int else right
        return compare_list(l, r)
                
f = open("../in.txt", "r")
lines = []
for line in f.readlines():
    line = line.strip("\n")
    if line != "":
        lines.append(eval(line))

# PART 1
n = 0
s = 0
for i in range(0, len(lines), 2):
    n += 1
    left = lines[i]
    right = lines[i+1]
    res = compare_list(left, right)
    if res == -1:
        s += n

print(s)


# PART 2
div1 = [[2]]
div2 = [[6]]
lines.append(div1)
lines.append(div2)
slines = sorted(lines, key=cmp_to_key(compare_list))
print((slines.index(div1) + 1) * (slines.index(div2) + 1))
