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
    struct MyComp{
        bool operator()(const auto &A, const auto &B){
            return A->val > B->val;
        };
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        priority_queue<ListNode *, vector<ListNode *>, MyComp> q;
        for(auto head : lists){
            if(head){
                q.push(head);
            }            
        }

        while(!q.empty()){
            ListNode * node = q.top();
            q.pop();
            if(node->next) q.push(node->next);

            current->next = node;
            current = current->next;
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
