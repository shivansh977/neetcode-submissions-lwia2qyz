class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int dist=0;
        int minval;
        int ids=0;
        for(int i=0;i<k;i++){
            dist+=abs(arr[i]-x);
        }
        minval=dist;
        vector<int> fa;
        for(int st=1;st<=n-k;st++){
            dist+=abs(arr[st+k-1]-x);
            dist-=abs(arr[st-1]-x);
            if(dist<minval){
                minval=dist;
                ids=st;
            }
        }
        for(int i=ids;i<ids+k;i++){
            fa.push_back(arr[i]);
        }
        return fa;
    }
};