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
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL, *current = slow->next, *next;
        slow->next = NULL;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        ListNode* head1 = head->next, *head2 = prev ;
        current = head;
        while(head1 || head2){
            if(head2){
                current->next = head2;
                head2 = head2->next;
                current = current->next;
            }
            if(head1){
                current->next = head1;
                head1 = head1->next;
                current = current->next;
            }            
        }
        current->next = NULL;
    }
};
