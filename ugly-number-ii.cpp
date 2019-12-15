//https://leetcode.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long int, vector<long int>, greater<long int> > q;
        q.push(1);
        unordered_set<long int> walked;
        walked.insert(1);
        for(int i=0; i<n-1; i++){
            long int tmp=q.top();
            q.pop();
            if(tmp>=INT_MAX/2)continue;
            if(walked.find(tmp*2)==walked.end()){
                q.push(tmp*2);
                walked.insert(tmp*2);
            }
            if(walked.find(tmp*3)==walked.end()){
                q.push(tmp*3);
                walked.insert(tmp*3);
            }
            if(walked.find(tmp*5)==walked.end()){
                q.push(tmp*5);
                walked.insert(tmp*5);
            }
        }
        return q.top();
        
    }
};
