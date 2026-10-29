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
    int GCD(int a, int b){
        return b == 0 ? a : GCD(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        ListNode* adjacent  = head->next;
        while(adjacent != nullptr){
            int val = GCD(current->val, adjacent->val);            
            current->next = new ListNode(val, adjacent);
            current = adjacent;
            adjacent = adjacent->next;
        }   
        return head;
    }
};