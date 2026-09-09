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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;

        ListNode* prev_block_tail = dummyhead;
        while(true){
            ListNode* kth = prev_block_tail;
            for(int i = 0; i < k && kth != nullptr; i++){
                kth = kth->next;
            }
            if(!kth) break;

            ListNode* prev = kth->next;
            ListNode* current = prev_block_tail->next;
            ListNode* temp;
            for(int i = 0; i < k; i++){
                temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }

            temp = prev_block_tail->next; //new block tail
            prev_block_tail->next = kth;
            prev_block_tail = temp;
        }

        ListNode* new_head = dummyhead->next;
        delete dummyhead;
        return new_head;
    }
};
