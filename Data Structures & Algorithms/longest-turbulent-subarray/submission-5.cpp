class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        vector<int> eid(n,1);
        int id=0;int cur=1;int maxans=0;
        int dir=0;
        while(id+1<n){
            if(dir==0){
                if(arr[id+1]<arr[id]) {dir=-1;cur++;}
                else if(arr[id]<arr[id+1]) {dir=1;cur++;}
                id++;
            }
            else if(dir==1){
                if(arr[id]>arr[id+1]){
                    cur++;id++;dir=-1;
                }
                else{
                    maxans=max(cur,maxans);
                    cur=1;
                    dir=0;
                }
            }
            else if(dir==-1){
                if(arr[id]<arr[id+1]){
                    cur++;id++;dir=1;
                }
                else{
                    maxans=max(cur,maxans);
                    cur=1;
                    dir=0;
                }
            }
        }
        maxans=max(maxans,cur);
        return maxans;
    }
};