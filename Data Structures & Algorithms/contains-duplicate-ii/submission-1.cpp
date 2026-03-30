class Solution {
private:
    bool good(map<int,int>& cnt){
        for(const auto& i:cnt){
            if(i.second>1) return true;
        }
        return false;
    }
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int reqlen=k+1;
        int n=nums.size();
        reqlen=min(reqlen,n);
        map<int,int> cnt;
        for(int i=0;i<reqlen;i++){
            cnt[nums[i]]++;
        }
        if(good(cnt)) return true;
        for(int st=1;st+k<n;st++){
            cnt[nums[st-1]]--;
            cnt[nums[st+k]]++;
            if(good(cnt)) return true;
        }
        return false;
    }
};