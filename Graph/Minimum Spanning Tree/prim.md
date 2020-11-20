#Time complexity: O(ElogV)
#Space complexity: O(V+E)

```cpp
// Author: Huahua
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main(int argc, char** argv) {
  const int n = 4;
  vector<vector<int>> edges{{0,1,1},{0,3,3},{0,2,6},{2,3,2},{1,2,4},{1,3,5}};
  vector<vector<pair<int, int>>> g(n);
  for (const auto& e : edges) {
    g[e[0]].emplace_back(e[1], e[2]);
    g[e[1]].emplace_back(e[0], e[2]);
  }
 
  priority_queue<pair<int, int>> q; // (-w, v)
  vector<int> seen(n);
  q.emplace(0, 0); // (-w, v)
 
  int cost = 0;
  for (int i = 0; i < n; ++i) {
    while (true) {
      const int w = -q.top().first;
      const int v = q.top().second;
      q.pop();
      if (seen[v]++) continue;
      cost += w;
      for (const auto& p : g[v]) {
        if (seen[p.first]) continue;
        q.emplace(-p.second, p.first);
      }
      break;
    }
  }
  cout << cost << endl;
  return 0;
}
```

```python
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
	
# Author: Huahua
from collections import defaultdict
from heapq import *
 
n = 4
edges = [[0,1,1],[0,3,3],[0,2,6],[2,3,2],[1,2,4],[1,3,5]]
g = defaultdict(list)
for e in edges:
  g[e[0]].append((e[1], e[2]))
  g[e[1]].append((e[0], e[2]))
 
q = []
cost = 0
seen = set()
heappush(q, (0, 0))
for _ in range(n):
  while True:
    w, u = heappop(q)
    if u in seen: continue  
    cost += w
    seen.add(u)
    for v, w in g[u]:
      if v in seen: continue
      heappush(q, (w, v))
    break
 
print(cost)
```
