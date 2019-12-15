//https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> elemFrequency;
        for (const auto& elem : nums) {
            ++elemFrequency[elem];
        }
        
        map<int, unordered_set<int>> frequencyToElemBST;
        for (const auto& kv : elemFrequency) {
            frequencyToElemBST[kv.second].insert(kv.first);
        }
        
        auto iter = frequencyToElemBST.rbegin();
        int i = 0;
        vector<int> result;
        
        while (i < k && iter != frequencyToElemBST.rend()) {
            auto freqElems = iter->second;
            for (auto elemIter = freqElems.begin(); elemIter != freqElems.end() && i < k; ++i, ++elemIter) {
                result.push_back(*elemIter);
            }
            ++iter;
        }
        
        return result;
    }
};
