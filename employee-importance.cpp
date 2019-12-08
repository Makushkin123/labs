https://leetcode.com/problems/employee-importance/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // 36ms, faster than 35.99%
        /*
        int res = 0, num = 0;
        while(num < employees.size() && employees[num]->id != id) num++;
        if(num == employees.size()) return 0;
        res += employees[num]->importance;
        
        if(employees[num]->subordinates.size()) {
            for(int i = 0; i < employees[num]->subordinates.size(); i++) res += getImportance(employees, employees[num]->subordinates[i]);
        }
        return res;
        */
        
        // 32ms, faster than 69.90%
        /*
        int res = 0;
        queue<int> q;
        q.push(id);
        
        while(!q.empty()) {
            int num = 0;
            while(num < employees.size() && employees[num]->id != q.front()) num++;
            res += employees[num]->importance;
            for(int i = 0; i < employees[num]->subordinates.size(); i++) q.push(employees[num]->subordinates[i]);
            q.pop();
        }
        return res;
       
        int res = 0;
        queue<int> q;
        q.push(id);
        unordered_map<int, int> score;
        for(int i = 0; i < employees.size(); i++) score.insert(pair<int, int>(employees[i]->id, employees[i]->importance));
        
        while(!q.empty()) {
            int num = 0;
            while(num < employees.size() && employees[num]->id != q.front()) num++;
            res += score[employees[num]->id];
            for(int i = 0; i < employees[num]->subordinates.size(); i++) q.push(employees[num]->subordinates[i]);
            q.pop();
        }
        return res;
        
    }
};
