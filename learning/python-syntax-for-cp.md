# Modern Python Syntax for Competitive Programming

This is a practical Python guide for solving LeetCode-style problems. It focuses on syntax, standard library tools, and patterns you will actually use.

Assume LeetCode gives you something like:

```python
class Solution:
    def solve(self, nums: list[int]) -> int:
        # your code
        pass
```

LeetCode uses Python 3 (usually 3.10+). All examples assume Python 3.

---

## 1. Basic Structure

### Class-based (LeetCode style)

```python
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {}
        for i, v in enumerate(nums):
            if target - v in seen:
                return [seen[target - v], i]
            seen[v] = i
        return []
```

### Standalone function (scripts / Codeforces)

```python
def solve(nums):
    return sum(nums)
```

### Reading input (Codeforces / competitive)

```python
import sys
input = sys.stdin.readline  # faster than built-in input()

n = int(input())
a, b = map(int, input().split())
nums = list(map(int, input().split()))
```

### Multiple test cases

```python
t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    # solve
```

---

## 2. Core Types

```python
x: int = 5
f: float = 3.14
s: str = "hello"
b: bool = True
n = None
```

### Integer is arbitrary precision

```python
big = 10 ** 100   # no overflow, ever
```

### Float limits

```python
import math
math.inf    # positive infinity
-math.inf   # negative infinity
math.nan    # not a number
```

### Common substitutes for INT_MAX / INT_MIN

```python
INF = float('inf')
NEG_INF = float('-inf')

# or
INF = 10**18
```

### Type checking

```python
isinstance(x, int)    # True
isinstance(x, (int, float))  # multi-type check
```

---

## 3. Numbers

### Integer division

```python
7 // 2    # 3  (floor division)
-7 // 2   # -4 (floors toward negative infinity)
7 % 2     # 1
-7 % 2    # 1  (Python modulo is always non-negative)
```

### Power

```python
2 ** 10   # 1024
pow(2, 10)        # same
pow(2, 10, 1000)  # (2**10) % 1000, modular exponentiation
```

### Absolute value

```python
abs(-5)   # 5
```

### Rounding

```python
round(3.7)    # 4
round(3.5)    # 4  (banker's rounding — rounds to even)
int(3.9)      # 3  (truncates toward zero)
math.floor(3.9)  # 3
math.ceil(3.1)   # 4
```

### Math module

```python
import math
math.sqrt(16)     # 4.0
math.log(8, 2)    # 3.0
math.log2(8)      # 3.0
math.log10(100)   # 2.0
math.factorial(5) # 120
math.gcd(12, 8)   # 4
math.lcm(4, 6)    # 12  (Python 3.9+)
math.isqrt(17)    # 4   (integer square root, no float)
math.comb(5, 2)   # 10  (n choose k)
math.perm(5, 2)   # 20  (n permute k)
```

---

## 4. Strings

```python
s = "hello"
n = len(s)         # 5
s[0]               # 'h'
s[-1]              # 'o'
s[1:3]             # 'el'
s[::-1]            # 'olleh' (reversed)
```

### Common methods

```python
s.upper()          # "HELLO"
s.lower()          # "hello"
s.strip()          # remove whitespace from both ends
s.lstrip()         # left strip
s.rstrip()         # right strip
s.split()          # split on whitespace
s.split(',')       # split on comma
','.join(['a','b','c'])  # "a,b,c"
s.replace('l','x') # "hexxo"
s.startswith('he') # True
s.endswith('lo')   # True
s.find('ll')       # 2  (returns -1 if not found)
s.count('l')       # 2
s.isdigit()        # False
s.isalpha()        # True
s.isalnum()        # True
```

### String building (efficient)

```python
parts = []
for c in "hello":
    parts.append(c.upper())
result = ''.join(parts)  # 'HELLO'
```

Avoid `result += c` in a loop — it's O(n²) in older implementations.

### ord and chr

```python
ord('a')    # 97
ord('A')    # 65
chr(97)     # 'a'

# index into alphabet
idx = ord(c) - ord('a')   # 0..25 for lowercase
```

### f-strings

```python
x = 42
s = f"value is {x}"
s = f"{x:05d}"   # "00042"
s = f"{3.14:.2f}"  # "3.14"
```

### Multiline strings

```python
s = """line1
line2"""
```

---

## 5. Lists

`list` is Python's dynamic array — equivalent to C++ `vector`.

```python
nums = []
nums = [1, 2, 3]
nums = [0] * 5           # [0, 0, 0, 0, 0]
nums = list(range(5))    # [0, 1, 2, 3, 4]
nums = list(range(1, 6)) # [1, 2, 3, 4, 5]
```

### Common operations

```python
nums.append(10)      # add to end
nums.pop()           # remove and return last
nums.pop(0)          # remove and return first (O(n) — avoid in hot loops)
nums.insert(1, 99)   # insert 99 at index 1 (O(n))
nums.extend([4, 5])  # append multiple
nums.clear()
len(nums)
nums[0]              # first
nums[-1]             # last
nums[1:3]            # slice [1, 2] (copy)
nums[::-1]           # reversed copy
```

### Modifying

```python
nums[0] = 100
nums[1:3] = [7, 8]  # slice assignment
```

### Looping

```python
for x in nums:
    print(x)

for i in range(len(nums)):
    print(i, nums[i])

for i, x in enumerate(nums):
    print(i, x)
```

### Checking membership

```python
3 in nums      # O(n)
3 not in nums  # O(n)
```

### Remove by value

```python
nums.remove(3)  # removes first occurrence, raises ValueError if missing
```

### Sorting in-place

```python
nums.sort()             # ascending
nums.sort(reverse=True) # descending
```

### Sorted (returns new list)

```python
sorted_nums = sorted(nums)
sorted_nums = sorted(nums, reverse=True)
```

### Min / Max

```python
min(nums)
max(nums)
min(a, b)
max(a, b, c)
```

### Sum

```python
sum(nums)
sum(nums[l:r])
```

### Reverse in-place

```python
nums.reverse()
```

### Copy

```python
copy = nums[:]        # shallow copy
copy = list(nums)     # same
import copy
deep = copy.deepcopy(nums)  # deep copy (for nested lists)
```

---

## 6. 2D Lists

```python
grid = [[1, 2, 3], [4, 5, 6]]
```

Create m × n grid filled with zero:

```python
m, n = 3, 4
grid = [[0] * n for _ in range(m)]
```

**Do not use `[[0] * n] * m`** — it creates m references to the same row.

Access:

```python
grid[0][1] = 5
```

Loop:

```python
for r in range(len(grid)):
    for c in range(len(grid[0])):
        print(grid[r][c])
```

Row count, column count:

```python
rows = len(grid)
cols = len(grid[0])
```

---

## 7. Tuples

Immutable, hashable — useful as dictionary keys or set elements.

```python
t = (1, 2)
t = (1,)        # single-element tuple needs trailing comma
a, b = t        # unpack
x, y, z = 1, 2, 3  # unpack from implicit tuple
```

### Common use: coordinate keys

```python
visited = set()
visited.add((r, c))
if (r, c) in visited:
    ...
```

---

## 8. Dictionaries

`dict` is Python's hash map — O(1) average insert/lookup/delete.

```python
d = {}
d = {'a': 1, 'b': 2}
d['a'] = 10          # insert or update
d['c']               # KeyError if missing
d.get('c')           # None if missing
d.get('c', 0)        # 0 if missing
d['x'] = d.get('x', 0) + 1  # increment with default
del d['a']           # delete key
'a' in d             # membership check
len(d)
```

### Iteration

```python
for key in d:
    print(key, d[key])

for key, val in d.items():
    print(key, val)

for key in d.keys():
    ...

for val in d.values():
    ...
```

### Common pattern: frequency count

```python
freq = {}
for x in nums:
    freq[x] = freq.get(x, 0) + 1
```

### Dict comprehension

```python
freq = {x: nums.count(x) for x in set(nums)}
squares = {x: x**2 for x in range(10)}
```

---

## 9. defaultdict

Avoids KeyError by returning a default value for missing keys.

```python
from collections import defaultdict

freq = defaultdict(int)       # default 0
freq['a'] += 1

adj = defaultdict(list)       # default []
adj[u].append(v)

nested = defaultdict(lambda: defaultdict(int))  # 2-level
```

---

## 10. Counter

Counts frequency of elements.

```python
from collections import Counter

c = Counter([1, 2, 2, 3, 3, 3])
# Counter({3: 3, 2: 2, 1: 1})

c[3]          # 3
c[99]         # 0  (no KeyError)
c.most_common(2)  # [(3, 3), (2, 2)]
c.total()         # sum of all counts (Python 3.10+)
sum(c.values())   # equivalent for older Python

# from string
c = Counter("abracadabra")

# arithmetic
c1 = Counter(a=3, b=2)
c2 = Counter(a=1, b=4)
c1 + c2   # Counter({'b': 6, 'a': 4})
c1 - c2   # Counter({'a': 2}) — drops non-positive
c1 & c2   # Counter({'a': 1, 'b': 2}) — min
c1 | c2   # Counter({'b': 4, 'a': 3}) — max
```

---

## 11. Sets

`set` is Python's hash set — O(1) average insert/lookup/delete.

```python
s = set()
s = {1, 2, 3}
s.add(4)
s.remove(3)     # raises KeyError if missing
s.discard(3)    # safe, no error
3 in s          # True / False
len(s)
```

### Set operations

```python
a = {1, 2, 3}
b = {2, 3, 4}
a | b    # {1,2,3,4}  union
a & b    # {2,3}      intersection
a - b    # {1}        difference
a ^ b    # {1,4}      symmetric difference
a <= b   # subset check
a < b    # proper subset
```

### frozenset (hashable, immutable)

```python
fs = frozenset([1, 2, 3])
d[fs] = "value"  # can use as dict key
```

---

## 12. Deque

Double-ended queue — O(1) append and pop from both ends.

```python
from collections import deque

dq = deque()
dq = deque([1, 2, 3])
dq.append(4)       # right
dq.appendleft(0)   # left
dq.pop()           # right
dq.popleft()       # left
dq[0]              # peek left
dq[-1]             # peek right
len(dq)
```

Use `deque` instead of `list` when you need O(1) operations at both ends (BFS queues, sliding window).

---

## 13. Heap / Priority Queue

Python's `heapq` is a **min-heap**.

```python
import heapq

heap = []
heapq.heappush(heap, 3)
heapq.heappush(heap, 1)
heapq.heappush(heap, 2)

heapq.heappop(heap)   # 1 (smallest)
heap[0]               # peek minimum without popping

# heapify in O(n) from existing list
nums = [3, 1, 4, 1, 5]
heapq.heapify(nums)
```

### Max-heap trick (negate values)

```python
heapq.heappush(heap, -val)
max_val = -heapq.heappop(heap)
```

### Heap with tuples (priority, value)

```python
heapq.heappush(heap, (priority, value))
pri, val = heapq.heappop(heap)
```

### nlargest / nsmallest

```python
heapq.nlargest(3, nums)   # 3 largest elements
heapq.nsmallest(3, nums)  # 3 smallest elements
```

---

## 14. Stack

Use a regular list.

```python
stack = []
stack.append(x)   # push
stack.pop()       # pop (raises IndexError if empty)
stack[-1]         # peek top
not stack         # is empty
```

---

## 15. Queue

Use `deque` for O(1) popleft.

```python
from collections import deque

q = deque()
q.append(x)       # enqueue
q.popleft()       # dequeue
q[0]              # peek front
not q             # is empty
```

---

## 16. Sorting

### Sort list in-place

```python
nums.sort()
nums.sort(reverse=True)
nums.sort(key=lambda x: -x)          # descending
nums.sort(key=lambda x: (x[1], x[0])) # by second element, then first
```

### sorted() — returns new list

```python
s = sorted(nums)
s = sorted(nums, reverse=True)
s = sorted(words, key=len)
s = sorted(words, key=lambda w: (len(w), w))
```

### Sort strings by character frequency

```python
s = sorted("hello", key=lambda c: ord(c))
```

### Custom comparison (functools.cmp_to_key)

```python
from functools import cmp_to_key

def cmp(a, b):
    if a < b: return -1
    if a > b: return 1
    return 0

nums.sort(key=cmp_to_key(cmp))
```

---

## 17. Binary Search (bisect)

```python
import bisect

nums = [1, 3, 5, 7, 9]

bisect.bisect_left(nums, 5)   # 2 — first index where 5 can be inserted
bisect.bisect_right(nums, 5)  # 3 — last index where 5 can be inserted
```

`bisect_left` returns leftmost position where target fits (first occurrence of target if present).  
`bisect_right` returns rightmost position (one past last occurrence).

### Check if value exists

```python
i = bisect.bisect_left(nums, target)
if i < len(nums) and nums[i] == target:
    # found
```

### Count occurrences in sorted array

```python
count = bisect.bisect_right(nums, val) - bisect.bisect_left(nums, val)
```

### insort

```python
bisect.insort(nums, val)  # insert val maintaining sorted order, O(n) due to shift
```

---

## 18. Comprehensions

### List comprehension

```python
squares = [x**2 for x in range(10)]
evens = [x for x in nums if x % 2 == 0]
flat = [x for row in grid for x in row]
```

### Dict comprehension

```python
d = {x: x**2 for x in range(5)}
inverted = {v: k for k, v in d.items()}
```

### Set comprehension

```python
unique_squares = {x**2 for x in nums}
```

### Generator expression (lazy, memory-efficient)

```python
total = sum(x**2 for x in range(10**6))
```

### Conditional expression (ternary)

```python
val = a if condition else b
```

---

## 19. Enumerate and Zip

### enumerate

```python
for i, x in enumerate(nums):
    print(i, x)

for i, x in enumerate(nums, start=1):   # start index at 1
    print(i, x)
```

### zip

```python
for a, b in zip(nums1, nums2):
    print(a, b)

# zip stops at the shortest iterable
pairs = list(zip([1,2,3], ['a','b','c']))  # [(1,'a'),(2,'b'),(3,'c')]
```

### zip_longest

```python
from itertools import zip_longest
for a, b in zip_longest(nums1, nums2, fillvalue=0):
    ...
```

---

## 20. Lambda Functions

```python
f = lambda x: x * 2
g = lambda x, y: x + y

nums.sort(key=lambda x: -x)
filtered = list(filter(lambda x: x > 0, nums))
mapped = list(map(lambda x: x**2, nums))
```

---

## 21. functools

### lru_cache (memoization)

```python
from functools import lru_cache

@lru_cache(maxsize=None)
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)
```

For class methods, use `@lru_cache` on inner function or `functools.cache`:

```python
from functools import cache

@cache
def dp(i, j):
    ...
```

### reduce

```python
from functools import reduce
product = reduce(lambda acc, x: acc * x, nums, 1)
```

---

## 22. Itertools

```python
import itertools

# permutations
list(itertools.permutations([1,2,3]))       # all orderings
list(itertools.permutations([1,2,3], 2))    # length-2 permutations

# combinations
list(itertools.combinations([1,2,3], 2))    # [(1,2),(1,3),(2,3)]

# combinations with replacement
list(itertools.combinations_with_replacement([1,2], 2))  # [(1,1),(1,2),(2,2)]

# product (cartesian product)
list(itertools.product([0,1], repeat=3))    # all 3-bit strings

# accumulate
list(itertools.accumulate([1,2,3,4]))       # [1,3,6,10] (prefix sums)
list(itertools.accumulate([1,2,3,4], max))  # [1,2,3,4] (running max)

# chain
list(itertools.chain([1,2], [3,4]))         # [1,2,3,4]

# groupby (input must be sorted by key)
for key, group in itertools.groupby([1,1,2,2,3], key=lambda x: x):
    print(key, list(group))
```

---

## 23. Bit Manipulation

```python
n = 0b1010    # binary literal = 10
n & 1         # check lowest bit (1 if odd)
n | (1 << k)  # set bit k
n & ~(1 << k) # clear bit k
n ^ (1 << k)  # toggle bit k
(n >> k) & 1  # get bit k
n << 1        # multiply by 2
n >> 1        # divide by 2 (floor)
n & (n - 1)   # clear lowest set bit
n & (-n)      # isolate lowest set bit
bin(n)        # '0b1010'
bin(n).count('1')  # popcount
n.bit_length()     # number of bits in binary representation
```

### XOR tricks

```python
a ^ a == 0    # anything XOR itself is 0
a ^ 0 == a    # anything XOR 0 is itself
# XOR all elements to find the one that appears odd number of times
```

### Check power of 2

```python
n > 0 and (n & (n - 1)) == 0
```

---

## 24. Linked List Patterns

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# dummy head pattern
dummy = ListNode(0)
dummy.next = head
curr = dummy
while curr.next:
    curr = curr.next

# two-pointer (fast/slow)
slow, fast = head, head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
```

---

## 25. Tree Traversal

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

### Recursive DFS

```python
def inorder(root):
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)

def preorder(root):
    if not root:
        return []
    return [root.val] + preorder(root.left) + preorder(root.right)

def postorder(root):
    if not root:
        return []
    return postorder(root.left) + postorder(root.right) + [root.val]
```

### Iterative inorder

```python
def inorder_iterative(root):
    result, stack = [], []
    curr = root
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        result.append(curr.val)
        curr = curr.right
    return result
```

### BFS (level order)

```python
from collections import deque

def level_order(root):
    if not root:
        return []
    result, q = [], deque([root])
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        result.append(level)
    return result
```

---

## 26. Graph Representation

### Adjacency list

```python
from collections import defaultdict

adj = defaultdict(list)
for u, v in edges:
    adj[u].append(v)
    adj[v].append(u)  # undirected
```

### Adjacency list with weights

```python
adj = defaultdict(list)
for u, v, w in edges:
    adj[u].append((v, w))
    adj[v].append((u, w))
```

### Matrix as graph

```python
rows, cols = len(grid), len(grid[0])
dirs = [(0,1),(0,-1),(1,0),(-1,0)]

for dr, dc in dirs:
    nr, nc = r + dr, c + dc
    if 0 <= nr < rows and 0 <= nc < cols:
        # valid neighbor
```

---

## 27. DFS Graph

### Recursive

```python
def dfs(node, visited, adj):
    visited.add(node)
    for nei in adj[node]:
        if nei not in visited:
            dfs(nei, visited, adj)

visited = set()
dfs(start, visited, adj)
```

### Iterative

```python
def dfs(start, adj):
    visited = set()
    stack = [start]
    while stack:
        node = stack.pop()
        if node in visited:
            continue
        visited.add(node)
        for nei in adj[node]:
            if nei not in visited:
                stack.append(nei)
```

### DFS returning value (connected components)

```python
def count_components(n, edges):
    adj = defaultdict(list)
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = set()

    def dfs(node):
        visited.add(node)
        for nei in adj[node]:
            if nei not in visited:
                dfs(nei)

    count = 0
    for i in range(n):
        if i not in visited:
            dfs(i)
            count += 1
    return count
```

---

## 28. BFS Graph

```python
from collections import deque

def bfs(start, adj):
    visited = {start}
    q = deque([start])
    dist = {start: 0}
    while q:
        node = q.popleft()
        for nei in adj[node]:
            if nei not in visited:
                visited.add(nei)
                dist[nei] = dist[node] + 1
                q.append(nei)
    return dist
```

---

## 29. Dijkstra

```python
import heapq

def dijkstra(start, n, adj):
    dist = [float('inf')] * n
    dist[start] = 0
    heap = [(0, start)]  # (cost, node)

    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(heap, (dist[v], v))

    return dist
```

---

## 30. Union Find / DSU

```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.rank[px] < self.rank[py]:
            px, py = py, px
        self.parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1
        return True
```

---

## 31. Dynamic Programming

### 1D DP

```python
n = len(nums)
dp = [0] * (n + 1)
dp[0] = 1
for i in range(1, n + 1):
    dp[i] = dp[i - 1] + ...
```

### 2D DP

```python
m, n = len(grid), len(grid[0])
dp = [[0] * n for _ in range(m)]
```

### Common DP patterns

```python
# Knapsack (0/1)
dp = [0] * (capacity + 1)
for weight, value in items:
    for w in range(capacity, weight - 1, -1):  # iterate backwards
        dp[w] = max(dp[w], dp[w - weight] + value)

# Unbounded knapsack
for weight, value in items:
    for w in range(weight, capacity + 1):  # iterate forwards
        dp[w] = max(dp[w], dp[w - weight] + value)
```

---

## 32. Memoization with @cache

```python
from functools import cache

class Solution:
    def solve(self, nums):
        @cache
        def dp(i, remaining):
            if remaining == 0:
                return 1
            if i == len(nums) or remaining < 0:
                return 0
            return dp(i + 1, remaining - nums[i]) + dp(i + 1, remaining)

        return dp(0, target)
```

### Clear cache between test cases

```python
dp.cache_clear()
```

### Manual memoization (dict)

```python
memo = {}

def dp(i, j):
    if (i, j) in memo:
        return memo[(i, j)]
    # compute result
    memo[(i, j)] = result
    return result
```

---

## 33. Prefix Sum

```python
n = len(nums)
prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + nums[i]

# sum of nums[l..r] inclusive
range_sum = prefix[r + 1] - prefix[l]
```

### 2D prefix sum

```python
m, n = len(grid), len(grid[0])
prefix = [[0] * (n + 1) for _ in range(m + 1)]
for r in range(m):
    for c in range(n):
        prefix[r+1][c+1] = (grid[r][c]
                           + prefix[r][c+1]
                           + prefix[r+1][c]
                           - prefix[r][c])

# sum of subgrid [r1..r2][c1..c2]
def query(r1, c1, r2, c2):
    return (prefix[r2+1][c2+1]
          - prefix[r1][c2+1]
          - prefix[r2+1][c1]
          + prefix[r1][c1])
```

---

## 34. Difference Array

```python
n = len(nums)
diff = [0] * (n + 1)

# add val to nums[l..r] inclusive
def range_add(l, r, val):
    diff[l] += val
    diff[r + 1] -= val

# reconstruct
result = []
running = 0
for x in diff[:n]:
    running += x
    result.append(running)
```

---

## 35. Sliding Window

### Fixed size window

```python
k = 3
window_sum = sum(nums[:k])
max_sum = window_sum
for i in range(k, len(nums)):
    window_sum += nums[i] - nums[i - k]
    max_sum = max(max_sum, window_sum)
```

### Variable size window

```python
left = 0
window = defaultdict(int)
for right in range(len(nums)):
    window[nums[right]] += 1
    while not valid(window):
        window[nums[left]] -= 1
        if window[nums[left]] == 0:
            del window[nums[left]]
        left += 1
    # window [left..right] is valid
    ans = max(ans, right - left + 1)
```

---

## 36. Two Pointers

### Opposite ends

```python
left, right = 0, len(nums) - 1
while left < right:
    if nums[left] + nums[right] == target:
        # found
        break
    elif nums[left] + nums[right] < target:
        left += 1
    else:
        right -= 1
```

### Same direction (fast/slow)

```python
slow = 0
for fast in range(len(nums)):
    if condition(nums[fast]):
        nums[slow] = nums[fast]
        slow += 1
```

---

## 37. Monotonic Stack

### Next greater element

```python
result = [-1] * len(nums)
stack = []  # stores indices

for i in range(len(nums)):
    while stack and nums[stack[-1]] < nums[i]:
        j = stack.pop()
        result[j] = nums[i]
    stack.append(i)
```

### Previous less element

```python
result = [-1] * len(nums)
stack = []

for i in range(len(nums)):
    while stack and nums[stack[-1]] >= nums[i]:
        stack.pop()
    result[i] = stack[-1] if stack else -1
    stack.append(i)
```

---

## 38. Binary Search on Answer

```python
def feasible(mid):
    # check if answer = mid is achievable
    ...

lo, hi = 0, max_possible
while lo < hi:
    mid = (lo + hi) // 2
    if feasible(mid):
        hi = mid        # minimize: answer could be mid or smaller
    else:
        lo = mid + 1

return lo
```

For maximization:

```python
while lo < hi:
    mid = (lo + hi + 1) // 2  # avoid infinite loop when hi = lo + 1
    if feasible(mid):
        lo = mid
    else:
        hi = mid - 1
```

---

## 39. Backtracking

```python
def backtrack(path, choices):
    if is_solution(path):
        result.append(path[:])
        return
    for choice in choices:
        if is_valid(choice, path):
            path.append(choice)
            backtrack(path, remaining_choices)
            path.pop()  # undo

result = []
backtrack([], initial_choices)
```

### Permutations example

```python
def permute(nums):
    result = []

    def backtrack(path, remaining):
        if not remaining:
            result.append(path[:])
            return
        for i in range(len(remaining)):
            path.append(remaining[i])
            backtrack(path, remaining[:i] + remaining[i+1:])
            path.pop()

    backtrack([], nums)
    return result
```

---

## 40. Modulo Arithmetic

```python
MOD = 10**9 + 7

# Always apply mod after arithmetic ops
result = (a + b) % MOD
result = (a * b) % MOD
result = (a - b + MOD) % MOD  # subtraction: add MOD first to stay positive

# Modular exponentiation (built-in)
pow(base, exp, MOD)   # fast, O(log exp)

# Modular inverse (only when MOD is prime)
inv = pow(a, MOD - 2, MOD)   # Fermat's little theorem

# Factorials with modular inverse
fact = [1] * (n + 1)
for i in range(1, n + 1):
    fact[i] = fact[i-1] * i % MOD

inv_fact = [1] * (n + 1)
inv_fact[n] = pow(fact[n], MOD - 2, MOD)
for i in range(n - 1, -1, -1):
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD

# nCr mod prime
def comb_mod(n, r):
    if r < 0 or r > n:
        return 0
    return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD
```

---

## 41. GCD and LCM

```python
import math

math.gcd(12, 8)       # 4
math.lcm(4, 6)        # 12  (Python 3.9+)

# Manual LCM
def lcm(a, b):
    return a * b // math.gcd(a, b)

# GCD of a list
from functools import reduce
g = reduce(math.gcd, nums)
```

---

## 42. Intervals

### Sort by start time

```python
intervals.sort(key=lambda x: x[0])
```

### Merge overlapping intervals

```python
def merge(intervals):
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], end)
        else:
            merged.append([start, end])
    return merged
```

---

## 43. SortedList (from sortedcontainers)

Available on LeetCode. Maintains a sorted list with O(log n) insert/delete.

```python
from sortedcontainers import SortedList

sl = SortedList()
sl.add(3)
sl.add(1)
sl.add(2)
sl[0]          # 1 (smallest)
sl[-1]         # 3 (largest)
sl.remove(2)
sl.bisect_left(2)   # insertion point
sl.bisect_right(2)
len(sl)
```

---

## 44. Common Patterns

### Initialize min/max tracker

```python
ans_min = float('inf')
ans_max = float('-inf')
# or
ans_min = 10**18
ans_max = -10**18
```

### Count True in boolean list

```python
count = sum(1 for x in nums if x > 0)
count = sum(x > 0 for x in nums)  # bool is subtype of int
```

### Flatten a list of lists

```python
flat = [x for row in matrix for x in row]
# or
import itertools
flat = list(itertools.chain.from_iterable(matrix))
```

### Transpose a matrix

```python
transposed = list(zip(*matrix))
# or as list of lists
transposed = [list(row) for row in zip(*matrix)]
```

### Rotate matrix 90° clockwise

```python
matrix[:] = [list(row) for row in zip(*matrix[::-1])]
```

### Swap two variables

```python
a, b = b, a
```

### Multiple assignment

```python
x = y = z = 0
```

### Check all / any

```python
all(x > 0 for x in nums)
any(x > 0 for x in nums)
```

---

## 45. Recursion Limit

Python's default recursion limit is 1000. Increase it for deep recursion (DFS on large graphs):

```python
import sys
sys.setrecursionlimit(10**6)
```

Or convert recursive DFS to iterative to avoid stack overflow.

---

## 46. Useful Built-ins

```python
abs(x)
min(a, b)
max(a, b)
min(nums)
max(nums)
sum(nums)
len(x)
sorted(x)
reversed(x)        # returns iterator
list(reversed(x))  # convert to list
range(n)           # 0, 1, ..., n-1
range(a, b)        # a, a+1, ..., b-1
range(a, b, step)
zip(a, b)
enumerate(a)
map(f, a)
filter(f, a)
any(iterable)
all(iterable)
chr(n)
ord(c)
bin(n)
hex(n)
int(s, base)       # int('ff', 16) = 255
```

---

## 47. Unpacking

```python
first, *rest = [1, 2, 3, 4]        # first=1, rest=[2,3,4]
*init, last = [1, 2, 3, 4]         # init=[1,2,3], last=4
first, *mid, last = [1, 2, 3, 4]   # first=1, mid=[2,3], last=4

a, b = [1, 2]          # positional unpack
(x, y), z = (1, 2), 3  # nested unpack
```

---

## 48. Typing Hints (for clarity in LeetCode)

```python
from typing import Optional, List, Tuple, Dict, Set

def solve(nums: List[int]) -> Optional[int]:
    ...

# Python 3.9+ built-in generics (no import needed)
def solve(nums: list[int]) -> int | None:
    ...
```

---

## 49. Common Pitfalls

### Mutable default argument

```python
# WRONG
def f(lst=[]):
    lst.append(1)

# RIGHT
def f(lst=None):
    if lst is None:
        lst = []
```

### Integer division vs float division

```python
5 / 2    # 2.5  (float)
5 // 2   # 2    (floor int)
```

### Copying a list

```python
b = a       # b is an alias, NOT a copy
b = a[:]    # shallow copy
```

### Negative modulo

```python
-7 % 3    # 2 in Python (not -1 like in C++)
```

### Late binding closures in loops

```python
# WRONG — all functions capture same i
fns = [lambda: i for i in range(3)]
fns[0]()  # 2, not 0

# RIGHT — capture i by value
fns = [lambda i=i: i for i in range(3)]
fns[0]()  # 0
```

### sort vs sorted

```python
nums.sort()        # modifies in-place, returns None
new = sorted(nums) # returns new list, original unchanged
```

### list() on range is not free

```python
range(10**8)         # O(1) — just object creation
list(range(10**8))   # O(n) memory — avoid unless needed
```

### Chained comparison (Python-specific, works correctly)

```python
0 <= x < n   # equivalent to 0 <= x and x < n
```

---

## 50. Cheat Sheet

| Task | Python |
|------|--------|
| Array | `list` |
| Dynamic array | `list` with `.append()` |
| Stack | `list` + `.append()` / `.pop()` |
| Queue | `deque` + `.append()` / `.popleft()` |
| Min heap | `heapq` |
| Max heap | `heapq` with `-val` |
| Hash map | `dict` |
| Hash map with default | `defaultdict(int/list/set)` |
| Frequency count | `Counter` |
| Hash set | `set` |
| Sorted set / multiset | `SortedList` |
| Sorted map | not built-in; use `SortedList` of pairs |
| Priority queue | `heapq` |
| Deque | `deque` |
| Binary search | `bisect.bisect_left/right` |
| GCD | `math.gcd` |
| Memoization | `@cache` or `@lru_cache(None)` |
| Permutations | `itertools.permutations` |
| Combinations | `itertools.combinations` |
| Prefix sum | manual list |
| Infinity | `float('inf')` |
| Integer max | `10**18` |

---

## 51. What to Learn First

1. Lists, dicts, sets — know all operations cold
2. `collections`: `defaultdict`, `Counter`, `deque`
3. `heapq` — min-heap and the negate trick
4. `@cache` / `@lru_cache` — memoization for DP
5. `bisect` — binary search on sorted arrays
6. Comprehensions — list, dict, set, generator
7. Two pointers and sliding window
8. DFS/BFS with iterative and recursive forms
9. Union Find
10. `itertools` — permutations, combinations, product
