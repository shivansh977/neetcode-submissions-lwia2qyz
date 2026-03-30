class Solution {
private:
    int calc(vector<int>& height, bool greaterThanEqual){
        int last_height=0;
        int ans=0;
        int tmpsum=0;
        for(int i=0;i<height.size();i++){
            if(greaterThanEqual){
                if(height[i]>=last_height) {last_height=height[i];ans+=tmpsum;tmpsum=0;}
                else tmpsum+=(last_height-height[i]);
            }
            else{
                if(height[i]>last_height) {last_height=height[i];ans+=tmpsum;tmpsum=0;}
                else tmpsum+=(last_height-height[i]);
            }
        }
        return ans;
    }
public:
    int trap(vector<int>& height) {
        int ans=calc(height,true);
        reverse(height.begin(),height.end());
        ans+=calc(height,false);
        return ans;
    }
};
