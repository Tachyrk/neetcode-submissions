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
            bool has_same_val = true;
            for(int i = starti; i < starti + width; i++){
                for(int j = startj; j < startj + width; j++){
                    if(grid[i][j] != grid[starti][startj]){
                        has_same_val = false;
                        break;
                    }
                }
            }

            Node* node = new Node(grid[starti][startj], false);
            if(has_same_val){
                node->isLeaf = true;
            }else{               
                node->topLeft = self(self, starti, startj, width / 2);
                node->topRight = self(self, starti, startj + width / 2, width / 2);
                node->bottomLeft = self(self, starti + width / 2, startj, width / 2);
                node->bottomRight = self(self, starti + width / 2, startj + width / 2, width / 2);
            }

            return node;
        };

        return createQuadTree(createQuadTree, 0, 0, n);
    }
};