Time complexity: O(ElogV)

Space complexity: O(V+E)

```cpp
// Author: Huahua
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;
 
int main(int argc, char** argv) {
  const int n = 4;
  vector<vector<int>> edges{{0,1,1},{0,3,3},{0,2,6},{2,3,2},{1,2,4},{1,3,5}};    
  vector<vector<int>> q; // (w, u, v)  
  for (const auto& e : edges)    
    q.push_back({e[2], e[0], e[1]});
  sort(begin(q), end(q));
 
  vector<int> p(n);
  iota(begin(p), end(p), 0);
 
  function<int(int)> find = [&](int x) {
    return x == p[x] ? x : p[x] = find(p[p[x]]);
  };
 
  int cost = 0;
  for (const auto& t : q) {    
    int w = t[0], u = t[1], v = t[2];      
    int ru = find(u), rv = find(v);      
    if (ru == rv) continue;
    p[ru] = rv; // merge (u, v)      
    cost += w;
  }  
  cout << cost << endl;
 
  return 0;
}
```

```python
from collections import defaultdict
from heapq import *
 
n = 4
edges = [[0,1,1],[0,3,3],[0,2,6],[2,3,2],[1,2,4],[1,3,5]]
p = list(range(n))
 
 
def find(x):
  if x != p[x]: p[x] = find(p[p[x]])
  return p[x]
 
cost = 0
for u, v, w in sorted(edges, key=lambda x: x[2]):
  ru, rv = find(u), find(v)
  if ru == rv: continue
  p[ru] = rv
  cost += w
 
print(cost)
```
