class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int id=-1;
        if(target>=matrix.back()[0]){
            return binary_search(matrix.back().begin(),matrix.back().end(),target);
        }
        else{
            int st=0,en=matrix.size()-1;
            while(st<en){
                int mid=st+(en-st)/2;
                if(matrix[mid][0]<=target){
                    st=mid+1;
                }
                else en=mid;
            }
            if(st==0) return false;
            return binary_search(matrix[st-1].begin(),matrix[st-1].end(),target);
        }
        return false;
    }
};

//find upper bound
