//https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> mm;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // city to cost
        queue<pair<int, int>> qu;

        for(auto it : flights) {
            mm[it[0]].push_back({it[1], it[2]});
        }

        qu.push({src, 0});

        int count = 0;
        int res = INT_MAX;
        while(!qu.empty()) {
            if(count++ > K+1) break;
            int size = qu.size();
            for(int i = 0; i < size; i++) {
                pair<int, int> temp = qu.front();
                qu.pop();
                int city = temp.first;
                int cost = temp.second;

                if(city == dst) {
                    res = min(res, cost);
                    continue;
                }

                for(auto it : mm[city]) {
                    it.second += cost;
                    if(dist[it.first] < it.second) continue;
                    dist[it.first] = it.second;
                    qu.push({it.first, it.second});
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
