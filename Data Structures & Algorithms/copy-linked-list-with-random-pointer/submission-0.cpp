/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* new_head = (Node*) new Node(head->val);
        Node* current = head;
        unordered_map<Node*, Node*> mp;

        mp[head] = new_head;
        while(current){
            Node* mirror_node = mp[current];
            if(current->next){
               if(mp.find(current->next) == mp.end()){
                    Node* new_next = (Node*) new Node(current->next->val);
                    mp[current->next] = new_next;
               }
               mirror_node->next = mp[current->next];
            }
            if(current->random){
               if(mp.find(current->random) == mp.end()){
                    Node* new_random = (Node*) new Node(current->random->val);
                    mp[current->random] = new_random;
               }
               mirror_node->random = mp[current->random];
            }
            current = current->next;
        }

        return new_head;
    }
};
