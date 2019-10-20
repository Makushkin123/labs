https://leetcode.com/problems/split-linked-list-in-parts/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   vector<ListNode*> splitListToParts(ListNode* h, int k) {
       
       
	vector<ListNode*> res(k, NULL);
       
       
	vector<int> s(k, 0);
       
       
	int len = 0;
       
	
	for(ListNode* itr = h; itr; itr = itr->next, len++) {
        
        
        
        
        s[(len % k)]++;
    }

    ListNode* itr = h;
   
    for(int i=0; i<k; i++) {
        
        
        
        if (s[i]) {
            
            
            
            res[i] = itr;
            
            while(--s[i]) {
                
                
                
                itr = itr->next;
            }
           
            ListNode* tail = itr;
            
            itr = itr->next
                
                
                
            tail->next = NULL;
            
            
            
        }
        else {            

            break;
        }
    }
    return res;
}
};
