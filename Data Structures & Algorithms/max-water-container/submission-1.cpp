class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=int(heights.size())-1;
        int maxans=0;
        while(i<j){
            maxans=max((j-i)*min(heights[i],heights[j]),maxans);
            if(heights[i]>=heights[j]){
                j--;
            }
            else i++;
        }
        return maxans;
    }
};
