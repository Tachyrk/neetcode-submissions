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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prevblock = dummy;
        for(int i = left - 1; i > 0 && prevblock; i--){
            prevblock = prevblock->next;
        }       

        ListNode* nextblock = prevblock;
        for(int i = right; i >= left - 1 && nextblock; i--){
            nextblock = nextblock->next;
        }       

        ListNode* current = prevblock->next;
        ListNode* prev = nextblock;
        while(current != nextblock){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        prevblock->next = prev;
        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};