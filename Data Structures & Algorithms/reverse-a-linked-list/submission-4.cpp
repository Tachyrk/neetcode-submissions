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
        ListNode* newHead = NULL;
        auto dfs = [&](auto self, ListNode* current, ListNode* prev) -> void{
            if(current == NULL) return;
            if(current->next == NULL){
                newHead = current;
            }else{
                self(self, current->next, current);  
            }
            current->next = prev;
        };

        dfs(dfs, head, NULL);

        return newHead;
    }
};
