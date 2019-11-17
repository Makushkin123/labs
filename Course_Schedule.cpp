//https://leetcode.com/problems/course-schedule/

class Solution {
public:

  bool canFinish(int n, vector<vector<int>>& p) {
    vector<int> G[n];
    memset(G, 0, sizeof(G));
    
    int in_deg[n];
    memset(in_deg, 0, sizeof(in_deg));
    for(int i = 0; i < p.size(); i++) {
        int t = p[i][0];
        int s = p[i][1];
        in_deg[t]++;
        G[s].push_back(t);
    }

    queue<int> Q;
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++)
      if(in_deg[i] == 0) {
        Q.push(i);
        visited[i] = true;
      }
    
    int cnt = 0;
    // vector<int> topo_order;
    
    while(!Q.empty()) {
      int v = Q.front();
      Q.pop();
      // topo_order.push_back(v);
      for(int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if(!visited[u] && --in_deg[u] == 0) {
          Q.push(u);
          visited[u] = true;
        }       
      }
      cnt++;
    }
    
    if(cnt < n) return false; 
    return true;
  }
};
