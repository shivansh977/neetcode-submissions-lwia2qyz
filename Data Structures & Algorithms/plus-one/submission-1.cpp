class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int id=digits.size()-1;
        while(id>=0&&digits[id]==9){
            id--;
        }
        cout<<id<<"\n";
        if(id<0){
            vector<int> ans={1};
            for(int i=0;i<digits.size();i++) ans.push_back(0);
            return ans;
        }
        digits[id]++;
        for(int i=id+1;i<digits.size();i++) digits[i]=0;
        return digits;
    }
};
