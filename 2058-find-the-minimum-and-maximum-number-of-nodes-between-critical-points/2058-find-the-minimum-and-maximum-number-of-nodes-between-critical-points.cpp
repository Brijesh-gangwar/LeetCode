/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical_idx;
        ListNode* cur = head;
        ListNode* prev = nullptr;       
        int index = 0;
    
        while(cur){
            ListNode* next = cur->next;
            if(prev != nullptr && next != nullptr){
                if(prev->val < cur->val && cur->val > next->val || prev->val > cur->val && cur->val < next->val){
                    critical_idx.push_back(index);
                }
            }
            prev = cur;
            cur = cur->next;

            index++;
        }

        int n = critical_idx.size();
        if(n < 2) return {-1 , -1 };

        int minval = INT_MAX;
        for(int i = 0; i < n-1 ; i++){
            minval = min(minval , critical_idx[i+1] -  critical_idx[i]);
        }
        int maxval = critical_idx[n-1] - critical_idx[0];;
        return {minval , maxval};
    }
};