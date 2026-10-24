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
            
            int half = width / 2;
            Node* tl = self(self, starti, startj, half);
            Node* tr = self(self, starti, startj + half, half);
            Node* bl = self(self, starti + half, startj, half);
            Node* br = self(self, starti + half, startj + half, half);
            if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && (tl->val == tr->val && tl->val == bl->val && bl->val == br->val)){
                delete tl;
                delete tr;
                delete bl;
                delete br;
                return new Node(grid[starti][startj], true);                
            }
            Node* node = new Node(grid[starti][startj], false, tl, tr, bl, br);            
            return node;
        };

        return createQuadTree(createQuadTree, 0, 0, n);
    }
};