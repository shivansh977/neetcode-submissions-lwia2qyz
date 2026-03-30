class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        int cnt20=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                cnt5++;
            }
            if(bills[i]==10){
                if(cnt5==0){
                    return false;
                }
                else{
                    cnt5--;
                    cnt10++;
                }
            }
            if(bills[i]==20){
                if((cnt5>=3)||(cnt10>0&&cnt5>0)){
                    cnt20++;
                    if(cnt10>0&&cnt5>0){
                        cnt10--;cnt5--;
                    }
                    else{
                        cnt5-=3;
                    }
                }
                else return false;
            }
        }
        return true;
    }
};