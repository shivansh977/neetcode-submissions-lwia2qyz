class Solution {
private:
    string intToBin(int n){
        string ans="";
        for(int i=0;i<31;i++){
            ans.push_back('0');
        }
        int id=30;
        while(n>0){
            ans[id--]=char('0'+(n%2));
            n/=2;
        }
        return ans;
    }
    int binToInt(string s){
        int x=1;
        int ans=0;
        for(int i=30;i>=0;i--){
            if(s[i]=='1') ans+=x;
            x*=2;
        }
        return ans;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        string x1=intToBin(left);
        string x2=intToBin(right);
        string tmp=intToBin(0);
        for(int i=0;i<31;i++){
            if(x1[i]!=x2[i]){
                break;
            }
            tmp[i]=x1[i];
        }
        return binToInt(tmp);
    }
};