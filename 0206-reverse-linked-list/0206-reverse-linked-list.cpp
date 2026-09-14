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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;

        ListNode* prev = nullptr;

        while(cur){
            ListNode* next = cur->next; // next node
            cur->next = prev; // assign prev node to cur

            prev = cur; // update prev to cur for next iteration
            cur = next; // cur = cur->next
        }

        return prev;
    }
};