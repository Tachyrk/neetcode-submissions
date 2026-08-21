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
        int length = 0;
        vector<ListNode*> temp;

        ListNode* current = head;
        while(current){
            temp.push_back(current);
            length++;
            current = current->next;
        }

        int left = 1, right = length - 1;
        current = head;
        while(left <= right){           
            current->next = temp[right--];
            current = current->next;            
            if(left > right){               
                break;
            }            
            current->next = temp[left++];
            current = current->next;            
        }        
        current->next = NULL;
    }
};
