//https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        vector<pair<int, int>> degrees(N+1);
        
        for(const auto pair : trust)
        {
            degrees[pair[0]].second++;
            degrees[pair[1]].first++;
        }
        
        for(int i=1; i<N+1; i++)
        {
            if(degrees[i].first == N-1 && degrees[i].second == 0)
            {
                return i;                                
            }
        }
        
        return -1;        
    }
    
};
