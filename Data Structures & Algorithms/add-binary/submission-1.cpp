class Solution {
public:
    string addBinary(string a, string b) {
        bool carry=0;
        string ans;
        while(a.size()>0||b.size()>0){
            int tot=0;
            if(a.size()>0&&b.size()>0){
                int v1=a.back()-'0';
                int v2=b.back()-'0';
                a.pop_back();
                b.pop_back();
                tot=v1+v2+carry;
                
            }
            else if(a.size()>0){
                tot=a.back()-'0'+carry;
                a.pop_back();
            }
            else{
                tot=b.back()-'0'+carry;
                b.pop_back();
            }
            carry=tot/2;
            tot%=2;
            ans.push_back(tot+'0');
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};