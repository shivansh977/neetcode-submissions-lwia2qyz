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
private:
    Node* constr(vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
        if(x1>x2||y1>y2){
            return NULL;
        }
        int val=grid[x1][y1];
        bool isLeaf=true;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                if(val!=grid[i][j]){
                    isLeaf=false;
                    break;
                }
            }
        }
        if(isLeaf){
            Node* n=new Node(val, true);
            return n;
        }
        int midx=(x1+x2)/2;
        int midy=(y1+y2)/2;
        Node* tl=constr(grid,x1,y1,midx,midy);
        Node* tr=constr(grid,x1,midy+1,midx,y2);
        Node* bl=constr(grid,midx+1,y1,x2,midy);
        Node* br=constr(grid,midx+1,midy+1,x2,y2);
        Node* n=new Node(0,0,tl,tr,bl,br);
        return n;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return constr(grid,0,0,n-1,n-1);
    }
};