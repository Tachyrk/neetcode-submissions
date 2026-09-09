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

        ListNode* node = dummyhead, *prev_block_end = dummyhead,*current, *temp, *prev;
        int count = 0;
        while(node != NULL){
            if(count == k){    
                current = prev_block_end->next;                
                count = 1;            
                node = node->next;
                
                prev = node;
                for(int i = 0; i < k; i++){
                    temp = current->next;
                    current->next = prev;
                    prev = current;
                    current = temp;
                }

                prev_block_end->next = prev;  
                for(int i = 0; i < k; i++){
                    prev_block_end = prev_block_end->next;
                }                          
            }
            if(!node) break;
            count++;
            node = node->next;
        }



        current = dummyhead->next;
        delete dummyhead;
        return current;
    }
};
