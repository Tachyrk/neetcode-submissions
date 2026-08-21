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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int reminder = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(l1 || l2){
            int sum = reminder;
            reminder = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            if(sum >= 10){
                reminder = 1;
                sum -= 10;
            }
            ListNode* new_node = new ListNode(sum);
            current->next = new_node;
            current = current->next;
        }
        if(reminder){
            ListNode* new_node = new ListNode(reminder);
            current->next = new_node;            
        }
        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
