class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 第一階段：複製節點並穿插在原節點之後
        // 將 A -> B -> C 變成 A -> A' -> B -> B' -> C -> C'
        Node* current = head;
        while (current) {
            Node* new_node = new Node(current->val);
            new_node->next = current->next;
            current->next = new_node;
            
            // 移動到下一個原節點
            current = new_node->next; 
        }

        // 第二階段：設定新節點的 random 指標
        current = head;
        while (current) {
            if (current->random) {
                // current->next 是新節點 (A')
                // current->random->next 就是新節點 random 該指向的目標 (B')
                current->next->random = current->random->next;
            }
            // 每次跳過新節點，直接往下一個原節點走
            current = current->next->next;
        }

        // 第三階段：分離兩個鏈結串列，並恢復原來的鏈結串列
        current = head;
        Node* new_head = head->next;
        Node* copy_current = new_head;

        while (current) {
            // 恢復原鏈結：A -> B
            current->next = current->next->next;
            
            // 串接新鏈結：A' -> B'
            if (copy_current->next) {
                copy_current->next = copy_current->next->next;
            }
            
            // 雙雙往下移動
            current = current->next;
            copy_current = copy_current->next;
        }

        return new_head;
    }
};