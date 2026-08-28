/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;        

        Node* CopyedNode = new Node(node->val);
        mp[node] = CopyedNode;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* current = q.front();
            Node* Copyed_current = mp[current];
            q.pop();           
            for(Node* neibor : current->neighbors){
                if(mp.find(neibor) == mp.end()){
                    Node* temp = new Node(neibor->val);
                    mp[neibor] = temp;      
                    q.push(neibor);      
                }
                Copyed_current->neighbors.push_back(mp[neibor]);            

            }
        }

        return CopyedNode;
    }
};
