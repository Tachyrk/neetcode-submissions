class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // 將 carry 也納入迴圈繼續執行的條件
        while(l1 || l2 || carry){
            int sum = carry;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            if(sum >= 10){
                carry = 1;
                sum -= 10;
            } else {
                carry = 0; // 記得重置 carry
            }
            
            current->next = new ListNode(sum);
            current = current->next;
        }
        
        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};