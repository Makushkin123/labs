https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // separate out even and odd levels
        vector<int> res(seq.size(), 0);
        int level = -1;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                level++;
                // separate odd level from even
                if (level % 2) {
                    res[i] = 1;
                }
            } else if (seq[i] == ')') {
                if (level % 2) {
                    res[i] = 1;
                }
                level--;
            } 
        }
        return res;
    }
};
