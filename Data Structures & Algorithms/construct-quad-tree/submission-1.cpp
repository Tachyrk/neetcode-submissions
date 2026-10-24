/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();        

        auto createQuadTree = [&](auto &self, int starti, int startj, int width)-> Node*{    
            if(width == 1) return new Node(grid[starti][startj], true);
            Node* node = new Node(grid[starti][startj], false);
            int half = width / 2;
            node->topLeft = self(self, starti, startj, half);
            node->topRight = self(self, starti, startj + half, half);
            node->bottomLeft = self(self, starti + half, startj, half);
            node->bottomRight = self(self, starti + half, startj + half, half);
            if(node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf && (node->topLeft->val == node->topRight->val && node->topLeft->val == node->bottomLeft->val && node->bottomLeft->val == node->bottomRight->val)){
                delete node->topLeft;
                delete node->topRight;
                delete node->bottomLeft;
                delete node->bottomRight;
                node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = nullptr;
                node->isLeaf = true;
            }
            
            return node;
        };

        return createQuadTree(createQuadTree, 0, 0, n);
    }
};