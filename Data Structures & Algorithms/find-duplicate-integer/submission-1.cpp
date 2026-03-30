class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int id=nums[0];
        int id1=nums[id];
        while(id!=id1){
            id=nums[id];
            id1=nums[nums[id1]];
        }
        id1=id;
        id=0;
        while(id!=id1){
            id=nums[id];
            id1=nums[id1];
        }
        return id;
    }
};
