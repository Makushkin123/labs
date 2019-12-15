//https://leetcode.com/problems/last-stone-weight/
class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        
        
        sort(stones.begin(), stones.end());
        while (stones.size() > 1) {
		
            if (stones[stones.size() - 1] > stones[stones.size() - 2]) {
                
                stones[stones.size() - 2] = abs(stones[stones.size() - 2] - stones[stones.size() - 1]);
                
                stones.pop_back();
                
                
            } else
            {
				stones.erase(stones.end() - 2, stones.end());
            }
            if (!stones.empty()) sort(stones.begin(), stones.end());
        }
		
        
        
        return !stones.empty() ? stones[0] : 0;
    }
};
