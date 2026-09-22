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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* ans = nullptr;

        while (list1 && list2) {
            ListNode* newnode = nullptr;

            if (list1->val < list2->val) {
                newnode = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                newnode = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (ans == nullptr) {
                ans = newnode;
                head = newnode;
            } else {
                head->next = newnode;
            }
            if (head->next != nullptr)
                head = head->next;
        }

 if (head == nullptr)
            return list1 ? list1 : list2;

        if (list1 == nullptr)
            head->next = list2;
        else
            head->next = list1;
        return ans;
    }
};