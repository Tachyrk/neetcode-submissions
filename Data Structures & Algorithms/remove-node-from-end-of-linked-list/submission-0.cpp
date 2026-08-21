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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int total = 0;
        ListNode* current = head;
        while(current){
            total++;
            current = current->next;
        }

        if(n > total) return head;
        int prev_idx = total - n - 1; 
        if(prev_idx < 0) return head->next;
        current = head;
        while(prev_idx--){
            current = current->next;
        }
        current->next = current->next->next;

        return head;
    }
};
