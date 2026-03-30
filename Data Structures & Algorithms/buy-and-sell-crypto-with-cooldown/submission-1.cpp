class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        else if(n==2) return max(0,prices[1]-prices[0]);
        else if(n==3) return max(max(0,max(prices[2],prices[1])-prices[0]),prices[2]-min(prices[1],prices[0]));
        vector<int> arr(n);
        vector<int> profit(n);
        int arrmin=INT_MAX;
        arr[0]=prices[0];
        arr[1]=prices[1];
        arr[2]=prices[2]-arr[1];
        arrmin=min(arr[0],arr[1]);
        profit[0]=0;
        profit[1]=max(0,prices[1]-prices[0]);
        profit[2]=max(max(0,max(prices[2],prices[1])-prices[0]),prices[2]-min(prices[1],prices[0]));
        for(int i=3;i<n;i++){
            profit[i]=max(prices[i]-arrmin,profit[i-1]);
            arr[i]=prices[i]-profit[i-2];
            arrmin=min(arrmin,arr[i]);
        }
        for(int i=0;i<n;i++){
            cout<<profit[i]<<","<<arr[i]<<" ";
        }
        return profit.back();
    }
};
